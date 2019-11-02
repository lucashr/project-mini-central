//Mcm_BMP180 mini central meteorologica

#ifndef Mcm_BMP180_H
#define Mcm_BMP180_H	
#include <Arduino.h>
#include <Adafruit_BMP085.h>

class Mcm_BMP180
{
	public:
		float lerPressaoAtm(Adafruit_BMP085 p);

	private:
	
};

#endif
