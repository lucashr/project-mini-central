//Datalogger mini central meteorologica
#include "Mcm_Datalogger.h"

//---------- Insere cabecalho no arquivo no cartao SD ----------//
/*void Mcm_Datalogger::cabecalho(String cabecalho, File dataFile)
{
   if(flag_cabecalho)
   {
     dataFile.println(cabecalho);
     flag_cabecalho = false;   //Flag usada para execucao do cabecalho apenas uma vez
   }
}*/

//---------- Abre arquivo no catao SD modo escrita ----------//
/*File Mcm_Datalogger::abreArquivo(String nomeArqMaisExtensao)
{
	File dataFile;
	// Abre o arquivo Log.txt no cart�o microsd
    dataFile = SD.open(nomeArqMaisExtensao, FILE_WRITE);
    return dataFile;
}*/

//---------- Escreve no cartao SD ----------//
void Mcm_Datalogger::escreveNoCartao(String nomeArqMaisExtensao, String linhaDeSaida)
{
	// Abre o arquivo Log.txt no cart�o microsd
	File dataFile = SD.open(nomeArqMaisExtensao, FILE_WRITE);
	
    // Verifica se o arquivo esta disponivel
    if (dataFile) {
      dataFile.println(linhaDeSaida); // Escreve no cartao microsd
      dataFile.close();               // Fecha o arquivo no cart�o microsd
    }
    // Caso o arquivo Log.txt n�o esteja disponivel no cart�o exibe a seguinte frase
    else {
      Serial.println("Erro ao abrir o arquivo"); //Escreve na serial 
    }
}

//---------- Verifica cartao SD (Setup) ----------//
void Mcm_Datalogger::inicializaCartaoSD(byte chipSelect)
{
	//chipSelect = pino de selecao do cartao SD
	Serial.print("Inicializando cart�o SD...");
	if (!SD.begin(chipSelect)) {
	  Serial.println("Cart�o danificado ou n�o esta inserido");
	  return;
	}
	Serial.println("Cart�o inicializado");
}
