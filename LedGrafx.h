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
		void PrintOledMessage(String heading, String text, String t2="");
		bool HasGrafx();
		void DimGrafx(bool doDim);
		void SendGrafxCmd(uint8_t cmd);
	private:
		OledDisplay* _Oled;
};


#endif