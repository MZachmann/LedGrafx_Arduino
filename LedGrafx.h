#ifndef LED_GRAFX_H
#define LED_GRAFX_H

#define USE_SH1106

class OledDisplay;

class LedGrafx
{
	public:
		LedGrafx();
		virtual ~LedGrafx();

		OledDisplay* Oled();
		void SetupGrafx(bool Enable);
		void PrintTextAt(const char* data, int x, int y, bool clear = false);
		void PrintTextAt(const String& data, int x, int y, bool clear = false);
		void PrintMin(const String& data, int maxlength);
		void PrintOledMessage(const String& heading, const String& text, const String& t2="");
		bool HasGrafx();
		void DimGrafx(bool doDim);
		void SendGrafxCmd(uint8_t cmd);
	private:
		OledDisplay* _Oled;
};


#endif