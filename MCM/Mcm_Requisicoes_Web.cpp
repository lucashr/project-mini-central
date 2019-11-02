//Mcm_Requisicoes_Web mini central meteorologica
#include "Mcm_Requisicoes_Web.h"

String Mcm_Requisicoes_Web::getURLRequest(String *requisicao){
	int inicio, fim;
    String retorno;

    inicio = requisicao->indexOf("GET") + 3;
    fim = requisicao->indexOf("HTTP/") - 1;
    retorno = requisicao->substring(inicio, fim);
    retorno.trim();

    return retorno;
}

bool Mcm_Requisicoes_Web::mainPageRequest(String *requisicao){
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
