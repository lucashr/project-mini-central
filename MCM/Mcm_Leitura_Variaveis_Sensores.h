//Mcm_Leitura_Variaveis_Sensores mini central meteorologica

#ifndef Mcm_Leitura_Variaveis_Sensores_H
#define Mcm_Leitura_Variaveis_Sensores_H	
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Mcm_Leitura_Variaveis_Sensores
{
	public:
		void lePortaAnalogica(byte porta, byte posicao, WiFiClient cl, float sensorUmidade);

	private:
	
};

#endif
