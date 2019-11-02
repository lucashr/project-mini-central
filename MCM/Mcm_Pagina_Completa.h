//Mcm_Pagina_Completa mini central meteorologica

#ifndef Mcm_Pagina_Completa_H
#define Mcm_Pagina_Completa_H	
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Mcm_Pagina_Completa
{
	
	WiFiServer server(int); //Shield irá receber as requisições das páginas (o padrão WEB é a porta 80)
	
	Mcm_Pagina_Completa(WiFiServer server){
		WiFiClient client = server.available();
	}
	
	
	public:
		void paginaWeb(WiFiClient client);
		void processaPorta(byte porta, byte posicao, WiFiClient cl); 
		void lePortaAnalogica(byte porta, byte posicao, WiFiClient cl);
		String getURLRequest(String *requisicao);
		bool mainPageRequest(String *requisicao);
		
	private:
		String HTTP_req; 
		String URLValue;
		
		
	
};

#endif
