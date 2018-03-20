#include "I2cCom.h"
#include <Wire.h>

static int didBegin = false;
static bool diagnostics = false;

// baseAddr is the i2c slave address
I2CHelper::I2CHelper(uint8_t baseAddr)
{
	_i2caddr = baseAddr;
	if(baseAddr != 0 && !didBegin)
	{
		// the OLED supports 400K but not the PIC afaik
		// this clock speed must be set before Wire.begin is called
		Wire.setClock(400000);  // this is the default nowadays. it was 400k orig
		// at 100KHz it takes .1S to update the screen
//		Wire.begin(int sdaPin, int sclPin, uint32_t frequency);	// join as master
//		Wire.begin(4, 15, 100000);	// join as master, connect to display
		Wire.begin();	// join as master
		didBegin = true;
	}
}

uint8_t I2CHelper::SendBuffer(uint8_t* data, uint8_t length, uint8_t prelude)
{
	Wire.beginTransmission(_i2caddr);	// send to this slave
	if( prelude != PRELUDE_NONE)
	{
		Wire.write(prelude);
	}
	byte ran = Wire.write(data, length);		// how do we trap an error here?
	Wire.endTransmission();
	if(diagnostics && (ran != length))
	{
		Serial.println(String(_i2caddr) + ": Sent " + String(length) + "bytes. First =" + String(data[0]) + " Returned: " + String(ran) + ".");
	}
	return ran;
}

uint8_t I2CHelper::SendString(String& outp, uint8_t prelude)
{
	// I2C
	// send a bunch of data in one xmission
	Wire.beginTransmission(_i2caddr);
	if( prelude != PRELUDE_NONE)
	{
		Wire.write(prelude);
	}

	uint8_t ran = Wire.write(outp.c_str());		// how do we trap an error here?
	Wire.endTransmission();
	if(diagnostics && (ran != outp.length()))
	{
		Serial.println(String(_i2caddr) + ": Sent " + outp + " Returned: " + String(ran) + ".");
	}
	return ran;
}

// this should be interrupt-driven which is directly supported by Wire
String I2CHelper::ReadString(uint8_t bsize)
{
	Wire.requestFrom(_i2caddr, bsize);    // request bsize bytes from slave device
	String rslt = "";
    while(Wire.available())
	{						   // slave may send less than requested
      char c = Wire.read();    // receive a byte as character
	  rslt += c;
    }
	if(diagnostics)
	{
		// rslt and length
		Serial.println("Wire read: '" + rslt + "' (" + String(rslt.length() + ")."));
	}
	return rslt;
}

// this should be interrupt-driven which is directly supported by Wire
uint8_t I2CHelper::ReadBuffer(uint8_t* data, uint8_t length)
{
	uint8_t i = 0;
	if(length != 0)
	{
		Wire.requestFrom(_i2caddr, length);    // request bsize bytes from slave device
		//delay(300);
	    while(Wire.available() && i < length)
		{						   // slave may send less than requested
	      uint8_t c = Wire.read();    // receive a byte as character
		  data[i++] = c;
	    }
		if(diagnostics)
		{
			// rslt and length
			Serial.println("Wire read buffer: " + String(i) + " bytes.");
		}
	}
	else
	{
		// Serialpt("Attempt to read 0 bytes");
	}
	return i;
}
