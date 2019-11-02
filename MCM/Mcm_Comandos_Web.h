//Mcm_Comandos_Web mini central meteorologica

#ifndef Mcm_Comandos_Web_H
#define Mcm_Comandos_Web_H	
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Mcm_Comandos_Web
{
	public:
		void processaPorta(byte porta, byte posicao, WiFiClient cl, String URLValue);


	private:
	
};

#endif
