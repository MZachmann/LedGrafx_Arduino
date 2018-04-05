#ifndef LED_GRAFX_H
#define LED_GRAFX_H

class OledDisplay;

class LedGrafx
{
	public:
		LedGrafx();
		virtual ~LedGrafx();

		OledDisplay* Oled() { return _Oled; }
		void SetupGrafx(bool Enable);
		void PrintOledMessage(String heading, String text, String t2="");
		bool HasGrafx();
		void DimGrafx(bool doDim);
		void SendGrafxCmd(uint8_t cmd);
	private:
		OledDisplay* _Oled;
};


#endif