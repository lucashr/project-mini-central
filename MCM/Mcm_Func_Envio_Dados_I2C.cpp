//Mcm_Func_Envio_Dados_I2C mini central meteorologica
#include "Mcm_Func_Envio_Dados_I2C.h"

String Mcm_Func_Envio_Dados_I2C::convertByte(float temperatura, float umidade, float pressaoAtm)
{	
	//Ajustando o n�mero antes da v�rgula para vari�veis float positivas 
	  
	//Temperatura
	//Ajustando o n�mero antes da v�rgula
	aux = (unsigned int) temperatura; // aux = 46689, Pega somente a parte inteira da vari�vel float (0 - 65536)
	Tbyte1 = aux;                     // byte2 = 0B01100001, pega apenas os primeros 8 bits
	    
	// Ajustando o n�mero depois da v�rgula
	temperatura -= aux;               // Deixa apenas o n�mero depois da v�rgula
	temperatura *= 100;               // Multiplica por 100 para pegar 2 d�gitos ap�s a v�rgula
	aux = (unsigned int) temperatura; // Pega somente o valor antes da v�rgula
	Tbyte2 = aux;                     // byte2 = 0B00101110, pega apenas os primeros 8 bits
	
	//===========================================================================================================
	
	// Ajustando o n�mero antes da v�rgula para vari�veis float positivas  
	//Umidade
	aux2 = (unsigned int) umidade;    // Pega somente a parte inteira da vari�vel float (0 - 65536)
	Ubyte1 = aux2;                    // byte2 = 0B01100001, pega apenas os primeros 8 bits
	  
	// Ajustando o n�mero depois da v�rgula
	  
	umidade -= aux2;                  // Deixa apenas o n�mero depois da v�rgula
	umidade *= 100;                   // Multiplica por 100 para pegar 2 d�gitos ap�s a v�rgula
	aux2 = (unsigned int) umidade;    // Pega somente o valor antes da v�rgula
	Ubyte2 = aux2;                    // byte2 = 0B00101110, pega apenas os primeros 8 bits
	
	//===========================================================================================================
	
	// Ajustando o n�mero antes da v�rgula para vari�veis float positivas
	  
	//Press�o
	aux3 = (unsigned int) patm;       // aux = 46689, Pega somente a parte inteira da vari�vel float (0 - 65536)
	Pbyte1 = aux3;                    // byte2 = 0B01100001, pega apenas os primeros 8 bits
	  
	// Ajustando o n�mero depois da v�rgula
	  
	patm -= aux3;                     // Deixa apenas o n�mero depois da v�rgula
	patm *= 100;                      // Multiplica por 100 para pegar 2 d�gitos ap�s a v�rgula
	aux3 = (unsigned int) patm;       // Pega somente o valor antes da v�rgula
	Pbyte2 = aux3;                    // byte2 = 0B00101110, pega apenas os primeros 8 bits
	
	return (String) Tbyte1 + "t1;" + (String) Tbyte2 + "t2;" + (String) Ubyte1 + "u1;" + (String) Ubyte2 + "u2;" + (String) Pbyte1 + "p1;" + (String) Pbyte2 + "p2";
}

void Mcm_Func_Envio_Dados_I2C::enviaDadosI2c(String vetDados)
{
	int i;
    int tam;
    char* tmpCaracter;
    char* dadosChar;
    
	char caracter[1];
	char key[] = "t1t2u1u2p1p2hsmisedmmsanuv";
		
	std::strcpy (dadosChar, vetDados.c_str());	
	vetDados = strtok (dadosChar,";");    
	
	while (dadosChar != NULL)
	{

		tmpCaracter = strpbrk (dadosChar, key);
		tam = strlen(tmpCaracter);

		caracter[0] = tmpCaracter[tam-2];
		caracter[1] = tmpCaracter[tam-1];
		
		if(caracter[0] == 't' && caracter[1] == '1')
		{
			i = atoi (dadosChar);
			Tbyte1 = i;			
		}
		else if(caracter[0] == 't' && caracter[1] == '2')
		{
			i = atoi (dadosChar);
			Tbyte2 = i;
		}
		else if(caracter[0] == 'u' && caracter[1] == '1')
		{
			i = atoi (dadosChar);
			Ubyte1 = i;
		}
		else if(caracter[0] == 'u' && caracter[1] == '2')
		{
			i = atoi (dadosChar);
			Ubyte2 = i;
		}
		else if(caracter[0] == 'p' && caracter[1] == '1')
		{
			i = atoi (dadosChar);
			Pbyte1 = i;
		}
		else if(caracter[0] == 'p' && caracter[1] == '2')
		{
			i = atoi (dadosChar);
			Pbyte2 = i;
		}
		else if(caracter[0] == 'h' && caracter[1] == 's')
		{
			i = atoi (dadosChar);
			hs = i;
		}
		else if(caracter[0] == 'm' && caracter[1] == 'i')
		{
			i = atoi (dadosChar);
			mi = i;
		}
		else if(caracter[0] == 's' && caracter[1] == 'e')
		{
			i = atoi (dadosChar);
			se = i;	
		}
		else if(caracter[0] == 'd' && caracter[1] == 'm')
		{
			i = atoi (dadosChar);
			dm = i;
		}
		else if(caracter[0] == 'm' && caracter[1] == 's')
		{
			i = atoi (dadosChar);
			ms = i;
		}
		else if(caracter[0] == 'a' && caracter[1] == 'n')
		{
			i = atoi (dadosChar);
			an = i;
		}
		else if(caracter[0] == 'u' && caracter[1] == 'v')
		{
			i = atoi (dadosChar);
			uv = i;
		}
	
		dadosChar = strtok (NULL, ";");

	}

  	//Envio dos Dados gerados pelos sensores para o Arduino

  	//temperatura
  	Wire.beginTransmission(5);      // Come�a transmiss�o para o escravo no endere�o 5
  	Wire.write(Tbyte1);               // Envia os bytes do n�mero antes da v�rgua
  	Wire.write(Tbyte2);               // Envia os bytes do n�mero depois da v�rgua

  	//IndiceUV
  	Wire.write(uv);                // Envia os bytes do n�mero

  	//Umidade
  	Wire.write(Ubyte1);               // Envia os bytes do n�mero antes da v�rgua    
  	Wire.write(Ubyte2);               // Envia os bytes do n�mero depois da v�rgua

  	//Press�o
  	Wire.write(Pbyte1);               // Envia os bytes do n�mero antes da v�rgua     
  	Wire.write(Pbyte2);               // Envia os bytes do n�mero depois da v�rgua

  	//Data e hora
  	Wire.write(hs);               // Envia os bytes do n�mero
  	Wire.write(mi);               // Envia os bytes do n�mero
  	Wire.write(se);               // Envia os bytes do n�mero
  	Wire.write(dm);               // Envia os bytes do n�mero
  	Wire.write(ms);               // Envia os bytes do n�mero
  	Wire.write(an);               // Envia os bytes do n�mero
    
  	Wire.endTransmission();           // Termina a transmiss�o para o Arduino
  	delay(1000);                      // Tempo de atualiza��o das informa��es enviadas para o Arduino
}
