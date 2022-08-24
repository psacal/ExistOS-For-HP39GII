

const unsigned char VGA_Ascii_5x8[] =              // ASCII
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // - -

	0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00, // -!-

	0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00, // -"-

	0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00, // -#-

	0x20,0x78,0xC0,0x70,0x28,0xF0,0x20,0x00, // -$-

	0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00, // -%-

	0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00, // -&-

	0x30,0x20,0x40,0x00,0x00,0x00,0x00,0x00, // -'-

	0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00, // -(-

	0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00, // -)-

	0x20,0xA8,0x70,0x20,0x70,0xA8,0x20,0x00, // -*-

	0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x00, // -+-

	0x00,0x00,0x00,0x00,0x60,0x40,0x80,0x00, // -,-

	0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00, // ---

	0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00, // -.-

	0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00, // -/-

	0x70,0x88,0x98,0xA8,0xC8,0x88,0x70,0x00, // -0-

	0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00, // -1-

	0x70,0x88,0x08,0x30,0x40,0x80,0xF8,0x00, // -2-

	0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00, // -3-

	0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00, // -4-

	0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00, // -5-

	0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00, // -6-

	0xF8,0x08,0x10,0x20,0x40,0x40,0x40,0x00, // -7-

	0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00, // -8-

	0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00, // -9-

	0x00,0x60,0x60,0x00,0x60,0x60,0x00,0x00, // -:-

	0x00,0x60,0x60,0x00,0x60,0x60,0x80,0x00, // -;-

	0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x00, // -<-

	0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00, // -=-

	0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, // ->-

	0x70,0x88,0x10,0x20,0x20,0x00,0x20,0x00, // -?-

	0x70,0x88,0xB8,0xA8,0xB8,0x80,0x78,0x00, // -@-

	0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00, // -A-

	0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00, // -B-

	0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00, // -C-

	0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00, // -D-

	0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00, // -E-

	0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00, // -F-

	0x70,0x88,0x80,0x80,0xB8,0x88,0x78,0x00, // -G-

	0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00, // -H-

	0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00, // -I-

	0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00, // -J-

	0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00, // -K-

	0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00, // -L-

	0x88,0xD8,0xA8,0xA8,0x88,0x88,0x88,0x00, // -M-

	0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00, // -N-

	0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00, // -O-

	0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00, // -P-

	0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00, // -Q-

	0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00, // -R-

	0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00, // -S-

	0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x00, // -T-

	0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00, // -U-

	0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00, // -V-

	0x88,0x88,0x88,0xA8,0xA8,0xD8,0x88,0x00, // -W-

	0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00, // -X-

	0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00, // -Y-

	0xF8,0x08,0x10,0x20,0x40,0x80,0xF8,0x00, // -Z-

	0xF0,0xC0,0xC0,0xC0,0xC0,0xC0,0xF0,0x00, // -[-

	0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00, // -\-

	0x78,0x18,0x18,0x18,0x18,0x18,0x78,0x00, // -]-

	0x20,0x70,0xA8,0x20,0x20,0x20,0x20,0x00, // -^-

	0x00,0x20,0x40,0xF8,0x40,0x20,0x00,0x00, // -_-

	0x20,0x10,0x08,0x00,0x00,0x00,0x00,0x00, // -`-

	0x00,0x00,0xE0,0x10,0x70,0x90,0x68,0x00, // -a-

	0x80,0x80,0xB0,0xC8,0x88,0xC8,0xB0,0x00, // -b-

	0x00,0x00,0x70,0x88,0x80,0x80,0x70,0x00, // -c-

	0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00, // -d-

	0x00,0x00,0x70,0x88,0xF0,0x80,0x70,0x00, // -e-

	0x30,0x48,0x40,0xF0,0x40,0x40,0x40,0x00, // -f-

	0x00,0x00,0x70,0x88,0x88,0x78,0x08,0xF0, // -g-

	0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,0x00, // -h-

	0x20,0x00,0x00,0x20,0x20,0x20,0x20,0x00, // -i-

	0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x60, // -j-

	0x80,0x80,0x90,0xA0,0xC0,0xA0,0x98,0x00, // -k-

	0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00, // -l-

	0x00,0x00,0x50,0xA8,0xA8,0xA8,0xA8,0x00, // -m-

	0x00,0x00,0xB0,0x48,0x48,0x48,0x48,0x00, // -n-

	0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00, // -o-

	0x00,0x00,0xF0,0x88,0x88,0xF0,0x80,0x80, // -p-

	0x00,0x00,0x78,0x88,0x88,0x78,0x08,0x08, // -q-

	0x00,0x00,0xB0,0x48,0x40,0x40,0x40,0x00, // -r-

	0x00,0x00,0x78,0x80,0x70,0x08,0xF0,0x00, // -s-

	0x40,0x40,0xF8,0x40,0x40,0x48,0x30,0x00, // -t-

	0x00,0x00,0x90,0x90,0x90,0x90,0x68,0x00, // -u-

	0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00, // -v-

	0x00,0x00,0xA8,0xA8,0xA8,0xA8,0x50,0x00, // -w-

	0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00, // -x-

	0x00,0x00,0x88,0x88,0x98,0x68,0x08,0xF0, // -y-

	0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00, // -z-

	0x20,0x40,0x40,0x80,0x40,0x40,0x20,0x00, // -{-

	0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00, // -|-

	0x20,0x10,0x10,0x08,0x10,0x10,0x20,0x00, // -}-

	0x00,0x00,0x40,0xA8,0x10,0x00,0x00,0x00, // -~-

	0xA8,0x50,0xA8,0x50,0xA8,0x50,0xA8,0x00, // --
};

 
const unsigned char VGA_Ascii_6x12[] =              // ASCII
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // - -
	0x00,0x00,0x00,0x00,

	0x00,0x10,0x10,0x10,0x10,0x10,0x00,0x00,  // -!-
	0x10,0x00,0x00,0x00,

	0x00,0x6C,0x48,0x48,0x00,0x00,0x00,0x00,  // -"-
	0x00,0x00,0x00,0x00,

	0x00,0x14,0x14,0x28,0x7C,0x28,0x7C,0x28,  // -#-
	0x50,0x50,0x00,0x00,

	0x00,0x10,0x38,0x40,0x40,0x38,0x48,0x70,  // -$-
	0x10,0x10,0x00,0x00,

	0x00,0x20,0x50,0x20,0x0C,0x70,0x08,0x14,  // -%-
	0x08,0x00,0x00,0x00,

	0x00,0x00,0x00,0x18,0x20,0x20,0x54,0x48,  // -&-
	0x34,0x00,0x00,0x00,

	0x00,0x10,0x10,0x10,0x10,0x00,0x00,0x00,  // -'-
	0x00,0x00,0x00,0x00,

	0x00,0x08,0x08,0x10,0x10,0x10,0x10,0x10,  // -(-
	0x10,0x08,0x08,0x00,

	0x00,0x20,0x20,0x10,0x10,0x10,0x10,0x10,  // -)-
	0x10,0x20,0x20,0x00,

	0x00,0x10,0x7C,0x10,0x28,0x28,0x00,0x00,  // -*-
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x10,0x10,0x10,0xFC,0x10,0x10,  // -+-
	0x10,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,  // -,-
	0x10,0x30,0x20,0x00,

	0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,  // ---
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,  // -.-
	0x30,0x00,0x00,0x00,

	0x00,0x04,0x04,0x08,0x08,0x10,0x10,0x20,  // -/-
	0x20,0x40,0x00,0x00,

	0x00,0x38,0x44,0x44,0x44,0x44,0x44,0x44,  // -0-
	0x38,0x00,0x00,0x00,

	0x00,0x30,0x10,0x10,0x10,0x10,0x10,0x10,  // -1-
	0x7C,0x00,0x00,0x00,

	0x00,0x38,0x44,0x04,0x08,0x10,0x20,0x44,  // -2-
	0x7C,0x00,0x00,0x00,

	0x00,0x38,0x44,0x04,0x18,0x04,0x04,0x44,  // -3-
	0x38,0x00,0x00,0x00,

	0x00,0x0C,0x14,0x14,0x24,0x44,0x7C,0x04,  // -4-
	0x0C,0x00,0x00,0x00,

	0x00,0x3C,0x20,0x20,0x38,0x04,0x04,0x44,  // -5-
	0x38,0x00,0x00,0x00,

	0x00,0x1C,0x20,0x40,0x78,0x44,0x44,0x44,  // -6-
	0x38,0x00,0x00,0x00,

	0x00,0x7C,0x44,0x04,0x08,0x08,0x08,0x10,  // -7-
	0x10,0x00,0x00,0x00,

	0x00,0x38,0x44,0x44,0x38,0x44,0x44,0x44,  // -8-
	0x38,0x00,0x00,0x00,

	0x00,0x38,0x44,0x44,0x44,0x3C,0x04,0x08,  // -9-
	0x70,0x00,0x00,0x00,

	0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x30,  // -:-
	0x30,0x00,0x00,0x00,

	0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x18,  // -;-
	0x30,0x20,0x00,0x00,

	0x00,0x00,0x0C,0x10,0x60,0x80,0x60,0x10,  // -<-
	0x0C,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x7C,0x00,0x7C,0x00,  // -=-
	0x00,0x00,0x00,0x00,

	0x00,0x00,0xC0,0x20,0x18,0x04,0x18,0x20,  // ->-
	0xC0,0x00,0x00,0x00,

	0x00,0x00,0x18,0x24,0x04,0x08,0x10,0x00,  // -?-
	0x30,0x00,0x00,0x00,

	0x38,0x44,0x44,0x4C,0x54,0x54,0x4C,0x40,  // -@-
	0x44,0x38,0x00,0x00,

	0x00,0x30,0x10,0x28,0x28,0x28,0x7C,0x44,  // -A-
	0xEC,0x00,0x00,0x00,

	0x00,0xF8,0x44,0x44,0x78,0x44,0x44,0x44,  // -B-
	0xF8,0x00,0x00,0x00,

	0x00,0x3C,0x44,0x40,0x40,0x40,0x40,0x44,  // -C-
	0x38,0x00,0x00,0x00,

	0x00,0xF0,0x48,0x44,0x44,0x44,0x44,0x48,  // -D-
	0xF0,0x00,0x00,0x00,

	0x00,0xFC,0x44,0x50,0x70,0x50,0x40,0x44,  // -E-
	0xFC,0x00,0x00,0x00,

	0x00,0x7C,0x20,0x28,0x38,0x28,0x20,0x20,  // -F-
	0x70,0x00,0x00,0x00,

	0x00,0x3C,0x44,0x40,0x40,0x4C,0x44,0x44,  // -G-
	0x38,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x44,0x7C,0x44,0x44,0x44,  // -H-
	0xEC,0x00,0x00,0x00,

	0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,  // -I-
	0x7C,0x00,0x00,0x00,

	0x00,0x3C,0x08,0x08,0x08,0x48,0x48,0x48,  // -J-
	0x30,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x48,0x50,0x70,0x48,0x44,  // -K-
	0xE4,0x00,0x00,0x00,

	0x00,0x70,0x20,0x20,0x20,0x20,0x24,0x24,  // -L-
	0x7C,0x00,0x00,0x00,

	0x00,0xEC,0x6C,0x6C,0x54,0x54,0x44,0x44,  // -M-
	0xEC,0x00,0x00,0x00,

	0x00,0xEC,0x64,0x64,0x54,0x54,0x54,0x4C,  // -N-
	0xEC,0x00,0x00,0x00,

	0x00,0x38,0x44,0x44,0x44,0x44,0x44,0x44,  // -O-
	0x38,0x00,0x00,0x00,

	0x00,0x78,0x24,0x24,0x24,0x38,0x20,0x20,  // -P-
	0x70,0x00,0x00,0x00,

	0x00,0x38,0x44,0x44,0x44,0x44,0x44,0x44,  // -Q-
	0x38,0x1C,0x00,0x00,

	0x00,0xF8,0x44,0x44,0x44,0x78,0x48,0x44,  // -R-
	0xE0,0x00,0x00,0x00,

	0x00,0x34,0x4C,0x40,0x38,0x04,0x04,0x64,  // -S-
	0x58,0x00,0x00,0x00,

	0x00,0xFC,0x90,0x10,0x10,0x10,0x10,0x10,  // -T-
	0x38,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x44,0x44,0x44,0x44,0x44,  // -U-
	0x38,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x44,0x28,0x28,0x28,0x10,  // -V-
	0x10,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x44,0x54,0x54,0x54,0x54,  // -W-
	0x28,0x00,0x00,0x00,

	0x00,0xC4,0x44,0x28,0x10,0x10,0x28,0x44,  // -X-
	0xC4,0x00,0x00,0x00,

	0x00,0xEC,0x44,0x28,0x28,0x10,0x10,0x10,  // -Y-
	0x38,0x00,0x00,0x00,

	0x00,0x7C,0x44,0x08,0x10,0x10,0x20,0x44,  // -Z-
	0x7C,0x00,0x00,0x00,

	0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,  // -[-
	0x20,0x20,0x38,0x00,

	0x00,0x40,0x20,0x20,0x20,0x10,0x10,0x08,  // -\-
	0x08,0x08,0x00,0x00,

	0x00,0x38,0x08,0x08,0x08,0x08,0x08,0x08,  // -]-
	0x08,0x08,0x38,0x00,

	0x00,0x10,0x10,0x28,0x44,0x00,0x00,0x00,  // -^-
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -_-
	0x00,0x00,0x00,0xFC,

	0x00,0x10,0x08,0x00,0x00,0x00,0x00,0x00,  // -`-
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x38,0x44,0x3C,0x44,0x44,  // -a-
	0x3C,0x00,0x00,0x00,

	0x00,0xC0,0x40,0x58,0x64,0x44,0x44,0x44,  // -b-
	0xF8,0x00,0x00,0x00,

	0x00,0x00,0x00,0x3C,0x44,0x40,0x40,0x44,  // -c-
	0x38,0x00,0x00,0x00,

	0x00,0x0C,0x04,0x34,0x4C,0x44,0x44,0x44,  // -d-
	0x3C,0x00,0x00,0x00,

	0x00,0x00,0x00,0x38,0x44,0x7C,0x40,0x40,  // -e-
	0x3C,0x00,0x00,0x00,

	0x00,0x1C,0x20,0x7C,0x20,0x20,0x20,0x20,  // -f-
	0x7C,0x00,0x00,0x00,

	0x00,0x00,0x00,0x34,0x4C,0x44,0x44,0x44,  // -g-
	0x3C,0x04,0x38,0x00,

	0x00,0xC0,0x40,0x58,0x64,0x44,0x44,0x44,  // -h-
	0xEC,0x00,0x00,0x00,

	0x00,0x10,0x00,0x70,0x10,0x10,0x10,0x10,  // -i-
	0x7C,0x00,0x00,0x00,

	0x00,0x10,0x00,0x78,0x08,0x08,0x08,0x08,  // -j-
	0x08,0x08,0x70,0x00,

	0x00,0xC0,0x40,0x5C,0x48,0x70,0x50,0x48,  // -k-
	0xDC,0x00,0x00,0x00,

	0x00,0x30,0x10,0x10,0x10,0x10,0x10,0x10,  // -l-
	0x7C,0x00,0x00,0x00,

	0x00,0x00,0x00,0xE8,0x54,0x54,0x54,0x54,  // -m-
	0xFC,0x00,0x00,0x00,

	0x00,0x00,0x00,0xD8,0x64,0x44,0x44,0x44,  // -n-
	0xEC,0x00,0x00,0x00,

	0x00,0x00,0x00,0x38,0x44,0x44,0x44,0x44,  // -o-
	0x38,0x00,0x00,0x00,

	0x00,0x00,0x00,0xD8,0x64,0x44,0x44,0x44,  // -p-
	0x78,0x40,0xE0,0x00,

	0x00,0x00,0x00,0x34,0x4C,0x44,0x44,0x44,  // -q-
	0x3C,0x04,0x0C,0x00,

	0x00,0x00,0x00,0x6C,0x30,0x20,0x20,0x20,  // -r-
	0x7C,0x00,0x00,0x00,

	0x00,0x00,0x00,0x3C,0x44,0x38,0x04,0x44,  // -s-
	0x78,0x00,0x00,0x00,

	0x00,0x00,0x20,0x7C,0x20,0x20,0x20,0x20,  // -t-
	0x1C,0x00,0x00,0x00,

	0x00,0x00,0x00,0xCC,0x44,0x44,0x44,0x4C,  // -u-
	0x34,0x00,0x00,0x00,

	0x00,0x00,0x00,0xEC,0x44,0x44,0x28,0x28,  // -v-
	0x10,0x00,0x00,0x00,

	0x00,0x00,0x00,0xEC,0x44,0x54,0x54,0x54,  // -w-
	0x28,0x00,0x00,0x00,

	0x00,0x00,0x00,0xCC,0x48,0x30,0x30,0x48,  // -x-
	0xCC,0x00,0x00,0x00,

	0x00,0x00,0x00,0xEC,0x44,0x24,0x28,0x18,  // -y-
	0x10,0x10,0x78,0x00,

	0x00,0x00,0x00,0x7C,0x48,0x10,0x20,0x44,  // -z-
	0x7C,0x00,0x00,0x00,

	0x00,0x08,0x10,0x10,0x10,0x10,0x20,0x10,  // -{-
	0x10,0x10,0x08,0x00,

	0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,  // -|-
	0x10,0x10,0x00,0x00,

	0x00,0x20,0x10,0x10,0x10,0x10,0x08,0x10,  // -}-
	0x10,0x10,0x20,0x00,

	0x00,0x00,0x00,0x00,0x00,0x24,0x58,0x00,  // -~-
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x24,0x58,0x00,  // --
	0x00,0x00,0x00,0x00,
};

