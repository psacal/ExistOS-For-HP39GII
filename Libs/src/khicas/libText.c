#include <stdio.h>
#include <stdlib.h>
#include "LibText.h"

// Thanks to Simon Lothar for this function
typedef char*(*Txt_SC)(void);
const unsigned int Txt_SC_VRAM[] = { 0xD201D002, 0x422B0009, 0x80010070, 0x0135 };
#define Txt_GetVRAM (*(Txt_SC)Txt_SC_VRAM)
char *Txt_VRAM;

unsigned int *Txt_Fonts[TXT_FONTS];

void Txt_Init(int fonts)
{
  int i;
  Txt_VRAM = Txt_GetVRAM();
  for(i=0;i<TXT_FONTS;i++) Txt_Fonts[i] = NULL;

  if(fonts & FONT_MINISD)
  {
    unsigned int FontMINISD[60] = {
    4141870527, 3682580223, 1845419005, 3086708726, 3756900315, 2142699373, 4275830199, 4218418911, 
    3988773759, 3070193150, 3690838011, 1878450157, 3218833334, 4285398747, 4256693103, 37386, 
    3490052053, 4092635221, 1436811305, 588403370, 6094850, 1081081857, 312768220, 2992611135, 
    754678078, 1945958386, 2465718255, 1008762945, 581051278, 573203074, 3319574455, 1567855165, 
    1843292668, 3526962103, 3687996563, 2109397284, 4158356918, 2875905864, 2907135339, 2297336406, 
    3689788763, 2109037418, 1268071241, 823204133, 2499805191, 2550144430, 1802531378, 3982580954, 
    3912945306, 3666238595, 1555782802, 3808118454, 2238323432, 493116704, 2045104738, 3687167243, 
    2098551341, 2021112657, 882006293, 2210430975 };
    Txt_Fonts[TXT_MINISD] = malloc(240);    
    for(i=0;i<60;i++) Txt_Fonts[TXT_MINISD][i] = FontMINISD[i];
  }

  if(fonts & FONT_7SEGMINI)
  {
    unsigned int Font7SEGMINI[60] = {
    4141870527, 3682580223, 1845419005, 3086708726, 3756900315, 2142699373, 4275830199, 4218418911, 
    3988773759, 3070193150, 3690838011, 1878450157, 3218833334, 4285398747, 4256693103, 37386, 
    3490052052, 4090538069, 1436811346, 1149840042, 6094850, 2154823681, 44103390, 1227333439, 
    1023113534, 1945958386, 1240981487, 1008762945, 1117922190, 573203074, 3302879159, 3716125309, 
    1843296764, 4068044727, 3687997348, 3048921380, 4158356918, 4218419145, 3992968559, 2633929302, 
    3689788763, 2109037418, 1268072338, 1896946835, 3573547015, 1140953022, 1333272178, 2112813532, 
    4063940243, 3665976580, 3029818514, 3808116982, 2179931896, 1038384043, 2632574176, 1539355915, 
    2097326597, 1215806289, 882006293, 2155380735 };
    Txt_Fonts[TXT_7SEGMINI] = malloc(240);
    for(i=0;i<60;i++) Txt_Fonts[TXT_7SEGMINI][i] = Font7SEGMINI[i];
  }

  if(fonts & FONT_SYSTEM)
  {
    unsigned int FontSYSTEM[140] = {
    4234352839, 4287390488, 4294020195, 536752524,  1677706801, 2357196998, 831520536,  3325165539, 
    415645692,  1662568447, 2355304703, 4052509471, 4264660067, 4291178892, 2147010097, 2415859910, 
    838853400,  3326082147, 415760268,  1662582769, 2355306494, 831284223,  3325135999, 4173738383, 
    4279813681, 4293073094, 1073505048, 3355413603, 419426700,  1663041073, 2355363782, 831291384, 
    3325136895, 415642111,  3810051647, 0,          69273664,   290082816,  2711383,    3567402638, 
    797543560,  2291718442, 582118152,  2147483665, 277090376,  545530400,  78355794,   8714504, 
    97,         268436448,  0,          207618594,  570455143,  1556464741, 138575313,  143167484, 
    1141924577, 424867973,  4168622475, 2357754417, 2009211408, 2222220008, 3318647902, 288361568, 
    415236492,  50888840,   2283831808, 2082406432, 2181597315, 2719027204, 1950538453, 3465314072, 
    3352399779, 523907204,  586041905,  2360997955, 3498573576, 2047902627, 163983244,  1677248063, 
    554189436,  3792733478, 1179960613, 406982788,  1058920113, 2355305686, 1904976664, 3324965987, 
    3896643212, 1666791377, 2410227898, 812671727,  2424578313, 415641995,  2736309802, 610491094, 
    2861323333, 1177652308, 1108599057, 286243080,  1108402241, 68174049,   138548104,  2826960896, 
    31,         1627652096, 230136,     3188766307, 520097412,  585139635,  2354970682, 1065584199, 
    277094400,  4173082244, 764986912,  538460728,  1076921638, 1108518441, 638616609,  469789365, 
    2906655590, 830996712,  3324903485, 524419075,  3807413248, 3059812352, 260277220,  1896366668, 
    4600219,    1074316618, 536942806,  2852139618, 845153362,  1650458872, 2291107972, 1091052048, 
    2216757378, 272900608,  81149959,   4294967295 };
    Txt_Fonts[TXT_SYSTEM] = malloc(560);
    for(i=0;i<140;i++) Txt_Fonts[TXT_SYSTEM][i] = FontSYSTEM[i];
  }

  if(fonts & FONT_7SEG)
  {
    unsigned int Font7SEG[140] = {
    4234352839, 4287390488, 4294020195, 536752524, 1677706801, 2357196998, 831520536, 3325165539, 
    415645692, 1662568447, 2355304703, 4052509471, 4264660067, 4291178892, 2147010097, 2415859910, 
    838853400, 3326082147, 415760268, 1662582769, 2355306494, 831284223, 3325135999, 4173738383, 
    4279813681, 4293073094, 1073505048, 3355413603, 419426700, 1663041073, 2355363782, 831291384, 
    3325136895, 415642111, 3810051647, 0, 69273664, 290082816, 2711383, 3567402638, 
    797542536, 2290669866, 582117640, 1073741858, 277094532, 277094672, 78355794, 8714504, 
    33, 134218720, 0, 2097698, 570489955, 415752456, 1108379617, 266407932, 
    569918456, 3326019651, 4165198095, 4278746673, 4290908292, 570188792, 3355413630, 284951552, 
    134217856, 17318024, 2283831808, 2082406432, 2181597319, 3256057860, 4165204167, 4287397656, 
    3354496931, 536744068, 570377777, 2357065795, 4035444488, 2115012577, 147210124, 1677248063, 
    554189439, 3827370062, 1179960613, 406982788, 1058919985, 2355305686, 1905255192, 3326082147, 
    4165083020, 1666807793, 2409830654, 284705791, 2424578313, 415641999, 3810051626, 610491094, 
    3146536005, 1177652308, 1108599057, 286260752, 2216816705, 68174320, 2216759240, 2826960896, 
    31, 1627652096, 508920, 4262496227, 528490372, 569410623, 2357067902, 1065864775, 
    277094401, 4177280900, 569951776, 538460728, 1076921383, 1108518441, 638616609, 469789365, 
    2906656710, 830996984, 3326017599, 532807687, 3824190464, 4230023168, 528991220, 1896366620, 
    4600207, 3221800490, 536942806, 2852135586, 706741347, 4043047160, 2291112068, 1091068432, 
    2216757442, 272900864, 215375879, 4294967295 };
    Txt_Fonts[TXT_7SEG] = malloc(560);
    for(i=0;i<140;i++) Txt_Fonts[TXT_7SEG][i] = Font7SEG[i];
  }

  if(fonts & FONT_ARCADIUM)
  {
    unsigned int FontARCADIUM[100] = {
    4234354686, 831520536,  3355413603, 4291179007, 3810066417, 2357196998, 1073505055, 4264660991, 
    415760268,  1677706801, 4293073151, 4052516856, 3326082147, 536752527,  4279814143, 2355363782, 
    838853400,  4294020223, 4173742076, 1663041073, 2415859911, 4287390719, 3325165539, 419426700, 
    2147010111, 16,         2214663328, 719550,     2815542774, 1682231281, 2357117472, 2232450, 
    272765204,  1334920231, 3359637892, 1073868800, 202769,     286291051,  387023911,  4229383166, 
    193194183,  3775914464, 4191220829, 4035478644, 1561803311, 194560049,  2349009025, 285478974, 
    260113425,  283678724,  1885034298, 1066171679, 1204782112, 4282790391, 3788013552, 3827361870, 
    780959512,  4236519422, 692687247,  2736275984, 4235679942, 967631592,  3324966013, 138031515, 
    4246685231, 2206461840, 2216977176, 3123808905, 416721546,  2292761924, 557720099,  3997307112, 
    545393540,  557353608,  31,         822345784,  797679887,  1203797024, 4035309947, 2749905361, 
    3290491068, 1048949528, 2684895644, 554274948,  3106152712, 808803028,  479503367,  1177421731, 
    3892441464, 1097646606, 2198194298, 275785001,  806524176,  147237382,  2290811210, 570548771, 
    3324119138, 277095176,  573573548,  2181038079 };
    Txt_Fonts[TXT_ARCADIUM] = malloc(400);
    for(i=0;i<100;i++) Txt_Fonts[TXT_ARCADIUM][i] = FontARCADIUM[i];
  }

  if(fonts & FONT_SERIF)
  {
    unsigned int FontSERIF[168] = {
    4263010694, 536839704, 1636302817, 2249744895, 4167140888, 2147358817, 2250243974, 409044991, 
    3783661665, 4294467974, 411041304, 1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 
    409044511, 4286978145, 2281693574, 409075704, 1636178047, 4263010694, 536839704, 1636302817, 
    2249744895, 4167140888, 2147358817, 2250243974, 409044991, 3783661665, 4294467974, 411041304, 
    1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 409044511, 4286978145, 2281693574, 
    409075704, 1636178047, 0, 532610, 134251796, 1342177281, 1161712613, 343058972, 
    715600072, 1108383846, 614533796, 1757480960, 4226, 136347912, 272696336, 2325508768, 
    520, 4169269248, 12354, 3968, 0, 798736, 2216757248, 1915529882, 
    654860930, 136570658, 138547451, 3775402024, 2618344740, 4165025410, 117606851, 277072034, 
    1944093728, 2181591592, 2626299676, 2317845009, 2148282371, 201327372, 12650504, 1108353088, 
    2147741759, 264208, 554189256, 2182119432, 1914733162, 2802067620, 1598537617, 1172591097, 
    3898638856, 1593381969, 1159708485, 1192511487, 3511797008, 1105748126, 408874260, 1598365438, 
    545392675, 4018675842, 675517588, 1631893985, 68174111, 4050474321, 1203687781, 1423044072, 
    1636178014, 4178861633, 236881432, 1581318033, 1172640485, 3898636312, 1593483784, 545733445, 
    340870382, 3510964874, 330584405, 1430948389, 139602082, 2302806049, 3483504772, 586727944, 
    545393666, 67637280, 1276133636, 281154696, 0, 63, 1619066880, 385, 
    479308816, 1097224568, 1870344, 2618040474, 2586279937, 3367928259, 306414608, 3771044408, 
    613204228, 375723072, 537266209, 3254804610, 138609682, 1367675488, 2181570695, 173397, 
    1431306457, 2488394752, 478816412, 3650376057, 68852264, 2651353088, 3649310944, 1999296, 
    3158541328, 1090715651, 3025224928, 15536778, 268450629, 1430913032, 2485209216, 19172369, 
    2147547714, 318292488, 1082264608, 2181570690, 202391684, 281018442, 2835350527, 4294967295 };
    Txt_Fonts[TXT_SERIF] = malloc(672);
    for(i=0;i<168;i++) Txt_Fonts[TXT_SERIF][i] = FontSERIF[i];
  }

  if(fonts & FONT_SERIFITALIC)
  {
    unsigned int FontSERIFITALIC[168] = {
    4263010694, 536839704, 1636302817, 2249744895, 4167140888, 2147358817, 2250243974, 409044991, 
    3783661665, 4294467974, 411041304, 1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 
    409044511, 4286978145, 2281693574, 409075704, 1636178047, 4263010694, 536839704, 1636302817, 
    2249744895, 4167140888, 2147358817, 2250243974, 409044991, 3783661665, 4294467974, 411041304, 
    1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 409044511, 4286978145, 2281693574, 
    409075704, 1636178047, 0, 266434, 134284470, 2415919104, 2457816057, 607737100, 
    715600528, 1124607283, 2454817444, 3904964608, 4226, 272695812, 136348688, 2236510880, 
    260, 2021785600, 12354, 1920, 0, 798720, 53673984, 957769098, 
    654586177, 136431489, 99098873, 4030869536, 3155731620, 4232126273, 117574595, 3493980322, 
    1944618000, 2182101268, 1586112270, 1159168523, 3222024198, 402653964, 25301000, 1108353088, 
    2147741759, 264208, 554189256, 2182119440, 2047885674, 2802197652, 1598535569, 1206428400, 
    3830481416, 2625180769, 2318344005, 138183655, 3510767392, 2163495054, 413025556, 1660561550, 
    272762913, 3280212098, 146871444, 3800638017, 69239343, 2439861346, 2317637974, 681740516, 
    1367746716, 949113209, 235816216, 1651536777, 622301924, 3830460456, 2625458436, 545732933, 
    342002638, 1363748116, 1672761738, 2863957301, 2355832930, 2441220163, 2278623428, 586736136, 
    1090788417, 34086977, 235413764, 297863752, 0, 63, 1619066880, 224, 
    2626790920, 1120707184, 935432, 2617512026, 2586279936, 3831464897, 2300822544, 3771044408, 
    1226359044, 751446144, 268633121, 3254804612, 281216148, 1661609008, 1090789511, 173397, 
    2862612584, 3562203136, 239474844, 3650379330, 136026663, 69320704, 1824788704, 999616, 
    3156328976, 1090715651, 3026356672, 15537300, 1610627910, 445906952, 2485209216, 19172387, 
    30786, 284188932, 1619135504, 1091051650, 202392464, 1124073546, 2835350527, 4294967295 };
    Txt_Fonts[TXT_SERIFITALIC] = malloc(672);
    for(i=0;i<168;i++) Txt_Fonts[TXT_SERIFITALIC][i] = FontSERIFITALIC[i];
  }

  if(fonts & FONT_SERIFBOLD)
  {
    unsigned int FontSERIFBOLD[168] = {
    4263010694, 536839704, 1636302817, 2249744895, 4167140888, 2147358817, 2250243974, 409044991, 
    3783661665, 4294467974, 411041304, 1636179967, 2249744775, 4292970008, 1643903073, 2249752574, 
    409044511, 4286978145, 2281693574, 409075704, 1636178047, 4263010694, 536839704, 1636302817, 
    2249744895, 4167140888, 2147358817, 2250243974, 409044991, 3783661665, 4294467974, 411041304, 
    1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 409044511, 4286978145, 2281693574, 
    409075704, 1636178047, 0, 817635, 201379254, 3623878657, 1161712613, 343629086, 
    391623116, 1662570039, 3019476854, 2095156224, 12678, 409043724, 409044504, 3399250592, 
    49983, 4240637952, 798786, 262080, 0, 798736, 3325135904, 2067724239, 
    931950787, 204597171, 2355304957, 3972216892, 3726173606, 4234264519, 260279783, 3015961843, 
    2080163376, 3272375100, 3738122142, 3476538317, 3758895107, 201327372, 12650520, 3325059265, 
    2147741759, 396312, 831283692, 3273179148, 2066793326, 3080638271, 4090445721, 1709595129, 
    3966812940, 1593415257, 1704968037, 2274912255, 3647071768, 1642885327, 475985302, 1600495454, 
    818089009, 3884724419, 753121180, 1640479729, 2249744799, 4058996081, 3340563439, 2096352748, 
    4090445022, 4187381345, 2401161020, 4264591257, 1709595125, 3975182396, 3741242124, 818396517, 
    2522440942, 4056356506, 867987927, 1566232375, 2356886771, 3454209073, 4024637638, 838714904, 
    1636179075, 101455920, 1310220678, 417471706, 536870912, 63, 1891729408, 449, 
    2660891696, 3278795256, 2019084, 3725340891, 2654453761, 3967730163, 2573452824, 4056524408, 
    1771881228, 921115712, 12590129, 3808456899, 744688690, 3549246064, 3272356039, 2147659125, 
    3612344539, 2624709632, 516898014, 3684463099, 203136568, 3742134272, 3989182704, 2015712, 
    3731080728, 1636007939, 3161572832, 15668890, 805321671, 1566179340, 3727813824, 40475699, 
    2147548771, 436003596, 1623395888, 3272356035, 472957324, 834666570, 2835350527, 4294967295 };
    Txt_Fonts[TXT_SERIFBOLD] = malloc(672);
    for(i=0;i<168;i++) Txt_Fonts[TXT_SERIFBOLD][i] = FontSERIFBOLD[i];
  }

  if(fonts & FONT_SERIFBOLDITALIC)
  {
    unsigned int FontSERIFBOLDITALIC[168] = {
    4263010694, 536839704, 1636302817, 2249744895, 4167140888, 2147358817, 2250243974, 409044991, 
    3783661665, 4294467974, 411041304, 1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 
    409044511, 4286978145, 2281693574, 409075704, 1636178047, 4263010694, 536839704, 1636302817, 
    2249744895, 4167140888, 2147358817, 2250243974, 409044991, 3783661665, 4294467974, 411041304, 
    1636179967, 2249744775, 4292970008, 1644165217, 2249752574, 409044511, 4286978145, 2281693574, 
    409075704, 1636178047, 0, 399587, 201426651, 3680501760, 2457816057, 612062540, 
    2864165592, 1124625715, 2454817444, 3921876992, 6339, 409043724, 409046065, 2236510880, 
    49982, 4186308608, 28870, 257920, 0, 798720, 3488808960, 966161867, 
    654719075, 2352080771, 233582833, 4039536737, 3155997926, 4234256225, 2273513443, 3630296307, 
    2079901208, 3273144726, 1590372126, 3476522523, 3222024198, 402653964, 25301016, 3325059265, 
    2147741759, 396312, 831283692, 3273179160, 2050016110, 3876482486, 4292568985, 1743565552, 
    3864576780, 2625214065, 3408863077, 2410728423, 3647204400, 3237370063, 480179606, 2127244958, 
    818354275, 3284539627, 1013036763, 4224562017, 2251342639, 2439861346, 2317770095, 481478886, 
    1506225308, 953375097, 2400085404, 1919972237, 899127796, 3864539241, 2633945884, 1636777317, 
    2524105679, 1500096284, 1672761738, 2863975271, 141781427, 4259519587, 3487766726, 838656780, 
    1636179041, 2198614113, 2383962892, 834735725, 805306368, 63, 1891729408, 224, 
    3751394320, 2196562808, 943884, 2618044630, 3127345152, 3839853505, 2368988696, 4041593660, 
    1771880708, 785333440, 402884145, 3808456902, 417531094, 1938765368, 1636184263, 2147657045, 
    2862612584, 3562203136, 240007580, 3652509250, 136027703, 2251415552, 1824921840, 2023905, 
    4264682264, 1636007939, 3035011520, 15545558, 1879063366, 714342412, 3727813824, 20237875, 
    2147515491, 418964236, 3783662616, 1636577475, 236479448, 1669333066, 2835350527, 4294967295 };
    Txt_Fonts[TXT_SERIFBOLDITALIC] = malloc(672);
    for(i=0;i<168;i++) Txt_Fonts[TXT_SERIFBOLDITALIC][i] = FontSERIFBOLDITALIC[i];
  }

  if(fonts & FONT_RUNES)
  {
    unsigned int FontRUNES[224] = {
    0, 84, 3668859510, 1360793681, 1378110090, 134754467, 1166678048, 3187432, 
    780802108, 2252313636, 2231631985, 341669343, 469763068, 3102378504, 6365763, 67899392, 
    1629733382, 135791074, 1199836176, 805338386, 608735612, 7460030, 4200012800, 551727082, 
    2382953734, 3436724192, 4279259475, 1699383816, 128031, 4066443008, 33030128, 1627324472, 
    2333750178, 939580415, 4293889544, 14318841, 4019062784, 3665623531, 2382889178, 2096752778, 
    134273612, 405309960, 798375, 2319344640, 541101794, 67633184, 1095525636, 134217732, 
    1204879360, 2130443, 3431533568, 17907976, 2315784273, 276990080, 7153162, 674388736, 
    33295, 3892838400, 2109408, 2181038112, 3802202628, 134225984, 2164952584, 8303, 
    3783393280, 8589292, 134217760, 3823174148, 134225984, 2165280264, 12698567, 3474731008, 
    410118087, 2265317376, 1103618047, 2147614715, 3816947712, 41519, 3901358096, 1901101322, 
    2382888960, 2742021514, 1077744, 2165280264, 8462887, 3766616064, 143798216, 134217968, 
    541238146, 30849, 177080320, 1053684, 1225785344, 1091036228, 2164260880, 1901101342, 
    16837, 1107562240, 8462951, 3783393280, 143863756, 134217968, 541320066, 30849, 
    260966400, 1061876, 3373268992, 1099425348, 2164260880, 1911587102, 16839, 3255045888, 
    238, 0, 1086407174, 168820800, 3242394892, 268451969, 33950242, 17243481, 
    896647424, 2310186056, 2434924713, 2456258576, 536871442, 1124471362, 37346, 1200169472, 
    4227330, 67633152, 1082196484, 268443712, 2164458769, 4243778, 67637248, 2310186696, 
    2434924576, 1115914884, 134255042, 76419104, 5284290, 118100992, 2310186058, 2602696768, 
    3242395146, 301998145, 58786824, 2155173, 1107560448, 2172814473, 304349184, 2434942220, 
    268436052, 2840900932, 11096513, 33818624, 4044498890, 2504130592, 1082197781, 704647458, 
    3800109594, 8458819, 169582592, 2174788169, 304087084, 1218955812, 1744855075, 3825733378, 
    5284295, 3656891904, 1352746969, 4156424272, 2705608823, 3187691681, 1146118334, 5284399, 
    4193762816, 1352804411, 4156424272, 2720542839, 3187691682, 674259134, 5284391, 3416202240, 
    2705606807, 1043857488, 2720286879, 469782690, 608735516, 798378, 2318035968, 3978994346, 
    1809842200, 1364538864, 3112, 2726963296, 1853586, 3391643648, 68702500, 2457337856, 
    1885422640, 536899860, 2683457820, 33426581, 1217005568, 547579213, 2315780217, 207178821, 
    67109299, 2452132376, 32, 2315790336, 131, 2334130176, 2146954, 939524096, 
    545392672, 96, 3255312384, 255045, 67108864, 21416081, 1040187393, 1116246300 };
    Txt_Fonts[TXT_RUNES] = malloc(896);
    for(i=0;i<224;i++) Txt_Fonts[TXT_RUNES][i] = FontRUNES[i];
  }

  if(fonts & FONT_DOS)
  {
    unsigned int FontDOS[280] = {
    4278586392, 811647363, 4294711344, 1623294726, 268431456, 3246589452, 406847425, 2198211608, 
    811663359, 101455920, 1623294975, 4229443680, 3246589455, 4293943489, 2198211608, 1073725827, 
    101455920, 1627389702, 202911840, 3246653436, 405823681, 2198212607, 4032872835, 101455935, 
    4290872070, 202911840, 4294903308, 405823681, 2214591512, 811647363, 101711856, 1623294726, 
    202915839, 3246589452, 405823743, 4278586392, 811647363, 4294711344, 1623294726, 268431456, 
    3246589452, 406847425, 2198211608, 811663359, 101455920, 1623294975, 4229443680, 3246589455, 
    4293943489, 2198211608, 1073725827, 101455920, 1627389702, 202911840, 3246653436, 405823681, 
    2198212607, 4032872835, 101455935, 4290872070, 202911840, 4294903308, 405823681, 2214591512, 
    811647363, 101711856, 1623294726, 202915839, 3246589452, 405823743, 0, 0, 
    6415303, 2248939520, 1623616729, 2449473536, 54, 1845343078, 3755685392, 4217280259, 
    2783673376, 102523270, 409046552, 59611932, 2008757868, 3469085720, 1610612736, 6241, 
    2198211608, 808464576, 3233907462, 202924416, 13881, 4242759680, 12387, 4158850560, 
    0, 1548, 408944640, 4194048, 0, 0, 99072, 400497, 
    3340513280, 2106531453, 2096227270, 4167157635, 101455920, 1677187265, 2198614211, 209706851, 
    101511216, 1626455564, 955477215, 3271953471, 4131133503, 50827035, 3889754208, 4254015036, 
    1874846470, 204522246, 202931599, 506976497, 3821468150, 1014554499, 101653472, 396288, 
    49536, 6192, 774, 402656304, 3272346636, 202113024, 264241278, 12, 
    202116108, 818088991, 1673926752, 3246392844, 2106531453, 2062937792, 4193664120, 4060071823, 
    507497689, 3011300763, 914329395, 3280143884, 408526584, 3650827884, 3652414963, 4214631710, 
    1013499295, 4293712052, 2029101830, 504312771, 2198240376, 3651061647, 507508977, 3821505776, 
    3246589452, 405823969, 3783460364, 456551631, 968058585, 3821456601, 4092641667, 101455921, 
    1744772991, 4294304711, 2401123452, 4261404575, 507279583, 1674022686, 1014559166, 4241333047, 
    3424137313, 3791010936, 4058767096, 813681881, 3011310003, 1719459683, 3353473264, 2029108862, 
    4251500931, 101455995, 507279601, 3821506331, 3967349219, 3348045687, 3341935559, 2405350783, 
    4223059853, 3018032927, 919047579, 913100556, 405823983, 4175529496, 1636179071, 3474468960, 
    3246589452, 503317255, 117901063, 100724832, 3246589452, 405922055, 459472896, 0, 
    0, 127, 1623244992, 0, 15, 54447515, 868092952, 1046924699, 
    913276928, 16457228, 405913116, 406056153, 3009858796, 4017, 4290872091, 3787902104, 
    2019606915, 251658240, 4013320129, 3007111361, 2204593369, 3009924096, 198144, 942694880, 
    768, 471545447, 3090178253, 3016199577, 4080545888, 3246589452, 410517504, 499117015, 
    2942185472, 7235277, 2604035264, 64286, 1014559166, 1766, 1826209377, 3758096398, 
    4083600632, 821035008, 1853279619, 102629376, 16456451, 2175909392, 1623712518, 202913336, 
    6579, 1724750643, 2952790115, 3348045366, 3338665985, 2401156474, 4290117632, 104253198, 
    476941312, 1634787, 2114728896, 32716, 818089087, 3280738352, 3246490374, 119025760, 
    3246589452, 405913793, 2198013464, 811827200, 30648, 63, 4294967295, 4294967295 };
    Txt_Fonts[TXT_DOS] = malloc(1120);
    for(i=0;i<280;i++) Txt_Fonts[TXT_DOS][i] = FontDOS[i];
  }
}

