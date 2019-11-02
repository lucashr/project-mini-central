//MCM mini central meteorologica

//--------- Bibliotecas auxiliares ---------//
#ifndef MCM_H
#define MCM_H

//#include <Arduino.h>                    // Para funcionalidades do Arduino
//#include <Wire.h>                       // Para comunicação com o arduino, ESP12E e o RTC via i2c
//#include <Adafruit_BMP085.h>            // Para uso das funções do sensor de pressão BMP180
//#include <DHT.h>                        // Para uso das funções do sensor DHT22
#include <SPI.h>                        // Para comunicação do ESP12E com o modulo microsd
//#include <SD.h>                         // Para uso das funções do datalloger
//#include <ESP8266WiFi.h>

#include <DHT.h>
#include "Mcm_Func_Envio_Dados_I2C.h"       // Para envio de dados via I2C.
#include "Mcm_RTC_DS1307.h"                 // Para funcoes do CI DS1307
#include "Mcm_Datalogger.h"                 // Para funcoes de gravacao no cartao SD
#include "Mcm_BMP180.h"                     // Para leitura dos dados geraos pelo sensor de pressao
#include "Mcm_UVM30A.h"                     // Para leitura dos dados geraos pelo sensor de indice UV
#include "Mcm_Comandos_Web.h"               // Para acionamento em geral via comandos Web
#include "Mcm_Leitura_Variaveis_Sensores.h" // Para letura de variaveis e atualização da pagina Web
#include "Mcm_Pagina_Completa.h"            // Contem toda pagina Web mais o javascript
#include "Mcm_Requisicoes_Web.h"            // Funções de tratamento de requisições Web

class MCM
{
	public:
		
		
	private:

};

#endif