const unsigned char VGA_Ascii_8x16[] =              // ASCII
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // - -
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,  // -!-
	0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00,

	0x00,0x66,0x66,0x66,0x24,0x00,0x00,0x00,  // -"-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x6C,0x6C,0xFE,0x6C,0x6C,  // -#-
	0x6C,0xFE,0x6C,0x6C,0x00,0x00,0x00,0x00,

	0x18,0x18,0x7C,0xC6,0xC2,0xC0,0x7C,0x06,  // -$-
	0x86,0xC6,0x7C,0x18,0x18,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0xC2,0xC6,0x0C,0x18,  // -%-
	0x30,0x60,0xC6,0x86,0x00,0x00,0x00,0x00,

	0x00,0x00,0x38,0x6C,0x6C,0x38,0x76,0xDC,  // -&-
	0xCC,0xCC,0xCC,0x76,0x00,0x00,0x00,0x00,

	0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,  // -'-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x0C,0x18,0x30,0x30,0x30,0x30,  // -(-
	0x30,0x30,0x18,0x0C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x30,0x18,0x0C,0x0C,0x0C,0x0C,  // -)-
	0x0C,0x0C,0x18,0x30,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x66,0x3C,0xFF,  // -*-
	0x3C,0x66,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x7E,  // -+-
	0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -,-
	0x00,0x18,0x18,0x18,0x30,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,  // ---
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -.-
	0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x02,0x06,0x0C,0x18,  // -/-
	0x30,0x60,0xC0,0x80,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0xCE,0xD6,0xD6,  // -0-
	0xE6,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x18,0x38,0x78,0x18,0x18,0x18,  // -1-
	0x18,0x18,0x18,0x7E,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0x06,0x0C,0x18,0x30,  // -2-
	0x60,0xC0,0xC6,0xFE,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0x06,0x06,0x3C,0x06,  // -3-
	0x06,0x06,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x0C,0x1C,0x3C,0x6C,0xCC,0xFE,  // -4-
	0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFE,0xC0,0xC0,0xC0,0xFC,0x0E,  // -5-
	0x06,0x06,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x38,0x60,0xC0,0xC0,0xFC,0xC6,  // -6-
	0xC6,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFE,0xC6,0x06,0x06,0x0C,0x18,  // -7-
	0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0xC6,  // -8-
	0xC6,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7E,0x06,  // -9-
	0x06,0x06,0x0C,0x78,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,  // -:-
	0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,  // -;-
	0x00,0x18,0x18,0x30,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,  // -<-
	0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,  // -=-
	0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,  // ->-
	0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0x0C,0x18,0x18,  // -?-
	0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x7C,0xC6,0xC6,0xDE,0xDE,  // -@-
	0xDE,0xDC,0xC0,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x10,0x38,0x6C,0xC6,0xC6,0xFE,  // -A-
	0xC6,0xC6,0xC6,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFC,0x66,0x66,0x66,0x7C,0x66,  // -B-
	0x66,0x66,0x66,0xFC,0x00,0x00,0x00,0x00,

	0x00,0x00,0x3C,0x66,0xC2,0xC0,0xC0,0xC0,  // -C-
	0xC0,0xC2,0x66,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xF8,0x6C,0x66,0x66,0x66,0x66,  // -D-
	0x66,0x66,0x6C,0xF8,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFE,0x66,0x62,0x68,0x78,0x68,  // -E-
	0x60,0x62,0x66,0xFE,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFE,0x66,0x62,0x68,0x78,0x68,  // -F-
	0x60,0x60,0x60,0xF0,0x00,0x00,0x00,0x00,

	0x00,0x00,0x3C,0x66,0xC2,0xC0,0xC0,0xDE,  // -G-
	0xC6,0xC6,0x66,0x3A,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xC6,0xC6,0xC6,0xFE,0xC6,  // -H-
	0xC6,0xC6,0xC6,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,  // -I-
	0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x1E,0x0C,0x0C,0x0C,0x0C,0x0C,  // -J-
	0xCC,0xCC,0xCC,0x78,0x00,0x00,0x00,0x00,

	0x00,0x00,0xE6,0x66,0x6C,0x6C,0x78,0x78,  // -K-
	0x6C,0x66,0x66,0xE6,0x00,0x00,0x00,0x00,

	0x00,0x00,0xF0,0x60,0x60,0x60,0x60,0x60,  // -L-
	0x60,0x62,0x66,0xFE,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,  // -M-
	0xC6,0xC6,0xC6,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xE6,0xF6,0xFE,0xDE,0xCE,  // -N-
	0xC6,0xC6,0xC6,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x38,0x6C,0xC6,0xC6,0xC6,0xC6,  // -O-
	0xC6,0xC6,0x6C,0x38,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFC,0x66,0x66,0x66,0x7C,0x60,  // -P-
	0x60,0x60,0x60,0xF0,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0xC6,0xC6,0xC6,  // -Q-
	0xC6,0xD6,0xDE,0x7C,0x0C,0x0E,0x00,0x00,

	0x00,0x00,0xFC,0x66,0x66,0x66,0x7C,0x6C,  // -R-
	0x66,0x66,0x66,0xE6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7C,0xC6,0xC6,0x60,0x38,0x0C,  // -S-
	0x06,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x7E,0x7E,0x5A,0x18,0x18,0x18,  // -T-
	0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,  // -U-
	0xC6,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,  // -V-
	0xC6,0x6C,0x38,0x10,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xC6,0xC6,0xC6,0xC6,0xD6,  // -W-
	0xD6,0xFE,0x6C,0x6C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xC6,0xC6,0x6C,0x6C,0x38,0x38,  // -X-
	0x6C,0x6C,0xC6,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x66,0x66,0x66,0x66,0x3C,0x18,  // -Y-
	0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0xFE,0xC6,0x86,0x0C,0x18,0x30,  // -Z-
	0x60,0xC2,0xC6,0xFE,0x00,0x00,0x00,0x00,

	0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,  // -[-
	0x30,0x30,0x30,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,  // -\-
	0x1C,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,

	0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,  // -]-
	0x0C,0x0C,0x0C,0x3C,0x00,0x00,0x00,0x00,

	0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00,  // -^-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // -_-
	0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,

	0x30,0x30,0x18,0x00,0x00,0x00,0x00,0x00,  // -`-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x78,0x0C,0x7C,  // -a-
	0xCC,0xCC,0xCC,0x76,0x00,0x00,0x00,0x00,

	0x00,0x00,0xE0,0x60,0x60,0x78,0x6C,0x66,  // -b-
	0x66,0x66,0x66,0xDC,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x7C,0xC6,0xC0,  // -c-
	0xC0,0xC0,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x1C,0x0C,0x0C,0x3C,0x6C,0xCC,  // -d-
	0xCC,0xCC,0xCC,0x76,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x7C,0xC6,0xFE,  // -e-
	0xC0,0xC0,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x38,0x6C,0x64,0x60,0xF0,0x60,  // -f-
	0x60,0x60,0x60,0xF0,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x76,0xCC,0xCC,  // -g-
	0xCC,0xCC,0xCC,0x7C,0x0C,0xCC,0x78,0x00,

	0x00,0x00,0xE0,0x60,0x60,0x6C,0x76,0x66,  // -h-
	0x66,0x66,0x66,0xE6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x18,0x18,0x00,0x38,0x18,0x18,  // -i-
	0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x06,0x06,0x00,0x0E,0x06,0x06,  // -j-
	0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,

	0x00,0x00,0xE0,0x60,0x60,0x66,0x6C,0x78,  // -k-
	0x78,0x6C,0x66,0xE6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x38,0x18,0x18,0x18,0x18,0x18,  // -l-
	0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xEC,0xFE,0xD6,  // -m-
	0xD6,0xD6,0xD6,0xD6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xDC,0x66,0x66,  // -n-
	0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x7C,0xC6,0xC6,  // -o-
	0xC6,0xC6,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xDC,0x66,0x66,  // -p-
	0x66,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00,

	0x00,0x00,0x00,0x00,0x00,0x76,0xCC,0xCC,  // -q-
	0xCC,0xCC,0xCC,0x7C,0x0C,0x0C,0x1E,0x00,

	0x00,0x00,0x00,0x00,0x00,0xDC,0x76,0x62,  // -r-
	0x60,0x60,0x60,0xF0,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x7C,0xC6,0x60,  // -s-
	0x38,0x0C,0xC6,0x7C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x10,0x30,0x30,0xFC,0x30,0x30,  // -t-
	0x30,0x30,0x36,0x1C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xCC,0xCC,0xCC,  // -u-
	0xCC,0xCC,0xCC,0x76,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,  // -v-
	0x66,0x66,0x3C,0x18,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xC6,0xC6,0xC6,  // -w-
	0xD6,0xD6,0xFE,0x6C,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xC6,0x6C,0x38,  // -x-
	0x38,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0xC6,0xC6,0xC6,  // -y-
	0xC6,0xC6,0xC6,0x7E,0x06,0x0C,0xF8,0x00,

	0x00,0x00,0x00,0x00,0x00,0xFE,0xCC,0x18,  // -z-
	0x30,0x60,0xC6,0xFE,0x00,0x00,0x00,0x00,

	0x00,0x00,0x0E,0x18,0x18,0x18,0x70,0x18,  // -{-
	0x18,0x18,0x18,0x0E,0x00,0x00,0x00,0x00,

	0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x18,  // -|-
	0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00,

	0x00,0x00,0x70,0x18,0x18,0x18,0x0E,0x18,  // -}-
	0x18,0x18,0x18,0x70,0x00,0x00,0x00,0x00,

	0x00,0x00,0x76,0xDC,0x00,0x00,0x00,0x00,  // -~-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x10,0x38,0x6C,0xC6,  // --
	0xC6,0xC6,0xFE,0x00,0x00,0x00,0x00,0x00,
};