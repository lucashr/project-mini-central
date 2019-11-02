//SNS_UVM30A mini central meteorologica
#include "Mcm_UVM30A.h"

byte Mcm_UVM30A::lerIndiceUV(int pino_sensor)
{
	int valor_sensor = 0;
	byte UV_index = 0;
	
    valor_sensor = analogRead(pino_sensor);
  	//Calcula tensao em milivolts
  	int tensao = (valor_sensor * (5.0 / 1023.0)) * 1000;
  
  	//Compara com valores tabela UV_Index
	if (tensao > 0 && tensao < 50) { UV_index = 0; }
	else if (tensao > 50 && tensao <= 227) { UV_index = 0; }
	else if (tensao > 227 && tensao <= 318) { UV_index = 1; }
	else if (tensao > 318 && tensao <= 408) { UV_index = 2;	}
	else if (tensao > 408 && tensao <= 503)	{ UV_index = 3;	}
	else if (tensao > 503 && tensao <= 606)	{ UV_index = 4;	}
	else if (tensao > 606 && tensao <= 696)	{ UV_index = 5;	}
	else if (tensao > 696 && tensao <= 795)	{ UV_index = 6;	}
	else if (tensao > 795 && tensao <= 881)	{ UV_index = 7;	}
	else if (tensao > 881 && tensao <= 976)	{ UV_index = 8;	}
	else if (tensao > 976 && tensao <= 1079) { UV_index = 9; }
	else if (tensao > 1079 && tensao <= 1170) {	UV_index = 10; }
	else if (tensao > 1170)	{ UV_index = 11; }
	
	return(UV_index);
}
