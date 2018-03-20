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
OledDisplay     myOled(16);

bool HasGrafx()
{
    return _HasGrafx;
}

// ------------------------------------------------------------------------
// Print a message on the Oled Display
// ------------------------------------------------------------------------
void PrintOledMessage(String heading, String text, String t2)
{
    if(!HasGrafx())
    {
        return;
    }

    myOled.clearDisplay();
    LargeFont* tempFont = CreateFontArial11();
    myOled.SetFont(tempFont);
    myOled.setTextSize(1);
    myOled.setTextWrap(true);
    myOled.setTextColor(WHITE);
    myOled.setCursor(0, YOFF_INDIC);
    myOled.print(heading);
    myOled.setCursor(0, YOFF_TEMP);
    myOled.print(text);
	if(t2.length() > 0)
	{
		myOled.setCursor(0, YOFF_TEMP*2);
		myOled.print(t2);
	}
    myOled.display();       // update the display
}

// SetupGrafx - allow passing a false for quick non-use

void SetupGrafx(bool Enable)
{
    _HasGrafx = Enable;
    if(!Enable)
    {
        return;
    }

    myOled.begin(SSD1306_SWITCHCAPVCC, I2C_ADDR);  // initialize with the I2C addr 0x3D (for the 128x64)
    // myOled.display();
    delay(200);
    myOled.clearDisplay();
    PrintOledMessage("hello", "me");
    myOled.display();
}

