//Mcm_Func_Envio_Dados_I2C mini central meteorologica
#include "Mcm_Func_Envio_Dados_I2C.h"

String Mcm_Func_Envio_Dados_I2C::convertByte(float temperatura, float umidade, float pressaoAtm)
{	
	//Ajustando o número antes da vírgula para variáveis float positivas 
	  
	//Temperatura
	//Ajustando o número antes da vírgula
	aux = (unsigned int) temperatura; // aux = 46689, Pega somente a parte inteira da variável float (0 - 65536)
	Tbyte1 = aux;                     // byte2 = 0B01100001, pega apenas os primeros 8 bits
	    
	// Ajustando o número depois da vírgula
	temperatura -= aux;               // Deixa apenas o número depois da vírgula
	temperatura *= 100;               // Multiplica por 100 para pegar 2 dígitos após a vírgula
	aux = (unsigned int) temperatura; // Pega somente o valor antes da vírgula
	Tbyte2 = aux;                     // byte2 = 0B00101110, pega apenas os primeros 8 bits
	
	//===========================================================================================================
	
	// Ajustando o número antes da vírgula para variáveis float positivas  
	//Umidade
	aux2 = (unsigned int) umidade;    // Pega somente a parte inteira da variável float (0 - 65536)
	Ubyte1 = aux2;                    // byte2 = 0B01100001, pega apenas os primeros 8 bits
	  
	// Ajustando o número depois da vírgula
	  
	umidade -= aux2;                  // Deixa apenas o número depois da vírgula
	umidade *= 100;                   // Multiplica por 100 para pegar 2 dígitos após a vírgula
	aux2 = (unsigned int) umidade;    // Pega somente o valor antes da vírgula
	Ubyte2 = aux2;                    // byte2 = 0B00101110, pega apenas os primeros 8 bits
	
	//===========================================================================================================
	
	// Ajustando o número antes da vírgula para variáveis float positivas
	  
	//Pressão
	aux3 = (unsigned int) patm;       // aux = 46689, Pega somente a parte inteira da variável float (0 - 65536)
	Pbyte1 = aux3;                    // byte2 = 0B01100001, pega apenas os primeros 8 bits
	  
	// Ajustando o número depois da vírgula
	  
	patm -= aux3;                     // Deixa apenas o número depois da vírgula
	patm *= 100;                      // Multiplica por 100 para pegar 2 dígitos após a vírgula
	aux3 = (unsigned int) patm;       // Pega somente o valor antes da vírgula
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
  	Wire.beginTransmission(5);      // Começa transmissão para o escravo no endereço 5
  	Wire.write(Tbyte1);               // Envia os bytes do número antes da vírgua
  	Wire.write(Tbyte2);               // Envia os bytes do número depois da vírgua

  	//IndiceUV
  	Wire.write(uv);                // Envia os bytes do número

  	//Umidade
  	Wire.write(Ubyte1);               // Envia os bytes do número antes da vírgua    
  	Wire.write(Ubyte2);               // Envia os bytes do número depois da vírgua

  	//Pressão
  	Wire.write(Pbyte1);               // Envia os bytes do número antes da vírgua     
  	Wire.write(Pbyte2);               // Envia os bytes do número depois da vírgua

  	//Data e hora
  	Wire.write(hs);               // Envia os bytes do número
  	Wire.write(mi);               // Envia os bytes do número
  	Wire.write(se);               // Envia os bytes do número
  	Wire.write(dm);               // Envia os bytes do número
  	Wire.write(ms);               // Envia os bytes do número
  	Wire.write(an);               // Envia os bytes do número
    
  	Wire.endTransmission();           // Termina a transmissão para o Arduino
  	delay(1000);                      // Tempo de atualização das informações enviadas para o Arduino
}
