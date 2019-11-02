//SNS_UVM30A mini central meteorologica
#include "Mcm_BMP180.h"

float Mcm_BMP180::lerPressaoAtm(Adafruit_BMP085 bmp180)
{	  
  float p = bmp180.readPressure() / 101325.0; 

  return(p);
}
