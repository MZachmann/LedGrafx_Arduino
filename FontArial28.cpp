#include "Arduino.h"
#include "FontArial28.h"

// Arial 48 support (actually 39 high)
static struct CharacterInfo Arial28Infos[] =
{
	{ 33, 1054, 2, 3, 8},
	{ 36, 893, 11, 1, 14},
	{ 37, 93, 19, 1, 22},
	{ 40, 1021, 6, 2, 8},
	{ 41, 1014, 6, 0, 8},
	{ 42, 973, 8, 1, 10},
	{ 43, 657, 12, 1, 15},
	{ 44, 1048, 2, 2, 7},
	{ 45, 1035, 6, 1, 8},
	{ 46, 1060, 2, 2, 7},
	{ 48, 631, 12, 1, 14},
	{ 49, 990, 7, 2, 14},
	{ 50, 618, 12, 1, 14},
	{ 51, 605, 12, 1, 14},
	{ 52, 592, 12, 1, 14},
	{ 53, 579, 12, 1, 14},
	{ 54, 735, 12, 1, 14},
	{ 55, 709, 12, 1, 14},
	{ 56, 683, 12, 1, 14},
	{ 57, 722, 12, 1, 14},
	{ 58, 1057, 2, 2, 7},
	{ 63, 566, 12, 1, 14},
	{ 64, 26, 23, 1, 25},
	{ 65, 414, 15, 1, 17},
	{ 66, 446, 14, 2, 17},
	{ 67, 283, 16, 1, 18},
	{ 68, 430, 15, 2, 18},
	{ 69, 461, 14, 2, 17},
	{ 70, 696, 12, 2, 15},
	{ 71, 317, 16, 1, 19},
	{ 72, 476, 14, 2, 18},
	{ 73, 1051, 2, 2, 6},
	{ 74, 940, 10, 1, 13},
	{ 75, 382, 15, 2, 17},
	{ 76, 773, 11, 2, 14},
	{ 77, 265, 17, 2, 21},
	{ 78, 551, 14, 2, 18},
	{ 79, 247, 17, 1, 19},
	{ 80, 506, 14, 2, 17},
	{ 81, 211, 17, 1, 19},
	{ 82, 366, 15, 2, 18},
	{ 83, 398, 15, 1, 17},
	{ 84, 491, 14, 0, 14},
	{ 85, 536, 14, 2, 18},
	{ 86, 350, 15, 1, 17},
	{ 87, 0, 25, 0, 26},
	{ 88, 229, 17, 0, 17},
	{ 89, 300, 16, 0, 16},
	{ 90, 521, 14, 0, 15},
	{ 95, 334, 15, 0, 14},
	{ 97, 670, 12, 1, 14},
	{ 98, 761, 11, 2, 14},
	{ 99, 833, 11, 1, 13},
	{ 100, 881, 11, 1, 14},
	{ 101, 644, 12, 1, 14},
	{ 102, 998, 7, 0, 7},
	{ 103, 905, 11, 1, 14},
	{ 104, 962, 10, 2, 14},
	{ 105, 1063, 2, 2, 6},
	{ 106, 1042, 5, 0, 6},
	{ 107, 917, 11, 2, 13},
	{ 108, 1066, 2, 2, 6},
	{ 109, 173, 18, 2, 22},
	{ 110, 929, 10, 2, 14},
	{ 111, 748, 12, 1, 14},
	{ 112, 797, 11, 2, 14},
	{ 113, 809, 11, 1, 14},
	{ 114, 1028, 6, 2, 8},
	{ 115, 821, 11, 1, 13},
	{ 116, 982, 7, 0, 7},
	{ 117, 951, 10, 2, 14},
	{ 118, 785, 11, 0, 11},
	{ 119, 133, 19, 0, 19},
	{ 120, 845, 11, 0, 11},
	{ 121, 857, 11, 1, 12},
	{ 122, 869, 11, 0, 12},
	{ 153, 50, 21, 3, 25},
	{ 169, 192, 18, 0, 18},
	{ 186, 1006, 7, 1, 9},
	{ 188, 153, 19, 1, 21},
	{ 189, 113, 19, 1, 21},
	{ 190, 72, 20, 0, 21},
	{ 0,0,0,0,0}
};

