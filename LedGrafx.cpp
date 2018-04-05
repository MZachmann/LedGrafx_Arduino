// ESP32 Heltec LoRa board
#include "Arduino.h"
#define USE_SH1106
#include "LedGrafx.h"
//#include "Utility.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_SH1106.h"
#include "LargeFont.h"
#include "FontArial48.h"
#include "FontArial11.h"
#include "FontArial28.h"

static bool _HasGrafx = false;

#define I2C_ADDR 0x3C

#ifdef FLIP_DISPLAY
#define YOFF_INDIC 48
#define YOFF_TEMP 2
#else
#define YOFF_INDIC 0
#define YOFF_TEMP 22
#endif

bool diagnostics = false;
// Singleton instance of the radio driver
// static String PROG_NAME("Remote");
// static ASerial _Aserial(PROG_NAME);

// the various objects we use to display and read stuff
LedGrafx::LedGrafx()
{
	_Oled = new OledDisplay(16);	// the reset pin. ignored
}

LedGrafx::~LedGrafx()
{
	delete _Oled;
}

bool LedGrafx::HasGrafx()
{
    return _HasGrafx;
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

    _Oled->clearDisplay();
    LargeFont* tempFont = CreateFontArial11();
    _Oled->SetFont(tempFont);
    _Oled->setTextSize(1);
    _Oled->setTextWrap(true);
    _Oled->setTextColor(WHITE);
    _Oled->setCursor(0, YOFF_INDIC);
    _Oled->print(heading);
    _Oled->setCursor(0, YOFF_TEMP);
    _Oled->print(text);
	if(t2.length() > 0)
	{
		_Oled->setCursor(0, YOFF_TEMP*2);
		_Oled->print(t2);
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

    _Oled->begin(SSD1306_SWITCHCAPVCC, I2C_ADDR);  // initialize with the I2C addr 0x3D (for the 128x64)
    // _Oled->display();
    delay(200);
    _Oled->clearDisplay();
    PrintOledMessage("hello", "me");
    _Oled->display();
}

void LedGrafx::DimGrafx(bool doDim)
{
	if(_HasGrafx)
	{
		_Oled->dim(doDim);
	}
}

void LedGrafx::SendGrafxCmd(uint8_t cmd)
{
	_Oled->SendCommand(cmd);
}