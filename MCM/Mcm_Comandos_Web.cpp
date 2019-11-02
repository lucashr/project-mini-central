//Mcm_Comandos_Web mini central meteorologica
#include "Mcm_Comandos_Web.h"

void Mcm_Comandos_Web::processaPorta(byte porta, byte posicao, WiFiClient cl, String URLValue){
	 
	static boolean LED_status = 0;
    String cHTML;

    cHTML = "P";
    cHTML += porta;
    cHTML += "=";
    cHTML += porta;
        
    if (URLValue.indexOf(cHTML) > -1) { 
       LED_status = HIGH;
    } else {
       LED_status = LOW;
    }
    digitalWrite(porta, LED_status);
        
    cl.print("<input type=\"checkbox\" name=\"P");
    cl.print(porta);
    cl.print("\" value=\"");
    cl.print(porta);
    
    cl.print("\"");

    cl.print(" id=\"pino");           //<------NOVO
    cl.print(porta);
    cl.print("\"");
    
    if (LED_status) { 
        cl.print(" checked ");
    }
    
    cl.print(">Porta ");
    cl.print(porta);

    cl.println();
}
