//Mcm_Requisicoes_Web mini central meteorologica

#ifndef Mcm_Requisicoes_Web_H
#define Mcm_Requisicoes_Web_H	
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Mcm_Requisicoes_Web
{
	public:
		String getURLRequest(String *requisicao);
		bool mainPageRequest(String *requisicao);


	private:
	
};

#endif