static uint8_t Arial28Pixels[]=// Image Size: 134bytes x 24lines
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x1c,
0x01,0x80,0x3f,0x80,0x3f,0xdc,0x0e,0x7c,
0x00,0xe1,0xe0,0x30,0x0c,0x00,0xc0,0x00,
0x00,0x0c,0x00,0xc0,0x00,0x00,0x03,0xf0,
0x00,0x7c,0x03,0x80,0x38,0x07,0xc0,0x60,
0x00,0xc0,0x7c,0x0c,0x00,0x70,0x1f,0x00,
0x00,0x03,0x00,0x1b,0xff,0x83,0x00,0x70,
0x1f,0x80,0x0e,0x03,0xff,0x03,0xff,0x07,
0xff,0xec,0x00,0xdf,0xff,0xbf,0xf8,0x3f,
0xfe,0xc0,0x0d,0x80,0x18,0x7e,0x07,0xfc,
0x00,0xc0,0xf8,0x07,0xe0,0x3e,0x00,0x00,
0x00,0x00,0x00,0x01,0xe0,0xff,0xf7,0xff,
0x87,0xc0,0x1f,0x00,0x00,0x60,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0xf8,0x00,
0x06,0x00,0x00,0x00,0x0c,0x00,0x30,0x00,
0xc0,0x00,0x18,0x78,0xe3,0x00,0x60,0x00,
0x06,0x1b,0x01,0xb0,0xc0,0x1c,0x03,0x80,
0xff,0xe0,0x3f,0xdc,0x1e,0xc6,0x01,0xc3,
0xf0,0x60,0x3c,0x01,0x80,0x00,0x00,0x3c,
0x01,0x80,0x00,0x00,0x0f,0xfc,0x01,0xff,
0x01,0xc0,0x70,0x1f,0xf0,0x78,0x03,0xc1,
0xff,0x06,0x00,0xe0,0xff,0xc0,0x00,0x03,
0x00,0x3b,0xff,0xe3,0x00,0xe0,0x7f,0xe0,
0x0e,0x03,0xff,0xc3,0xff,0x87,0xff,0xec,
0x00,0xdf,0xff,0xbf,0xfc,0x3f,0xfe,0xc0,
0x0d,0xc0,0x18,0xff,0x07,0xfc,0x01,0xc1,
0xfe,0x0f,0xf0,0x7f,0x80,0x00,0x00,0x00,
0x00,0x07,0xf8,0xff,0xf7,0xff,0x8f,0xf0,
0x3f,0x80,0x00,0x60,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x33,0xfe,0x00,0x06,0x00,
0x00,0x00,0x0c,0x00,0x30,0x00,0xc0,0xc0,
0x18,0xf9,0xf1,0x80,0xc0,0x00,0x06,0x1b,
0x01,0xb0,0x60,0x3e,0x03,0x03,0xe0,0x78,
0x06,0x1e,0x1e,0x06,0x01,0x87,0x30,0x60,
0x7c,0x03,0x80,0x00,0x00,0x7c,0x03,0x80,
0x00,0x00,0x1e,0x1e,0x07,0x83,0xc0,0xe0,
0xe0,0x78,0x3c,0x78,0x03,0xc7,0x81,0xc3,
0x00,0xc1,0xe0,0xe0,0x00,0x01,0x80,0x33,
0x00,0xe3,0x01,0xc0,0xe0,0x70,0x1f,0x03,
0x00,0xe3,0x01,0xc6,0x00,0x0c,0x00,0xc0,
0x60,0x30,0x0e,0x00,0x0c,0xc0,0x0d,0xe0,
0x19,0xc3,0x8e,0x00,0x03,0xc3,0x86,0x1c,
0x38,0xe1,0xc0,0x00,0x00,0x00,0x00,0x0e,
0x18,0xc0,0x00,0x03,0x1c,0x38,0x61,0xc0,
0x00,0x60,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x37,0x26,0x00,0x06,0x00,0x00,0x00,
0x0c,0x00,0x30,0x04,0xc0,0xc0,0x78,0xc3,
0xb9,0x81,0x80,0x00,0x00,0x1b,0x00,0x30,
0x60,0x36,0x03,0x07,0x00,0x1c,0x06,0x1e,
0x1e,0x06,0x03,0x06,0x18,0xc0,0x4c,0x03,
0x00,0x00,0x00,0x4c,0x03,0x00,0x00,0x00,
0x38,0x07,0x06,0x00,0xc0,0x60,0xc0,0x60,
0x0c,0x7c,0x07,0xce,0x00,0xc3,0x81,0xc1,
0x80,0x30,0x00,0x01,0x80,0x33,0x00,0x73,
0x03,0x81,0x80,0x38,0x1b,0x03,0x00,0x73,
0x00,0xe6,0x00,0x0c,0x00,0xc0,0x60,0x30,
0x07,0x00,0x1c,0xc0,0x0d,0xe0,0x1b,0x81,
0xcc,0x00,0x03,0xc7,0x03,0x30,0x1c,0xc0,
0xc0,0x00,0x03,0x00,0x00,0x0c,0x0c,0xc0,
0x00,0x06,0x38,0x18,0xc0,0xe0,0x00,0x60,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,
0x23,0x00,0x06,0x00,0x00,0x00,0x0c,0x00,
0x30,0x07,0xf8,0xc0,0xf8,0xc3,0x18,0xc1,
0x80,0x00,0x00,0x1b,0x00,0x30,0x60,0x36,
0x03,0x0e,0x00,0x0e,0x06,0x1b,0x36,0x1c,
0x07,0x06,0x18,0xc0,0x0c,0x06,0x00,0x00,
0x00,0x0c,0x06,0x00,0x00,0x00,0x71,0xe3,
0x8c,0x00,0x60,0x71,0xc0,0xc0,0x06,0x6c,
0x06,0xcc,0x00,0xe1,0x83,0x83,0x00,0x30,
0x00,0x01,0xc0,0x63,0x00,0x33,0x07,0x01,
0x80,0x18,0x1b,0x03,0x00,0x33,0x00,0x66,
0x00,0x0c,0x00,0xc0,0x60,0x30,0x03,0x00,
0x38,0xc0,0x0d,0xb0,0x1b,0x00,0xcc,0x00,
0x06,0xc6,0x03,0x30,0x0d,0x80,0x60,0x00,
0x03,0x00,0x00,0x0c,0x0c,0xc0,0x00,0x06,
0x30,0x08,0xc0,0x60,0x00,0x60,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x36,0x20,0x00,
0x06,0x00,0x00,0x00,0x0c,0x00,0x30,0x01,
0xe0,0xc3,0xd8,0xc3,0x18,0xc3,0x00,0x00,
0x00,0x1b,0x00,0x30,0x30,0x76,0x06,0x0c,
0x1e,0x66,0x06,0x1b,0x36,0x06,0x0e,0x06,
0x19,0x80,0x0c,0x0c,0x06,0x02,0x03,0x0c,
0x0c,0x06,0x78,0x78,0x67,0xf1,0x8c,0x00,
0x60,0x3b,0x80,0xc0,0x06,0x6c,0x06,0xdc,
0x00,0x40,0xc3,0x03,0x00,0x10,0x00,0x00,
0xc0,0x63,0x00,0x33,0x0e,0x01,0x80,0x00,
0x31,0x83,0x00,0x33,0x00,0x66,0x00,0x0c,
0x00,0xc0,0x60,0x30,0x03,0x00,0x70,0xc0,
0x0d,0x98,0x18,0x00,0xcc,0x00,0x0e,0xc0,
0x03,0x00,0x0d,0x80,0x60,0xf0,0x03,0x00,
0x7e,0x0c,0x0c,0xc0,0x00,0x0c,0x30,0x0d,
0x80,0x00,0xf0,0x67,0x86,0x00,0x60,0x36,
0x78,0x0f,0x31,0xf8,0x0f,0x86,0x03,0x60,
0x33,0xff,0x0f,0x36,0x20,0x0f,0x36,0x0e,
0x67,0x80,0x0d,0x81,0xb3,0xc1,0xe3,0xfb,
0x9b,0xfb,0x18,0x63,0x0d,0xc0,0x06,0x1b,
0x61,0xb0,0x30,0x63,0x06,0x18,0x7f,0x66,
0x06,0x19,0x26,0x06,0x0c,0x06,0x19,0x80,
0x0c,0x1c,0x06,0x07,0x03,0x0c,0x1c,0x06,
0xfd,0xfc,0xce,0x39,0xd8,0x00,0x30,0x1f,
0x01,0x80,0x03,0x6e,0x0c,0xd8,0x00,0x00,
0xe7,0x06,0x00,0x00,0x00,0x00,0xc0,0x63,
0x00,0x73,0x1c,0x01,0xc0,0x00,0x31,0x83,
0x00,0x1b,0x00,0x66,0x00,0x0c,0x00,0xc0,
0x60,0x30,0x03,0x00,0x60,0xc0,0x0d,0x98,
0x18,0x01,0xcd,0xe0,0x0c,0xc0,0x06,0x00,
0x0d,0x80,0x63,0xfc,0x03,0x01,0xff,0x0e,
0x18,0xc0,0x00,0x0c,0x30,0x0d,0x9f,0x03,
0xfc,0x6f,0xc6,0x00,0x60,0x37,0xfc,0x1f,
0xb3,0xfc,0x1f,0xe3,0x06,0x60,0x23,0xff,
0x1f,0xb7,0x20,0x1f,0xf6,0x1c,0x6f,0xc0,
0x0d,0x81,0xb7,0xe3,0x33,0xf8,0x1b,0xfb,
0x38,0x63,0x0f,0xc0,0x06,0x1b,0x61,0xb0,
0x30,0x63,0x06,0x18,0xe3,0xc3,0x06,0x19,
0xe6,0xce,0x18,0x07,0x3b,0x00,0x0c,0x18,
0x03,0x07,0x06,0x0c,0x18,0x07,0x8f,0x8e,
0xcc,0x00,0xd8,0x00,0x30,0x0e,0x01,0x80,
0x03,0x66,0x0c,0xd8,0x00,0x00,0x66,0x06,
0x00,0x00,0x00,0x00,0x60,0xc3,0x00,0xe3,
0x38,0x00,0xfc,0x00,0x71,0x83,0x00,0x1b,
0x00,0xc6,0x00,0x0c,0x00,0xc0,0x60,0x30,
0x07,0x00,0xe0,0xc0,0x0d,0x8c,0x18,0x03,
0x9f,0xf8,0x18,0xc0,0x7c,0x00,0x19,0x80,
0x67,0x0e,0x03,0x03,0x83,0x87,0xf0,0xc0,
0x00,0x18,0x30,0x0d,0xbf,0x87,0x0e,0x78,
0xe6,0x00,0x30,0x67,0x8e,0x38,0xf7,0x0e,
0x38,0x61,0x8c,0x30,0x60,0x06,0x38,0xf3,
0xe0,0x38,0xf6,0x38,0x78,0xe0,0x0d,0x81,
0xbc,0x73,0x20,0xc0,0x18,0xc1,0xf0,0x66,
0x0e,0x00,0x06,0x1b,0x01,0xb0,0x30,0x63,
0x0e,0x39,0xc1,0xc3,0x06,0x19,0xe6,0x7c,
0x30,0x03,0xf3,0x3c,0x0c,0x30,0x03,0x0f,
0x06,0x0c,0x30,0x07,0x07,0x06,0xcc,0x00,
0xd8,0x00,0x30,0x0e,0x01,0x80,0x03,0x66,
0x0c,0xd8,0x00,0x00,0x3c,0x06,0x00,0x00,
0x00,0x00,0x60,0xc3,0xff,0xe3,0x7c,0x00,
0x7f,0xc0,0x60,0xc3,0x00,0x1b,0xff,0x87,
0xff,0xcf,0xff,0xc0,0x60,0x30,0x0e,0x01,
0xc0,0xc0,0x0d,0x86,0x18,0x07,0x1c,0x1c,
0x38,0xc0,0x7e,0x00,0x19,0x80,0x66,0x06,
0x7f,0xfb,0x01,0x87,0xf8,0xff,0xe0,0x10,
0x38,0x1d,0xe1,0xce,0x07,0x70,0x66,0x00,
0x30,0x67,0x06,0x70,0x76,0x00,0x70,0x31,
0x8c,0x30,0x60,0x0c,0x70,0x71,0xf8,0x70,
0x76,0x70,0x70,0x60,0x0d,0x81,0xb8,0x30,
0x00,0xc0,0x18,0xc0,0xe0,0x36,0x0c,0x00,
0x06,0x1b,0x01,0xb0,0x18,0xc1,0x8c,0x31,
0x80,0xc3,0x06,0x18,0xc6,0x00,0x70,0x61,
0xe6,0x7e,0x00,0x63,0xe3,0x0d,0x86,0x00,
0x60,0x66,0x06,0x06,0xcc,0x00,0xd8,0x00,
0x30,0x0e,0x01,0x80,0x03,0x63,0x18,0xd8,
0x00,0x00,0x3c,0x06,0x03,0xf8,0x00,0x00,
0x60,0xc3,0xff,0x83,0xfc,0x00,0x0f,0xf0,
0x60,0xc3,0x00,0x1b,0xff,0xc7,0xff,0xcf,
0xff,0xc0,0x60,0x3f,0xfc,0x03,0x80,0xc0,
0x0d,0x86,0x18,0x0e,0x00,0x0e,0x30,0xc0,
0x07,0x00,0x31,0x80,0x6c,0x03,0x7f,0xf8,
0x01,0x8e,0x1c,0xff,0xe0,0x30,0x18,0x3d,
0xc0,0xec,0x03,0x60,0x36,0x00,0x30,0x66,
0x03,0x60,0x37,0x00,0x60,0x00,0xd8,0x30,
0xc0,0x18,0x60,0x30,0x3e,0x60,0x36,0xe0,
0x60,0x60,0x0d,0x81,0xb0,0x30,0x00,0xc0,
0x18,0xc0,0x00,0x36,0x0c,0x00,0x06,0x1b,
0x01,0xb0,0x18,0xc1,0x8c,0x33,0x00,0xc3,
0x00,0x00,0x00,0x00,0x60,0xe0,0x06,0xe6,
0x00,0xe6,0x31,0x8d,0x8c,0x00,0xe0,0xe6,
0x06,0x06,0xcc,0x00,0xd8,0x00,0x30,0x1b,
0x01,0x80,0x03,0x63,0x18,0xd8,0x00,0x00,
0x18,0x06,0x03,0xf8,0x00,0x00,0x31,0x83,
0x06,0x03,0xce,0x00,0x00,0x70,0xff,0xe3,
0x00,0x1b,0x00,0xe6,0x00,0x0c,0x00,0xc0,
0x60,0x3f,0xf8,0x03,0x00,0xc0,0x0d,0x83,
0x18,0x0c,0x00,0x06,0x60,0xc0,0x03,0x80,
0x61,0x80,0x6f,0xff,0x03,0x00,0x0f,0x9c,
0x0e,0xc0,0x00,0x30,0x0f,0xed,0x80,0x6c,
0x03,0x60,0x36,0x00,0x18,0xc6,0x03,0x60,
0x37,0xf0,0x60,0x00,0x70,0x18,0xc0,0x38,
0x60,0x30,0x26,0x60,0x37,0xc0,0x60,0x60,
0x0d,0x81,0xb0,0x30,0x00,0xc0,0x18,0xc0,
0x00,0x36,0x0c,0x00,0x06,0x1b,0x01,0xb0,
0x18,0xc1,0x8c,0x33,0x00,0xc3,0x00,0x00,
0x00,0x00,0xc1,0xe0,0x0c,0xc3,0x00,0xc0,
0x31,0x98,0xcc,0x00,0xc1,0xe6,0x06,0x06,
0xce,0x39,0xd8,0x00,0x30,0x3b,0x81,0x80,
0x03,0x63,0x18,0xd8,0x00,0x00,0x18,0x06,
0x00,0x18,0x00,0x00,0x31,0x83,0x07,0x03,
0x87,0x00,0x00,0x18,0xff,0xe3,0x00,0x1b,
0x00,0x76,0x00,0x0c,0x00,0xc0,0x60,0x30,
0x00,0x07,0x00,0xc0,0x0d,0x81,0x98,0x18,
0x00,0x06,0xe0,0xc0,0x01,0x80,0xc1,0x80,
0x6f,0xff,0x03,0x00,0xff,0x98,0x06,0xc0,
0x00,0x60,0x07,0xcd,0x80,0x6c,0x03,0x60,
0x36,0x00,0x18,0xc6,0x03,0x60,0x31,0xfe,
0x60,0x00,0x70,0x18,0xc0,0x70,0x60,0x30,
0x23,0x60,0x37,0xe0,0x60,0x60,0x0d,0x81,
0xb0,0x30,0x00,0xc0,0x18,0xc0,0x00,0x36,
0x0c,0x1f,0x86,0x1b,0x01,0xb0,0x0d,0x80,
0xd8,0x33,0x00,0x86,0x00,0x00,0x00,0x01,
0x81,0xe0,0x0c,0xc3,0x01,0x80,0x70,0xd8,
0xd8,0x01,0x81,0xe6,0x06,0x06,0x67,0xf1,
0x8c,0x00,0x60,0x71,0xc1,0xc0,0x06,0x61,
0x30,0xdc,0x00,0x60,0x18,0x07,0x00,0x18,
0x00,0x00,0x33,0x83,0x03,0x83,0x03,0x83,
0x00,0x18,0xc0,0x63,0x00,0x33,0x00,0x36,
0x00,0x0c,0x00,0xc0,0x60,0x30,0x00,0x0e,
0x00,0xc0,0x0d,0x81,0x98,0x18,0x00,0x06,
0xff,0xf0,0x01,0x83,0x81,0x80,0x6c,0x00,
0x03,0x01,0xf1,0x98,0x06,0xc0,0x00,0x60,
0x00,0x0d,0x80,0x6c,0x03,0x60,0x36,0x00,
0x0d,0x86,0x03,0x60,0x30,0x3f,0x60,0x00,
0x70,0x19,0x80,0xe0,0x60,0x30,0x23,0x60,
0x36,0x70,0x60,0x6c,0x0d,0x81,0xb0,0x30,
0x00,0xc0,0x18,0xc0,0x00,0x36,0x0c,0x1f,
0x86,0x1b,0x01,0xb0,0x0d,0x80,0xd8,0x33,
0x01,0x86,0x00,0x00,0x00,0x03,0x83,0x60,
0x18,0xc3,0x03,0x00,0x60,0xd8,0xd8,0x03,
0x03,0x66,0x06,0x06,0x73,0xe3,0x8c,0x0c,
0x60,0xe0,0xc0,0xc0,0x06,0x61,0xb0,0xcc,
0x00,0xe0,0x18,0x03,0x00,0x18,0x00,0x00,
0x1b,0x03,0x01,0xc3,0x03,0x83,0x00,0x19,
0x80,0x33,0x00,0x33,0x00,0x36,0x00,0x0c,
0x00,0xc0,0x60,0x30,0x00,0x1c,0x00,0xc0,
0x0d,0x80,0xd8,0x18,0x18,0x06,0xff,0xf6,
0x01,0x87,0x01,0x80,0x4c,0x00,0x03,0x03,
0x01,0x98,0x06,0xc0,0x00,0x60,0x30,0x19,
0x80,0x6c,0x03,0x60,0x36,0x00,0x0d,0x86,
0x03,0x60,0x30,0x07,0x60,0x30,0xf8,0x0d,
0x81,0xc0,0x60,0x36,0x23,0x60,0x36,0x38,
0x60,0x6c,0x0d,0x81,0xb0,0x30,0x00,0xc0,
0x18,0xc0,0x00,0x36,0x0c,0x00,0x06,0x1b,
0x01,0xb0,0x0d,0x80,0xd8,0x33,0x03,0x8c,
0x00,0x00,0x00,0x03,0x06,0x60,0x18,0xc3,
0x07,0x00,0xe0,0xf0,0x78,0x07,0x06,0x66,
0x06,0x06,0x38,0x07,0x0e,0x0f,0xe0,0xc0,
0x60,0xe0,0x0c,0x61,0xf0,0xce,0x01,0xc0,
0x18,0x03,0x80,0x18,0x00,0x00,0x1b,0x03,
0x00,0xe3,0x01,0xc1,0x80,0x39,0x80,0x33,
0x00,0x73,0x00,0x36,0x00,0x0c,0x00,0xc0,
0x60,0x30,0x00,0x18,0x00,0x60,0x19,0x80,
0x78,0x00,0x18,0x0c,0x00,0xc6,0x03,0x8c,
0x00,0xc0,0xce,0x03,0x03,0x03,0x03,0x98,
0x0e,0xc0,0x00,0xc0,0x30,0x18,0xc0,0xce,
0x06,0x70,0x66,0x00,0x0f,0x87,0x06,0x70,
0x76,0x03,0x70,0x71,0xdc,0x0f,0x01,0x80,
0x70,0x76,0x27,0x70,0x76,0x18,0x60,0x6c,
0x0d,0x83,0xb0,0x30,0x00,0xc0,0x18,0xc0,
0x00,0x36,0x0c,0x00,0x06,0x18,0x01,0xb0,
0x0f,0x80,0xf0,0x31,0x87,0x9c,0x00,0x00,
0x00,0x06,0x07,0xf0,0x30,0xe7,0x06,0x01,
0x80,0x70,0x70,0x06,0x07,0xf6,0x06,0x06,
0x1c,0x0e,0x07,0x87,0xc1,0xc0,0x70,0x78,
0x3c,0x60,0xe0,0xc7,0x03,0x80,0x18,0x01,
0xe0,0x78,0x00,0x00,0x1e,0x03,0x00,0xe3,
0x00,0xe1,0xe0,0x71,0x80,0x33,0x00,0xe3,
0x00,0xe6,0x00,0x0c,0x00,0xc0,0x60,0x30,
0x00,0x30,0x00,0x70,0x39,0x80,0x78,0x00,
0x0c,0x1c,0x00,0xc3,0x07,0x18,0x00,0xe1,
0xc7,0x06,0x00,0x03,0x87,0x8c,0x1c,0xc0,
0x00,0xc0,0x18,0x30,0xe1,0xc7,0x0e,0x78,
0xe6,0x00,0x07,0x07,0x8e,0x38,0xf7,0x07,
0x38,0x61,0x8c,0x0f,0x03,0x00,0x38,0xf3,
0x2e,0x38,0xf6,0x0c,0x60,0x6e,0x19,0xc7,
0xb0,0x30,0x00,0xc0,0x18,0xc0,0x00,0x66,
0x0c,0x00,0x06,0x18,0x01,0xb0,0x07,0x00,
0x70,0x19,0xff,0xf8,0x00,0x00,0x00,0x0c,
0x00,0x60,0x30,0x7e,0x0c,0x03,0x00,0x70,
0x70,0x0c,0x00,0x66,0x06,0x06,0x0f,0xfc,
0x03,0xff,0xc3,0x80,0x38,0x3f,0xf8,0x60,
0xe0,0xc3,0xff,0x00,0x18,0x00,0xff,0xe0,
0x00,0x00,0x0e,0x03,0x00,0x73,0x00,0x70,
0xff,0xe3,0x00,0x1b,0xff,0xc3,0xff,0xe7,
0xff,0xec,0x00,0xc0,0x60,0x30,0x00,0x7f,
0xfe,0x3f,0xf1,0x80,0x38,0x18,0x07,0xf8,
0x00,0xc1,0xfe,0x3f,0xfc,0x7f,0x83,0xfc,
0x00,0x01,0xfd,0x87,0xf8,0xc0,0x00,0xc0,
0x1f,0xe0,0x7f,0x83,0xfc,0x7f,0xc7,0xff,
0x07,0x07,0xfc,0x1f,0xf3,0xfe,0x1f,0xc3,
0x06,0x07,0x07,0xff,0x1f,0xf3,0xfe,0x1f,
0xf6,0x0e,0x60,0x67,0xf8,0xff,0xb0,0x30,
0x00,0xf8,0x18,0xc0,0x00,0x63,0x0c,0x00,
0x06,0xdb,0x6d,0xb0,0x07,0x00,0x70,0x1c,
0x79,0xe1,0x80,0x00,0x00,0x1c,0x00,0x60,
0x60,0x3c,0x18,0x07,0xf0,0x20,0x20,0x18,
0x00,0x66,0x06,0x06,0x03,0xf0,0x00,0xfe,
0xf7,0x00,0x1c,0x0f,0xe0,0x60,0xe0,0xc0,
0xfe,0x00,0x18,0x00,0x3f,0x80,0x00,0x00,
0x0e,0x03,0x00,0x3b,0x00,0x38,0x3f,0x83,
0x00,0x1b,0xff,0x03,0xff,0x87,0xff,0xec,
0x00,0xc0,0x60,0x30,0x00,0x7f,0xfe,0x0f,
0xc1,0x80,0x18,0x18,0x03,0xe0,0x00,0xc0,
0xfc,0x3f,0xfc,0x3f,0x01,0xf8,0x00,0x00,
0xf8,0xc3,0xf0,0xc0,0x00,0xc0,0x07,0xc0,
0x1f,0x01,0xf8,0x67,0x87,0xff,0x02,0x06,
0x78,0x0f,0x31,0xf8,0x0f,0x86,0x07,0x06,
0x07,0xff,0x0f,0x30,0xf8,0x0f,0x36,0x07,
0x60,0x63,0xe0,0x79,0xb0,0x30,0x00,0x78,
0x18,0xc0,0x00,0x63,0x0c,0x00,0x06,0xdb,
0x6d,0xb0,0x00,0x00,0x00,0x0e,0x00,0x03,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,
0x30,0x00,0x00,0x00,0x00,0x06,0x00,0x00,
0x00,0x00,0x20,0x00,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xc3,0x00,0x00,0x06,0x40,0x00,0x00,
0x00,0x00,0x00,0x07,0x00,0x0e,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x06,0x00,0x00,0x30,0x00,
0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,
0x20,0x60,0x70,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc1,
0x80,0x00,0x06,0x40,0x00,0x00,0x00,0x00,
0x00,0x03,0xe0,0x3c,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x00,0x30,0x00,0x00,0x00,
0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x70,
0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x81,0x80,0x00,
0x0e,0xc0,0x00,0x00,0x00,0x00,0x00,0x01,
0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xf8,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,
0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x3c,
0x00,0x00,0x00,0x00,0x00,0x3f,0xc0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0x80,0xc0,0x00,0x3c,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xc0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0xff,0xf8,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,
0x30,0x00,0x00,0x00,0x00,0x38,0x00,0x00,
0x00,0x00,0x00,0x1f,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x00,0x60,0x00,0x38,0x00,0x00,0x00
};

static LargeFont* bigFont = NULL;

// bitmap is 1068x23 = 3082 bytes
LargeFont* CreateFontArial28()
{
	if(bigFont == NULL)
	{
		struct FontInfo fif = {
			Arial28Infos,		//struct CharacterInfo* CharacterDescriptors;
			Arial28Pixels,		//uint8_t* PixelData;
			24,					//int Height;     // number of scan lines
			134					//int Width;      // width in bytes of the data stream
		};
	    bigFont = new LargeFont(&fif);
	}
	return bigFont;
}
