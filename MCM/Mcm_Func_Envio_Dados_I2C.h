//Mcm_Func_Envio_Dados_I2C mini central meteorologica

#ifndef Mcm_Func_Envio_Dados_I2C_H
#define Mcm_Func_Envio_Dados_I2C_H	
#include <Arduino.h>
#include <Wire.h>
#include <cstring>

class Mcm_Func_Envio_Dados_I2C
{
	public:
		String convertByte(float temperatura, float umidade, float pressaoAtm);
		void enviaDadosI2c(String vetDados);
		
	private:
		byte Tbyte1, Tbyte2, Ubyte1, Ubyte2, Pbyte1, Pbyte2;
		int uv, hs, mi, se, dm, ms, an, aux,aux2,aux3,patm;

};

#endif
