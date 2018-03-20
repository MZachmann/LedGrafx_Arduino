#ifndef LED_GRAFX_H
#define LED_GRAFX_H
void SetupGrafx(bool Enable);
void PrintOledMessage(String heading, String text, String t2="");
bool HasGrafx();
#endif