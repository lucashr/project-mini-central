//Mcm_Pagina_Completa mini central meteorologica
#include "Mcm_Pagina_Completa.h"

void Mcm_Pagina_Completa::paginaWeb(WiFiClient client){
	byte qtdePinosAnalogicos;
	byte pinosAnalogicos;
	
	if (client) { 
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) { 
                char c = client.read(); 
                HTTP_req += c;  
                
                if (c == '\n' && currentLineIsBlank ) { 

                    if ( mainPageRequest(&HTTP_req) ) {
                        URLValue = getURLRequest(&HTTP_req);
                        Serial.println(HTTP_req);
                                                 
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");              //<------ ATENCAO
                        client.println();
                        
                        //Conteudo da Página HTML
                        client.println("<!DOCTYPE html>");
                        client.println("<html>");

                        
                        client.println("<head>");
                        client.println("<title>Arduino via WEB</title>");

                        client.println("<script>");
                        client.println("function LeDadosDoArduino() {");
                        client.println("nocache = \"&nocache=\" + Math.random() * 1000000;");
                        client.println("var request = new XMLHttpRequest();");
                        client.println("var posIni;");
                        client.println("var valPosIni;");
                        client.println("var valPosFim;");
                        client.println("request.onreadystatechange = function() {");
                        client.println("if (this.readyState == 4) {");
                        client.println("if (this.status == 200) {");
                        client.println("if (this.responseText != null) {");

                        for (int nL=0; nL < qtdePinosAnalogicos; nL++) {                                                    //<-------NOVO
                            
                            client.print("posIni = this.responseText.indexOf(\"PA");
                            client.print(pinosAnalogicos);
                            client.println("\");"); 
                            client.println("if ( posIni > -1) {");
                            client.println("valPosIni = this.responseText.indexOf(\"#\", posIni) + 1;");
                            client.println("valPosFim = this.responseText.indexOf(\"|\", posIni);");
                            client.print("document.getElementById(\"pino");
                            client.print(pinosAnalogicos);
                            client.print("\").innerHTML = \"Porta ");
                            client.print(pinosAnalogicos);
                            client.print(" - Valor: \" + this.responseText.substring(valPosIni, valPosFim);");
                            client.println("}");
                        }
                          
                        client.println("}}}}");
                        client.println("request.open(\"GET\", \"solicitacao_via_ajax\" + nocache, true);");
                        client.println("request.send(null);");
                        client.println("setTimeout('LeDadosDoArduino()', 1000);");
                        client.println("}");
                        client.println("</script>");
                        
                        client.println("</head>");

                        client.println("<body onload=\"LeDadosDoArduino()\">");                      //<------ALTERADO                    
                        client.println("<h1>PORTAS EM FUN&Ccedil;&Atilde;O ANAL&Oacute;GICA</h1>");

                        for (int nL=0; nL < qtdePinosAnalogicos; nL++) {

                            client.print("<div id=\"pino");                         //<----- NOVO
                            client.print(pinosAnalogicos);
                            client.print("\">"); 
                                                         
                            client.print("Porta ");
                            client.print(pinosAnalogicos);
                            client.println(" - Valor: ");
                               
                            client.print("sensorUmidade");
                            client.println("</div>");                               //<----- NOVO
                               
                            client.println("<br/>");                             
                        }              
                        
                        client.println("<br/>");
                        client.println("<button type=\"submit\">Envia para o ESP8266</button>");
                        client.println("</form>");                      
                        
                        client.println("</body>");
                        
                        client.println("</html>");

                    
                    } else if (HTTP_req.indexOf("solicitacao_via_ajax") > -1) {     //<----- NOVO

                        Serial.println(HTTP_req);

                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");      
                        client.println();                      

                        for (int nL=0; nL < qtdePinosAnalogicos; nL++) {
                            lePortaAnalogica(pinosAnalogicos, qtdePinosAnalogicos, client);                            
                        }
                            
                    } else {

                        Serial.println(HTTP_req);
                        client.println("HTTP/1.1 200 OK");
                    }
                    HTTP_req = "";    
                    break;
                }
                
                if (c == '\n') {
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    currentLineIsBlank = false;
                }
            }
        } 
        delay(1);     
        client.stop(); 
    }
}


String Mcm_Pagina_Completa::getURLRequest(String *requisicao){
	int inicio, fim;
    String retorno;

    inicio = requisicao->indexOf("GET") + 3;
    fim = requisicao->indexOf("HTTP/") - 1;
    retorno = requisicao->substring(inicio, fim);
    retorno.trim();

    return retorno;
}




bool Mcm_Pagina_Completa::mainPageRequest(String *requisicao){
	String valor;
    bool retorno = false;

    valor = getURLRequest(requisicao);
    valor.toLowerCase();

    if (valor == "/") {
    	retorno = true;
    }

    if (valor.substring(0,2) == "/?") {
        retorno = true;
    }  

    if (valor.substring(0,10) == "/index.htm") {
        retorno = true;
    }  

    return retorno;
}
