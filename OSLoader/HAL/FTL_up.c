#include "FTL_up.h"
#include "mtd_up.h"
#include "../debug.h"

static mtdInfo_t *pMtdinfo;


#define BAD_BLOCK           0x1E1EE1E1
#define GOOD_BLOCK          0xFFFFFFFF

#define DATA_START_BLOCK    80

#define GC_RATIO        4

static uint8_t PageBuffer[ 2048 ] __attribute__((aligned(4)));

static struct dhara_nand nandDevice;
static struct dhara_map FTLmap;

PartitionInfo_t *PartitionInfo;

static int _pow(int x, int y) //x^y
{
    int res = x;
    for(int i = 1; i < y; i++)
    {
        res = res * x;
    }
    return res;
}

static int _log2(int x) // log2(x)
{
	int res = 0;
    int r = x;
	while(r > 1){
		r = r / 2;
		++res;
	}
	return res;
}

uint32_t meta;
int dhara_nand_is_bad(const struct dhara_nand *n, dhara_block_t b)
{
    uint32_t ret;
    ret = MTD_ReadPhyPageMeta((DATA_START_BLOCK + b) * pMtdinfo->PagesPerBlock, 4, (uint8_t *)&meta);
    //printf("TEST BAD\n");
    if((ret == -1) || (meta == BAD_BLOCK)){
        
        printf("Found BAD\n");
        return 1;
    }
    return 0;
}

void dhara_nand_mark_bad(const struct dhara_nand *n, dhara_block_t b)
{
    meta = BAD_BLOCK;
    printf("MARK BAD\n");
    uint8_t* tempbuf = pvPortMalloc(2048);
    uint8_t* tempmeta = pvPortMalloc(19);
    MTD_ReadPhyPage((DATA_START_BLOCK + b) *  pMtdinfo->PagesPerBlock, 0, 2048, tempbuf);
    memset(tempmeta, 0, 19);
    *((uint32_t *)&tempmeta[0]) = BAD_BLOCK;
    MTD_WritePhyPageWithMeta((DATA_START_BLOCK + b), 4, tempbuf, tempmeta);
    //MTD_WritePhyPageMeta((DATA_START_BLOCK + b) * _pow(2, n->log2_ppb), 4, (uint8_t *)&meta);
    vPortFree(tempbuf);
    vPortFree(tempmeta);
   
}

int dhara_nand_erase(const struct dhara_nand *n, dhara_block_t b,
		     dhara_error_t *err
)
{
    int ret;
    ret = MTD_ErasePhyBlock(DATA_START_BLOCK + b);
    //printf("ERASE ret %d, block:%d\n",ret,b);
    if(ret){
        *err = DHARA_E_BAD_BLOCK;
        printf("ERASE ERR\n");
    }
    return ret;
}

int dhara_nand_prog(const struct dhara_nand *n, dhara_page_t p,
		    const uint8_t *data,
		    dhara_error_t *err)
{
    int ret;
    //printf("PROG page:%d, data:%p\n",p, data);
    ret = MTD_WritePhyPage(p + (DATA_START_BLOCK *  pMtdinfo->PagesPerBlock) , (uint8_t *)data);

    //printf("ret %d.PROG page:%d, data:%p\n",ret, p, data);

    if(ret){
        *err = DHARA_E_BAD_BLOCK;
        printf("PROG ERR\n");
    }
    return ret;
}

int dhara_nand_is_free(const struct dhara_nand *n, dhara_page_t p)
{
    int ret;
    ret = MTD_ReadPhyPage(p + (DATA_START_BLOCK *  pMtdinfo->PagesPerBlock), 0, _pow(2, n->log2_page_size), NULL);
    //printf("is_free %d\n",ret);
    return ret;
}

