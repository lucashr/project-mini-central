//Relogio mini central meteorologica

#ifndef Mcm_RTC_DS1307_H
#define Mcm_RTC_DS1307_H	
#include <Arduino.h>
#include <Wire.h>

#define ENDERECO_RTC 0x68

class Mcm_RTC_DS1307
{

	public:
		String mostraRelogio();
		void selecionaDataHora();
		byte converteParaBCD(byte val);
		byte converteParaDecimal(byte val);
			
	private:
		byte posicaoMemGravacao = 0x00;
};

#endif
