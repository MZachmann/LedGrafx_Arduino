#ifndef I2C_COM_H
#define I2C_COM_H

 #include "Arduino.h"

// a way to not prelude a byte
#define PRELUDE_NONE 0xfe

// communicate with the on-board pic

class I2CHelper
{
private:
	uint8_t _i2caddr;
public:
	uint8_t SendString(String& outp, uint8_t prelude = PRELUDE_NONE);				// Send a char string
	uint8_t SendBuffer(uint8_t* src, uint8_t length, uint8_t prelude = PRELUDE_NONE);		// send a byte buffer (max 32)
	String ReadString(uint8_t amount);				// read a string
	uint8_t ReadBuffer(uint8_t* dest, uint8_t length);		// read up to length bytes. returns count read
	I2CHelper(uint8_t baseAddr);
};

#endif