void Txt_Pixel(int x, int y, int v)
{
  if(x&~127 || y&~63) return;
  if(v) *(Txt_VRAM+(y<<4)+(x>>3)) |=  (128>>(x&7));
  else  *(Txt_VRAM+(y<<4)+(x>>3)) &= ~(128>>(x&7));
}

void Txt_Point(int x, int y, int v, int m)
{
  switch(m)
  {
    case TXT_OR:  if(v) Txt_Pixel(x,y,1); break;
    case TXT_ON:  Txt_Pixel(x,y,v); break;
    case TXT_AND: if(v) Txt_Pixel(x,y,0); break;
    case TXT_REV: Txt_Pixel(x,y,!v); break;
    case TXT_XOR: if(v) Txt_Pixel(x,y,!Txt_Get(x,y)); break;
  }
}

int Txt_Get(int x, int y)
{
  return (*(Txt_VRAM+(y<<4)+(x>>3)) >> (~x&7))&1;
}

void Txt_Char(char c, int x, int y, int f, int w, int h, int m)
{
  unsigned int *font = Txt_Fonts[f];
  unsigned char a,b,v;
  int offbyte = (c*w*h)>>5;
  int offbit  = (c*w*h)&31;
  if(!font) return;

  for(b=0;b<h;b++)
  {
    for(a=0;a<w;a++)
    {
      v = (font[offbyte]&(1<<(31-offbit)))!=0;
      Txt_Point(x+a,y+b,v,m);
      if(offbit++==31) offbyte++, offbit=0;
    }
  }
}

void Txt_Text(char *s, int x, int y, int f, int m)
{
  int w = Txt_Width(f);
  int h = Txt_Height(f);
  int i;

  while(*s)
  {
    Txt_Char(*(s++),x,y,f,w,h,m);
    x += w+1;
    if(*s) for(i=0;i<h;i++) Txt_Point(x-1,y+i,0,m);
  }
}

int Txt_Width(int f)
{
  const unsigned int w[TXT_FONTS] = { 3, 3, 5, 5, 5, 6, 6, 6, 6, 7, 7 };
  return w[f];
}

int Txt_Height(int f)
{
  const unsigned int h[TXT_FONTS] = { 5, 5, 7, 7, 5, 7, 7, 7, 7, 8, 10 };
  return h[f];
}

void Txt_Quit(void)
{
  int i;
  for(i=0;i<TXT_FONTS;i++) if(Txt_Fonts[i]) free(Txt_Fonts[i]);
}
