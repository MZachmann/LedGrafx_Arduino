//#include "../application.h"
// this typeface has a list of descriptors and a list of pixel data (bytes)
#include "FontArial11.h"

// Arial 48 support (actually 39 high)
static struct CharacterInfo Arial11Infos[] =
{ { 33, 676, 1, 2, 5},
{ 36, 519, 7, 1, 9},
{ 37, 73, 12, 1, 14},
{ 40, 666, 3, 1, 5},
{ 41, 670, 3, 1, 5},
{ 42, 625, 5, 0, 6},
{ 43, 551, 7, 1, 9},
{ 44, 674, 1, 2, 4},
{ 45, 637, 4, 0, 5},
{ 46, 682, 1, 2, 4},
{ 48, 487, 7, 1, 9},
{ 49, 652, 4, 2, 9},
{ 50, 567, 7, 1, 9},
{ 51, 575, 7, 1, 9},
{ 52, 365, 8, 0, 9},
{ 53, 383, 7, 1, 9},
{ 54, 391, 7, 1, 9},
{ 55, 399, 7, 1, 9},
{ 56, 407, 7, 1, 9},
{ 57, 415, 7, 1, 9},
{ 58, 680, 1, 1, 4},
{ 63, 423, 7, 1, 9},
{ 64, 16, 15, 1, 16},
{ 65, 265, 9, 1, 11},
{ 66, 275, 9, 1, 11},
{ 67, 193, 10, 1, 12},
{ 68, 204, 10, 1, 12},
{ 69, 305, 9, 1, 11},
{ 70, 374, 8, 1, 10},
{ 71, 160, 10, 1, 12},
{ 72, 285, 9, 1, 11},
{ 73, 678, 1, 1, 3},
{ 74, 590, 6, 1, 8},
{ 75, 345, 9, 1, 11},
{ 76, 431, 7, 1, 9},
{ 77, 124, 11, 1, 13},
{ 78, 215, 9, 1, 11},
{ 79, 171, 10, 1, 12},
{ 80, 225, 9, 1, 11},
{ 81, 182, 10, 1, 12},
{ 82, 355, 9, 1, 11},
{ 83, 315, 9, 1, 11},
{ 84, 335, 9, 0, 9},
{ 85, 235, 9, 1, 11},
{ 86, 325, 9, 1, 11},
{ 87, 0, 15, 0, 15},
{ 88, 112, 11, 0, 11},
{ 89, 295, 9, 0, 9},
{ 90, 255, 9, 0, 9},
{ 95, 245, 9, 0, 9},
{ 97, 447, 7, 1, 9},
{ 98, 559, 7, 1, 9},
{ 99, 611, 6, 1, 8},
{ 100, 455, 7, 1, 9},
{ 101, 463, 7, 1, 9},
{ 102, 657, 4, 0, 4},
{ 103, 471, 7, 1, 9},
{ 104, 618, 6, 1, 8},
{ 105, 684, 1, 1, 4},
{ 106, 662, 3, 0, 3},
{ 107, 479, 7, 1, 8},
{ 108, 686, 1, 1, 3},
{ 109, 136, 11, 1, 13},
{ 110, 583, 6, 1, 8},
{ 111, 495, 7, 1, 9},
{ 112, 503, 7, 1, 9},
{ 113, 511, 7, 1, 9},
{ 114, 642, 4, 1, 5},
{ 115, 597, 6, 1, 8},
{ 116, 647, 4, 0, 4},
{ 117, 604, 6, 1, 8},
{ 118, 439, 7, 0, 7},
{ 119, 148, 11, 0, 11},
{ 120, 527, 7, 0, 7},
{ 121, 535, 7, 0, 7},
{ 122, 543, 7, 0, 7},
{ 153, 46, 13, 2, 12},
{ 169, 86, 12, 0, 12},
{ 186, 631, 5, 0, 5},
{ 188, 99, 12, 1, 13},
{ 189, 60, 12, 1, 13},
{ 190, 32, 13, 0, 13},
{ 0,0,0,0,0}
};