int dhara_nand_read(const struct dhara_nand *n, dhara_page_t p,
		    size_t offset, size_t length,
		    uint8_t *data,
		    dhara_error_t *err)
{
    int ret;
    //printf("start READ page:%d, offset:%d, len:%d, buff:%p\n", p,offset,length,data);
    ret = MTD_ReadPhyPage(p + (DATA_START_BLOCK *  pMtdinfo->PagesPerBlock), offset, length, data);

    //printf("READ END\n");
    /*
    for(int i=0;i<64; i++){
        printf("%02X ", data[i]);
    }
    printf("\n");*/

    if(ret < 0){
        *err = DHARA_E_ECC;
        printf("READ ERR\n");
        return ret;
    }
    return 0;
}            

int dhara_nand_copy(const struct dhara_nand *n,
		    dhara_page_t src, dhara_page_t dst,
		    dhara_error_t *err)
{
    int ret;
    //printf("COPY SRC %d dst %d\n",src,dst);
    ret = MTD_CopyPhyPage(src + (DATA_START_BLOCK *  pMtdinfo->PagesPerBlock), 
                          dst + (DATA_START_BLOCK *  pMtdinfo->PagesPerBlock));
    if(ret){
        *err = DHARA_E_ECC;
        printf("COPY ERR\n");
    }
    return ret;
}

//===================================================================================


static QueueHandle_t FTL_Operates_Queue;
static EventGroupHandle_t FTLLockEventGroup;

static int32_t FTLStatusBuf[32];
static int32_t pFTLStatus = 0;

static int32_t FTLLockBit = 0;

static bool inited = false;

static FTL_Operates curOpa;

bool FTL_inited()
{
    return inited;
}

char *testdat ;

void FTL_ClearAllSector()
{
    dhara_map_clear(&FTLmap);
}

void FTL_MapInit()
{
    dhara_error_t err;
    int ret;
    dhara_map_init(&FTLmap, &nandDevice, PageBuffer ,GC_RATIO);
    err = 0;
    ret = dhara_map_resume(&FTLmap, &err);
    INFO("Resume FTL: %d,%s\n",ret,dhara_strerror(err));
    INFO("FTL capacity %d/%d (%d K/ %d K)\n" ,dhara_map_size(&FTLmap),dhara_map_capacity(&FTLmap)
                                             ,dhara_map_size(&FTLmap) * pMtdinfo->PageSize_B / 1024
                                             ,dhara_map_capacity(&FTLmap) * pMtdinfo->PageSize_B / 1024 );
}

