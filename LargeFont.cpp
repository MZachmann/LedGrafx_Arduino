// ---------------------------------------------------------------------
// to get a large font...
// first use bitmap font generator (bmfont64) from http://www.angelcode.com/products/bmfont/
// select the chars you want and create a long bitmap (2048x512). Airal, Ansi, 48px high, no kerning, render from truetype
// export the glyph into the A field (8 bits) as png
// doing Export to bitmap will create two files. One metadata i use the fnt suffix for and one glyph data as png
// then run the methods in BmptoHex.py to create data structures from the png and the fnt output
// essentially convert the metadata to a list of CharacterDescriptors
// and crop the bitmap top/bottom/right then print it as hex
// ---------------------------------------------------------------------
// These methods are pretty simple:
//  (a) construct the font and then create a 256 character lookup table
//  (b) get a pixel from the character glyph
#include "Arduino.h"
#include "LargeFont.h"

static bool diagnoseFont = false;

// print to the serial device for debugging
static void Serialptf(const char* view)
{
    if(diagnoseFont)
    {
        Serial.println(view);
    }
}

// empty constructor, must call AttachInfo next
LargeFont::LargeFont()
{
    CharacterDescriptors = NULL;
    PixelData = NULL;
    Width = 0;
    Height = 0;
}

// Constructor
LargeFont::LargeFont(const struct FontInfo* pFif)
{
    CharacterDescriptors = pFif->CharacterDescriptors;
    PixelData = pFif->PixelData;
    Width = pFif->Width;
    Height = pFif->Height;
    CreateCharLookup();
    Serialptf("Created Char Lookup A");
}

// not really used by the code
LargeFont::LargeFont(int width, int height, const struct CharacterInfo* chardesc, const uint8_t* Pixels)
{
    CharacterDescriptors = chardesc;
    PixelData = Pixels;
    Width = width;
    Height = height;
    CreateCharLookup();
    Serialptf("Created Char Lookup B");
}

void LargeFont::AttachInfo(const struct FontInfo* pFif)
{
    CharacterDescriptors = pFif->CharacterDescriptors;
    PixelData = pFif->PixelData;
    Width = pFif->Width;
    Height = pFif->Height;
    CreateCharLookup();
    Serialptf("Attached Char Lookup");
}

// for debugging print a CharacterInfo verbose
void PrettyDescriptor(const struct CharacterInfo* pinfo)
{
    if(diagnoseFont)
    {
        char js[220];
        sprintf(js, "Descriptor: %c Xpos=%d, Width=%d, Offset=%d, Advance=%d", pinfo->Thechar, pinfo->Xpos, (int)pinfo->Width, (int)pinfo->Offset, (int)pinfo->Advance);
        Serialptf(js);
    }
}

// create the 256 element lookup table for the CharacterInfo descriptor list (which is sparse)
void LargeFont::CreateCharLookup()
{
    Serialptf("Creating Char Lookup");
    int i;
    for(i=0; i<256; i++)
    {
        int j = 0;
        // the one with Thechar==0 is the end of the vector and the default
        while( CharacterDescriptors[j].Thechar != 0)
        {
            if(i == CharacterDescriptors[j].Thechar)
            {
                if(diagnoseFont)
                {
                    char js[220];
                    sprintf(js, "Found descriptor for %c at %d", (char)i, (int)j);
                    PrettyDescriptor(CharacterDescriptors+j);
                    Serialptf(js);
                }
                break;
            }
            j++;
        }
        CharacterLookup[i] = &CharacterDescriptors[j];
    }
}

// for debugging print to serial the pixel request
void LargeFont::PrintGetPixel(unsigned char c, bool value, int x, int y) const
{
    if(diagnoseFont)
    {
        char rs[200];
        sprintf(rs, "Calling getpixel: %c at %d:%d was %c", c, x, y, value ? '1' : '0');
        Serialptf(rs);
    }
}

// Get a pixel for this character c at (x,y)
bool LargeFont::GetPixel(unsigned char c, uint8_t x, uint8_t y) const
{
    bool rslt = false;
    auto cinfo = CharacterLookup[c];
    PrettyDescriptor(cinfo);
    int dx = x - cinfo->Offset;
    int fontWidth = Width;  // width in bytes
    // now we are within the actual pixel data
    if(dx >= 0 && dx < cinfo->Width)
    {
        int xoff = dx + cinfo->Xpos;        // relative to entire bitmap
        int byteoff = xoff/8;                 // which byte of the data
        int xremain = xoff - byteoff * 8;   // pixels left over
        uint8_t bvalue = PixelData[byteoff + y*fontWidth];
        if(diagnoseFont)
        {
            char spr[200];
            sprintf(spr, "Pixel data: char=%c at %d,%d xval=%d 0x%02x offset %d at %d remain %d", c, (int)x, (int)y, dx, bvalue, (byteoff + y*fontWidth), xoff, xremain);
            Serialptf(spr);
        }
        if(xremain == 0)
        {
            rslt = 0x80 & bvalue;
        }
        else
        {
            rslt = (0x80 >> xremain) & bvalue;
        }
    }
    PrintGetPixel(c, rslt, x, y);
    return rslt;
}


// Get a pixel line for this character c at (x,y) optimized
bool LargeFont::GetPixelLine(unsigned char* pc, unsigned char c, uint8_t y) const
{
    auto cinfo = CharacterLookup[c];
    // int dx = x - cinfo->Offset;
    // now we are within the actual pixel data
    int cwidth = cinfo->Width;
    int xoff = cinfo->Xpos;
    int byteoff = xoff / 8;
    uint8_t xremain = 0x80 >> (xoff - byteoff * 8);
    byteoff +=   y * Width;         // move to nth scan line
    for(int dx = 0; dx < cwidth; dx++)
    {
        // int xoff = dx + cinfo->Xpos;        // relative to entire bitmap
        // int byteoff = xoff/8;               // which byte of the data
        // int xremain = xoff - byteoff * 8;   // pixels left over
        pc[dx] = xremain & PixelData[byteoff];
        xremain = xremain >> 1;
        if(xremain == 0)
        {
            xremain = 0x80;
            byteoff++;
        }
    }
    return cwidth;
}

int LargeFont::GetWidth(unsigned char c) const
{
    auto cinfo = CharacterLookup[c];
    return cinfo->Width;  // how much to move for each character
}

int LargeFont::GetOffset(unsigned char c) const
{
    auto cinfo = CharacterLookup[c];
    return cinfo->Offset;  // how much to move for each character
}

int LargeFont::GetAdvance(unsigned char c) const
{
    auto cinfo = CharacterLookup[c];
    return cinfo->Advance;  // how much to move for each character
}

int LargeFont::GetHeight() const
{
    return Height;
}