// Image Size: 86bytes x 16lines
static uint8_t Arial11Pixels[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x81,0x02,
0x07,0xe0,0x78,0x23,0xec,0x66,0x04,0x38,
0x40,0x7e,0x0c,0x08,0x40,0x48,0x02,0x00,
0x00,0x00,0x1e,0x03,0xc0,0x78,0x0f,0x8f,
0xe1,0x01,0x7f,0x10,0x10,0x00,0xff,0x04,
0x1f,0xe4,0x05,0x01,0x7f,0xc7,0xc4,0x05,
0xff,0x40,0x5f,0xc0,0x13,0xfc,0xfc,0x71,
0xfc,0x70,0x70,0x71,0x00,0x00,0x00,0x04,
0x00,0x01,0x00,0x70,0x00,0x00,0x00,0x78,
0x00,0x00,0x00,0x01,0x00,0x78,0x70,0x00,
0x10,0x00,0x00,0x20,0x10,0xe0,0x00,0x01,
0x18,0x8a,0x0a,0x0a,0x82,0x82,0x18,0x18,
0x88,0x40,0x8c,0x6a,0x08,0x44,0x80,0x81,
0x14,0x10,0x20,0x8c,0x06,0x00,0x00,0x00,
0x21,0x04,0x20,0x84,0x10,0x48,0x11,0x81,
0x40,0x90,0x10,0x00,0x02,0x0a,0x10,0x24,
0x04,0x82,0x40,0x08,0x24,0x04,0x10,0x40,
0x90,0x20,0x32,0x00,0x80,0x88,0x08,0x88,
0x88,0x89,0x00,0x00,0x00,0x04,0x00,0x01,
0x00,0x88,0x00,0x00,0x00,0xa4,0x00,0x00,
0x00,0x01,0x00,0x88,0x88,0x00,0x10,0x00,
0x00,0x20,0x7d,0x10,0x00,0x83,0x20,0x11,
0x0a,0x02,0x42,0x84,0x20,0x04,0x10,0x40,
0x8a,0xa2,0x10,0x44,0x81,0x3c,0x84,0x10,
0x11,0x0c,0x06,0x00,0x00,0x00,0x40,0x88,
0x11,0x02,0x20,0x28,0x09,0x41,0x40,0x50,
0x10,0x00,0x04,0x0a,0x10,0x14,0x04,0x82,
0x40,0x10,0x12,0x08,0x10,0x41,0x10,0x10,
0x52,0x00,0x81,0x04,0x09,0x05,0x05,0x05,
0x00,0x00,0x00,0x04,0x00,0x01,0x01,0x04,
0x00,0x00,0x01,0x24,0x00,0x00,0x00,0x01,
0x01,0x05,0x08,0x00,0x10,0x00,0x00,0x20,
0x11,0x10,0x00,0x85,0x20,0x11,0x0a,0x02,
0x42,0x84,0x43,0xa4,0x08,0x80,0x8a,0xa2,
0x10,0x45,0x02,0x42,0x44,0x20,0x11,0x0a,
0x0a,0xb9,0xc8,0x42,0x80,0x10,0x0a,0x01,
0x40,0x08,0x05,0x41,0x40,0x50,0x10,0x00,
0x04,0x0a,0x10,0x14,0x04,0x44,0x40,0x10,
0x02,0x08,0x10,0x42,0x10,0x10,0x92,0x01,
0x01,0x00,0x11,0x05,0x05,0x05,0x01,0x04,
0x78,0x74,0x70,0x75,0x05,0x04,0x71,0x70,
0x75,0x21,0x05,0x05,0xfc,0x21,0x70,0x04,
0x09,0x70,0x13,0xc8,0x47,0x2e,0x29,0x10,
0x2d,0xe9,0x78,0x91,0x0a,0x8a,0x44,0x44,
0x44,0x62,0x89,0x00,0x8a,0xa2,0x20,0x45,
0x02,0x40,0x44,0x40,0x0a,0x0a,0x0a,0xc6,
0x28,0x42,0x80,0x10,0x0a,0x01,0x40,0x08,
0x05,0x21,0x40,0x50,0x10,0x00,0x08,0x11,
0x10,0x24,0x04,0x28,0x40,0x08,0x02,0x08,
0x10,0x44,0x10,0x10,0x92,0x01,0xf1,0x70,
0x10,0x89,0x04,0x05,0x01,0x04,0x84,0x8c,
0x88,0x8d,0x09,0x04,0x89,0x88,0x8d,0x20,
0x89,0x04,0x08,0x21,0x88,0x04,0x19,0x88,
0x14,0x28,0x48,0xb1,0x29,0x10,0x30,0x81,
0x20,0xa0,0x8a,0x0a,0x44,0x44,0x88,0x22,
0x72,0x00,0x89,0x22,0x40,0x39,0x02,0x40,
0x44,0x40,0x04,0x09,0x12,0x84,0x24,0xa4,
0x80,0x10,0x0a,0x01,0x40,0x08,0x05,0x11,
0x40,0x90,0x10,0x00,0x10,0x11,0x1f,0xc7,
0xfc,0x28,0x7f,0x87,0x01,0x10,0x10,0x4c,
0x10,0x21,0x12,0x01,0x09,0x88,0x20,0x71,
0x04,0x09,0x00,0x89,0x05,0x05,0x05,0x05,
0x11,0x05,0x05,0x05,0x04,0xe0,0x51,0x08,
0x10,0x21,0x04,0x08,0x71,0x08,0x14,0x08,
0x50,0x21,0x00,0xe0,0x20,0x81,0x20,0xa0,
0x8a,0x0a,0x24,0x48,0x90,0x22,0x02,0x10,
0x00,0x00,0x4e,0x02,0x72,0x40,0x40,0x84,
0x0a,0x09,0x12,0x84,0x24,0xa4,0x87,0xd0,
0x0a,0x01,0x40,0x08,0x05,0x11,0x7f,0x10,
0x10,0x00,0x10,0x11,0x10,0x24,0x04,0x10,
0x40,0x00,0xe1,0x10,0x10,0x54,0x1f,0xc2,
0x13,0xf8,0x05,0x04,0x20,0x88,0x8c,0x11,
0x00,0x88,0x1d,0x05,0x05,0x05,0x21,0x05,
0x05,0x05,0x04,0x38,0x50,0x88,0x11,0xfd,
0x04,0x08,0x09,0x08,0x14,0x08,0x50,0x21,
0x00,0x00,0x20,0x81,0x20,0xa0,0x8a,0x0a,
0x28,0x28,0x90,0x42,0x04,0x30,0x00,0x00,
0x91,0x02,0x8a,0x42,0x41,0x0c,0x11,0x08,
0xa2,0x84,0x25,0x14,0x80,0x50,0x0a,0x01,
0x40,0x08,0x05,0x09,0x40,0x10,0x10,0x00,
0x20,0x3f,0x90,0x14,0x04,0x10,0x40,0x00,
0x11,0x10,0x10,0x62,0x10,0x84,0x12,0x00,
0x05,0x04,0x21,0x04,0x74,0x21,0x00,0x50,
0xe5,0x05,0xfd,0x05,0x61,0x05,0x05,0x05,
0x04,0x24,0x20,0x88,0x20,0x21,0x04,0x10,
0x05,0x08,0x13,0xc8,0x50,0x21,0x00,0x00,
0x20,0x81,0x20,0xa0,0x8a,0x0a,0x28,0x28,
0x90,0x42,0x08,0x50,0x00,0x01,0x01,0x04,
0x8a,0x3c,0x41,0x14,0x11,0x08,0xa2,0x84,
0x25,0x14,0x80,0x50,0x0a,0x01,0x40,0x08,
0x05,0x05,0x40,0x10,0x10,0x00,0x40,0x20,
0x90,0x14,0x04,0x10,0x40,0x00,0x10,0xa0,
0x10,0x41,0x10,0x47,0xfa,0x00,0x05,0x04,
0x21,0x04,0x04,0x21,0x00,0x51,0x05,0x05,
0x01,0x05,0x91,0x05,0x05,0x05,0x04,0x24,
0x50,0x50,0x40,0x21,0x04,0x20,0x05,0x0a,
0x10,0x28,0x50,0x21,0x00,0x07,0xa0,0x81,
0x20,0xa0,0x8a,0x0a,0x28,0x28,0x90,0x44,
0x08,0x90,0x00,0x02,0x06,0x04,0x89,0x00,
0x82,0x24,0x20,0x88,0xa2,0x84,0x25,0x14,
0x40,0x88,0x11,0x1b,0x20,0x28,0x09,0x05,
0x40,0x10,0x10,0x00,0x40,0x20,0x90,0x14,
0x04,0x10,0x40,0x10,0x10,0xa0,0x10,0x41,
0x10,0x40,0x12,0x01,0x05,0x04,0x41,0x05,
0x04,0x21,0x00,0x51,0x05,0x05,0x05,0x05,
0x11,0x05,0x05,0x05,0x05,0x24,0x50,0x50,
0x40,0x21,0x04,0x41,0x05,0x0a,0x10,0x28,
0x50,0x21,0x00,0x00,0x20,0x81,0x20,0xa0,
0x8a,0x0a,0x10,0x10,0x88,0xc8,0x10,0xf8,
0x00,0x02,0x08,0x08,0x88,0x81,0x04,0x3e,
0x40,0x48,0x42,0x84,0x22,0x08,0x21,0x04,
0x20,0x86,0x10,0x48,0x11,0x03,0x40,0x08,
0x20,0x00,0x80,0x40,0x50,0x24,0x04,0x10,
0x40,0x08,0x20,0x40,0x10,0x40,0x90,0x20,
0x12,0x00,0x88,0x88,0x40,0x88,0x88,0x01,
0x00,0x21,0x0c,0x8c,0x88,0x8d,0x08,0x88,
0x89,0x88,0x8c,0xa8,0x88,0x50,0x80,0x01,
0x88,0x81,0x89,0x0a,0x14,0x28,0xc8,0xa1,
0x00,0x00,0x20,0x81,0x20,0xa0,0x82,0x0a,
0x10,0x10,0x47,0x70,0x20,0x10,0x00,0x04,
0x1f,0x08,0x70,0x7e,0x08,0x04,0x80,0x28,
0x42,0x84,0x22,0x08,0x1e,0x03,0xc0,0x7b,
0x0f,0x8f,0xe1,0x01,0x40,0x07,0xc0,0x01,
0xff,0x40,0x5f,0xc4,0x04,0x10,0x7f,0xc7,
0xc0,0x40,0x10,0x40,0x50,0x10,0x12,0x00,
0x70,0x70,0x40,0x70,0x70,0x21,0xfc,0x20,
0xf4,0x74,0x70,0x75,0x04,0x70,0x71,0x70,
0x74,0x71,0x04,0x21,0xfc,0x01,0x71,0xfc,
0x71,0x09,0xe3,0xc7,0x47,0x21,0x00,0x00,
0x20,0xe1,0x20,0x91,0x2a,0xaa,0x00,0x00,
0x20,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x04,0x00,0x00,0x01,0x00,0x04,0x20,
0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x91,0x20,0x00,0x00,0x00,0x18,0x0c,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x08,
0x00,0x00,0x01,0x00,0x04,0x00,0x00,0x20,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x91,
0x20,0x00,0x00,0x00,0x07,0xf0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x07,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,
0x01,0x00,0x04,0x00,0x00,0xc0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x0a,0x00,0x00
};

static LargeFont* bigFont = NULL;

// bitmap is 688x15
LargeFont* CreateFontArial11()
{
	if(bigFont == NULL)
	{
		struct FontInfo fif = {
			Arial11Infos,		//struct CharacterInfo* CharacterDescriptors;
			Arial11Pixels,		//uint8_t* PixelData;
			16,					//int Height;     // number of scan lines
			86					//int Width;      // width in bytes of the data stream
		};
	    bigFont = new LargeFont(&fif);
	}
	return bigFont;
}