int FTL_init()
{
    dhara_error_t err;
    int ret;

    FTL_Operates_Queue = xQueueCreate(32, sizeof(FTL_Operates));
    FTLLockEventGroup = xEventGroupCreate();

    while(!MTD_isDeviceInited())
    {
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    pMtdinfo = MTD_getDeviceInfo();
    
    nandDevice.num_blocks = pMtdinfo->Blocks - DATA_START_BLOCK;
    nandDevice.log2_page_size = _log2(pMtdinfo->PageSize_B);
    nandDevice.log2_ppb = _log2(pMtdinfo->PagesPerBlock);
    
    INFO("FTL num_blocks:%d\n",nandDevice.num_blocks);
    INFO("FTL log2_page_size:%d\n",nandDevice.log2_page_size);
    INFO("FTL log2_ppb:%d\n",nandDevice.log2_ppb);


    FTL_MapInit();
         

    //err = 0;
    //ret = dhara_map_sync(&FTLmap, &err);
    //INFO("Sync FTL: %d,%s\n",ret,dhara_strerror(err));



    FTLLockBit = 0;
    for(int i=0; i<(sizeof(FTLStatusBuf) / sizeof(int32_t)); i++){
        FTLStatusBuf[i] = -5;
    }
    pFTLStatus = 0;



    inited = true;

    return ret;

}

void FTL_task()
{
    dhara_error_t err;
    int ret;
    while(1){
        if(xQueueReceive(FTL_Operates_Queue, &curOpa, portMAX_DELAY) == pdTRUE)
        {
            switch (curOpa.opa)
            {
            case FTL_SECTOR_READ:
                for(int i = 0; i < curOpa.num; i++){
                    ret = dhara_map_read(&FTLmap, curOpa.sector++, curOpa.buf, &err);
                    curOpa.buf += pMtdinfo->PageSize_B;
                    if(ret){
                        FTL_WARN("FTL READ FAIL:%d,%s\n",ret,dhara_strerror(err));
                        break;
                    }
                }
                *curOpa.StatusBuf = ret;
                break;

            case FTL_SECTOR_WRITE:
                for(int i = 0; i < curOpa.num; i++){
                    ret = dhara_map_write(&FTLmap, curOpa.sector++, curOpa.buf, &err);
                    curOpa.buf += pMtdinfo->PageSize_B;
                    if(ret){
                        FTL_WARN("FTL WRITE FAIL:%d,%s\n",ret,dhara_strerror(err));
                        break;
                    }
                }
                *curOpa.StatusBuf = ret;
                break;
            
            case FTL_SECTOR_TRIM:
                ret = dhara_map_trim(&FTLmap, curOpa.sector, &err);
                *curOpa.StatusBuf = ret;
                break;

            case FTL_SYNC:
                ret = dhara_map_sync(&FTLmap, &err);
                if(ret){
                    FTL_WARN("FTL SYNC FAIL:%d,%s\n",ret,dhara_strerror(err));
                }
                *curOpa.StatusBuf = ret;
                break;

            default:
                break;
            }

            xEventGroupSetBits(FTLLockEventGroup , (1 << curOpa.BLock));

        }
    }


}


static EventBits_t FTL_getLock()
{
    uint32_t bit;
    EventBits_t GroupBits;
    EventBits_t curBits;

    taskENTER_CRITICAL();
    
    GroupBits = xEventGroupGetBits(FTLLockEventGroup);

    curBits = (GroupBits >> FTLLockBit) & 1;
    while(curBits == 1)
    {
        GroupBits = xEventGroupGetBits(FTLLockEventGroup);
        FTLLockBit++;
        if(FTLLockBit > 23)
        {
            FTLLockBit = 0;
        }
        curBits = (GroupBits >> FTLLockBit) & 1;
    }

    bit = FTLLockBit;
    xEventGroupClearBits(FTLLockEventGroup, 1 << bit);

    FTLLockBit++;
    if(FTLLockBit > 23)
    {
        FTLLockBit = 0;
    }
    
    taskEXIT_CRITICAL();
    return bit;

}

static uint32_t *FTL_GetStatusBuf()
{
    int32_t *StatusBuf;
    taskENTER_CRITICAL();

    StatusBuf = &FTLStatusBuf[pFTLStatus];
    while(*StatusBuf != -5){
        pFTLStatus++;
        if(pFTLStatus >= (sizeof(FTLStatusBuf)/sizeof(int32_t))){
            pFTLStatus = 0;
        }
        StatusBuf = &FTLStatusBuf[pFTLStatus];
    }

    *StatusBuf = 0;

    pFTLStatus++;
    if(pFTLStatus >= (sizeof(FTLStatusBuf)/sizeof(int32_t))){
        pFTLStatus = 0;
    }
    //FTL_INFO("pFTLStatus:%d\n",pFTLStatus);
    taskEXIT_CRITICAL();
    return StatusBuf;
}

int FTL_GetSectorCount()
{
    return dhara_map_capacity(&FTLmap);
}

int FTL_GetSectorSize()
{
    return pMtdinfo->PageSize_B;
}



int FTL_ReadSector(uint32_t sector, uint32_t num, uint8_t *buf)
{

    FTL_Operates newOpa;
    int retVal;
    if(!FTL_inited){
        return -1;
    }

    newOpa.opa = FTL_SECTOR_READ;
    newOpa.sector = sector;
    newOpa.num = num;
    newOpa.buf = buf;
    newOpa.BLock = FTL_getLock();
    newOpa.StatusBuf = FTL_GetStatusBuf();

    xQueueSend(FTL_Operates_Queue, &newOpa, portMAX_DELAY);

    xEventGroupWaitBits(FTLLockEventGroup, (1 << newOpa.BLock), pdTRUE, pdFALSE, portMAX_DELAY);

    retVal = *newOpa.StatusBuf;
    *newOpa.StatusBuf = -5;
    return retVal;

}

int FTL_WriteSector(uint32_t sector, uint32_t num, uint8_t *buf)
{
    FTL_Operates newOpa;
    int retVal;
    if(!FTL_inited){
        return -1;
    }

    newOpa.opa = FTL_SECTOR_WRITE;
    newOpa.sector = sector;
    newOpa.num = num;
    newOpa.buf = buf;
    newOpa.BLock = FTL_getLock();
    newOpa.StatusBuf = FTL_GetStatusBuf();

    xQueueSend(FTL_Operates_Queue, &newOpa, portMAX_DELAY);

    xEventGroupWaitBits(FTLLockEventGroup, (1 << newOpa.BLock), pdTRUE, pdFALSE, portMAX_DELAY);

    retVal = *newOpa.StatusBuf;
    *newOpa.StatusBuf = -5;
    return retVal;
}

int FTL_TrimSector(uint32_t sector)
{
    FTL_Operates newOpa;
    int retVal;
    if(!FTL_inited){
        return -1;
    }

    newOpa.opa = FTL_SECTOR_TRIM;
    newOpa.sector = sector;
    
    newOpa.BLock = FTL_getLock();
    newOpa.StatusBuf = FTL_GetStatusBuf();

    xQueueSend(FTL_Operates_Queue, &newOpa, portMAX_DELAY);

    xEventGroupWaitBits(FTLLockEventGroup, (1 << newOpa.BLock), pdTRUE, pdFALSE, portMAX_DELAY);

    retVal = *newOpa.StatusBuf;
    *newOpa.StatusBuf = -5;
    return retVal;
}

int FTL_Sync()
{
    FTL_Operates newOpa;
    int retVal;
    if(!FTL_inited){
        return -1;
    }

    newOpa.opa = FTL_SYNC;
    
    newOpa.BLock = FTL_getLock();
    newOpa.StatusBuf = FTL_GetStatusBuf();

    xQueueSend(FTL_Operates_Queue, &newOpa, portMAX_DELAY);

    xEventGroupWaitBits(FTLLockEventGroup, (1 << newOpa.BLock), pdTRUE, pdFALSE, portMAX_DELAY);

    retVal = *newOpa.StatusBuf;
    *newOpa.StatusBuf = -5;
    return retVal;
}


PartitionInfo_t *FTL_GetPartitionInfo()
{
    return PartitionInfo;
}

bool FTL_ScanPartition()
{
  uint8_t *buf;
  uint32_t SectorStart[4];
  uint32_t Sectors[4]; 

    if(PartitionInfo == NULL){
        PartitionInfo = pvPortMalloc(sizeof(PartitionInfo_t));
      }
    memset(PartitionInfo, 0, sizeof(PartitionInfo_t));
  buf = pvPortMalloc(FTL_GetSectorSize());
  FTL_ReadSector(0, 1, buf);

  if((buf[0x1FE] != 0x55) || (buf[0x1FF] != 0xAA)){
    return false;
  }

  for(int i = 0; i < 4 ; i++){
    memcpy(&SectorStart[i],(void *) (((uint32_t)&buf[0x1c6]) + 0x10 * i)  , 4);
    memcpy(&Sectors[i],(void *) (((uint32_t)&buf[0x1ca]) + 0x10 * i)  , 4);
  }
  for(int i = 0; i < 4 ; i++){
    if((SectorStart[i] < FTL_GetSectorCount()) && (Sectors[i] > 0)){
      INFO("DISK PART[%d], Start Sector:%d, Size:%d\n",i,SectorStart[i], Sectors[i] * FTL_GetSectorSize());
      PartitionInfo->Partitions++;
      PartitionInfo->Sectors[i] = Sectors[i];
      PartitionInfo->SectorStart[i] = SectorStart[i];
    }
  }

  if(PartitionInfo->Partitions > 2){
    return true;
  }
  return false;
}

