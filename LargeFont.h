#ifndef _LARGEFONT_H
#define _LARGEFONT_H

#include "../application.h"

// for each character here's what we care about
struct CharacterInfo
{
    char Thechar;               // the character
    int Xpos;                   // pixel where it starts in the image
    unsigned char Width;        // width of char glyph in pixels
    unsigned char Offset;       // left blank space in pixels when drawing it
    unsigned char Advance;      // total width of char in pixels when printed
};

// this is the structure used to initialize the large font
struct FontInfo
{
	struct CharacterInfo* CharacterDescriptors;    // array of character descriptors for this font. terminated with Thechar==0 entry
	uint8_t* PixelData;   // a stream of the pixel data
	int Height;           // number of scan lines
	int Width;            // width in bytes of the data stream
};

// This draws the font on screen
class LargeFont
{
private:
    // the FontInfo information
    struct CharacterInfo* CharacterDescriptors;
    uint8_t* PixelData;
    int Height;     // number of scan lines
    int Width;      // width in bytes of the data stream
public:
    bool GetPixel(unsigned char c, uint8_t x, uint8_t y);           // read a pixel at x,y for character c
    bool GetPixelLine(unsigned char* pc, unsigned char c, uint8_t y);    // read a line of pixels at x,y, put into *pc
    void PrintGetPixel(unsigned char c, bool value, int x, int y);  // for diagnostics print the pixel value
    int  GetWidth(unsigned char c);         // return character width in pixels
    int  GetOffset(unsigned char c);         // return character width in pixels
    int  GetAdvance(unsigned char c);         // return character width in pixels
	int  GetHeight();                       // get height of font (fixed)
	LargeFont(int Width, int Height, struct CharacterInfo* chardesc, uint8_t* Pixels);
    LargeFont(const struct FontInfo* pFif);
private:
    struct CharacterInfo* CharacterLookup[256]; // lookup table for each character's info
    void CreateCharLookup();                    // on construction build the lookup table
};

#endif
