//Mcm_Leitura_Variaveis_Sensores mini central meteorologica
#include "Mcm_Leitura_Variaveis_Sensores.h"

void Mcm_Leitura_Variaveis_Sensores::lePortaAnalogica(byte porta, byte posicao, WiFiClient cl, float sensorUmidade){
	
    cl.print("PA");
    cl.print(porta);
    cl.print("#");
   
    cl.print(sensorUmidade);
   
    cl.println("|");
}
