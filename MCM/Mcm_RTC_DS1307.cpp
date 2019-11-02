//Relogio mini central meteorologica
#include "Mcm_RTC_DS1307.h"

String Mcm_RTC_DS1307::mostraRelogio()
{
	
  Wire.beginTransmission(ENDERECO_RTC);
  Wire.write(posicaoMemGravacao);
  Wire.endTransmission();
  Wire.requestFrom(ENDERECO_RTC, 7);
  int segundos = converteParaDecimal(Wire.read());
  int minutos = converteParaDecimal(Wire.read());
  int horas = converteParaDecimal(Wire.read() & 0b111111); 
  int diadasemana = converteParaDecimal(Wire.read()); 
  int diadomes = converteParaDecimal(Wire.read());
  int mes = converteParaDecimal(Wire.read());
  int ano = converteParaDecimal(Wire.read());
  
  return((String)diadomes + "/" + (String)mes + "/" + (String)ano + ";" + (String)horas + ":" + (String)minutos + ":" + (String)segundos);
}

void Mcm_RTC_DS1307::selecionaDataHora()
{
	
  byte segundos = 00;                     // Valores de 0 a 59
  byte minutos = 7;                      // Valores de 0 a 59
  byte horas = 21;                        // Valores de 0 a 23
  byte diadasemana = 0;                   // Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 12;                      // Valores de 1 a 31
  byte mes = 8;                           // Valores de 1 a 12
  byte ano = 18;                          // Valores de 0 a 99
  Wire.beginTransmission(ENDERECO_RTC); // Inicia a transmissção I2C para o endereço especificado
  Wire.write(posicaoMemGravacao);                       // Stop no CI para que o mesmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(converteParaBCD(segundos));
  Wire.write(converteParaBCD(minutos));
  Wire.write(converteParaBCD(horas));
  Wire.write(converteParaBCD(diadasemana));
  Wire.write(converteParaBCD(diadomes));
  Wire.write(converteParaBCD(mes));
  Wire.write(converteParaBCD(ano));
  Wire.write(posicaoMemGravacao);                       // Start no CI
  Wire.endTransmission();                 // Termina a transmissão para o DS1307
  
}

byte Mcm_RTC_DS1307::converteParaBCD(byte val)
{
	return ( (val/10*16) + (val%10) ); //Converte o número de decimal para BCD
}

byte Mcm_RTC_DS1307::converteParaDecimal(byte val) // Converte de BCD para decimal
{
	return ( (val/16*10) + (val%16) );
}
