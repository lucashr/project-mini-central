//Mcm_Datalogger mini central meteorologica

#ifndef Mcm_Datalogger_H
#define Mcm_Datalogger_H	
#include <Arduino.h>
#include <SD.h>

class Mcm_Datalogger
{
	
	public:
		
		void inicializaCartaoSD(byte chipSelect);     //chipSelect = pino de selecao do cartao SD
		void cabecalho(String cabecalho, File datafile);             //Cabecalho a ser gerado
		File abreArquivo(String nomeArqMaisExtensao); //Faz a abertura do arquivo
		void escreveNoCartao(String nomeArqMaisExtensao, String linhaDeSaida);    //Verifica se o arquivo esta disponivel	
			
	private:
		bool flag_cabecalho = true;	
	
};

#endif
