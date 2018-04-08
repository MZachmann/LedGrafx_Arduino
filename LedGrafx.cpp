// ESP32 Heltec LoRa board
#include "Arduino.h"
#include "LedGrafx.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_SH1106.h"
#include "LargeFont.h"
#include "FontArial11.h"
#include <SerialWrap.h>

static bool _HasGrafx = false;

#define I2C_ADDR 0x3C

#ifdef FLIP_DISPLAY
#define YOFF_INDIC 48
#define YOFF_TEMP 2
#else
#define YOFF_INDIC 0
#define YOFF_TEMP 22
#endif

static OledDisplay _LocalOled(16);	// allocating this via new () fails miserably ?

// the various objects we use to display and read stuff
LedGrafx::LedGrafx() : _Oled(NULL)
{
}

LedGrafx::~LedGrafx()
{
	// delete _Oled; now static
}

bool LedGrafx::HasGrafx()
{
    return _HasGrafx;
}

OledDisplay* LedGrafx::Oled() { return _Oled; }

void LedGrafx::PrintTextAt(String data, int x, int y)
{
    LargeFont* tempFont = CreateFontArial11();
    _Oled->SetFont(tempFont);
    _Oled->setTextSize(1);
    _Oled->setTextWrap(true);
    _Oled->setTextColor(WHITE);
    _Oled->setCursor(x, y);
    _Oled->print(data);
}

// ------------------------------------------------------------------------
// Print a message on the Oled Display
// ------------------------------------------------------------------------
void LedGrafx::PrintOledMessage(String heading, String text, String t2)
{
    if(!HasGrafx())
    {
        return;
    }

	_Oled = &_LocalOled;
    _Oled->clearDisplay();
    LargeFont* tempFont = CreateFontArial11();
    _Oled->SetFont(tempFont);
    _Oled->setTextSize(1);
    _Oled->setTextWrap(true);
    _Oled->setTextColor(WHITE);
    _Oled->setCursor(0, YOFF_INDIC);
    _Oled->print(heading.substring(0,min(12,heading.length())));
    _Oled->setCursor(0, YOFF_TEMP);
    _Oled->print(text.substring(0,min(12,text.length())));
	if(t2.length() > 0)
	{
		_Oled->setCursor(0, YOFF_TEMP*2);
		_Oled->print(t2.substring(0,min(10,t2.length())));
	}
    _Oled->display();       // update the display
}

// SetupGrafx - allow passing a false for quick non-use

void LedGrafx::SetupGrafx(bool Enable)
{
    _HasGrafx = Enable;
    if(!Enable)
    {
        return;
    }

	_Oled = &_LocalOled;
    _Oled->begin(SSD1306_SWITCHCAPVCC, I2C_ADDR);  // initialize with the I2C addr 0x3D (for the 128x64)
    delay(200);
    _Oled->clearDisplay();
    PrintOledMessage("hello", "me");
    _Oled->display();
}

void LedGrafx::DimGrafx(bool doDim)
{
	if(_HasGrafx && (_Oled != NULL))
	{
		_Oled->dim(doDim);
	}
}

void LedGrafx::SendGrafxCmd(uint8_t cmd)
{
	if(_HasGrafx && (_Oled != NULL))
	{
		_Oled->SendCommand(cmd);
	}
}