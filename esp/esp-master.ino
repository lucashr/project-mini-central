#include <MCM.h>


#define PINODHT 0     // Pino 0 do esp
#define TIPODHT DHT11 // Sensor DHT 22  (AM2302)

// Configuração de objetos
Mcm_BMP180 objBmp;
Mcm_Datalogger objDatalogger;
Mcm_UVM30A objUvm;
Mcm_RTC_DS1307 objRtc;
Mcm_Func_Envio_Dados_I2C objI2c;
Adafruit_BMP085 bmp180;      // Relativo ao sensor de pressão

// Definicao de hardware
DHT dht(PINODHT, TIPODHT);

const byte chipSelect = 15; // Seleciona o pino do ESP que esta conectado ao cartao microsd
int pino_sensorUv;          // Configura o pino analogico do esp como entrada - Sensor UV

//Variaveis auxilio na temporização da gravação do datalloger
unsigned long tmpAnterior = 0;             // Variavel de controle do tempo
unsigned long interval_datalloger = 10000; // Tempo em ms do intervalo a ser executado

void setup() {
  Serial.begin(115200);
  Wire.begin();                                   //Configura a transmissão I2C
  dht.begin();
   //if (!bmp180.begin())
   //{ 
    //Serial.println("Sensor nao encontrado !!");
    //while (1) {}
   //}
  pinMode(pino_sensorUv, INPUT);                  // Configura o pino analogico do esp como entrada - Sensor UV
  objDatalogger.inicializaCartaoSD(chipSelect); // Inicializa o cartao microsd
  objDatalogger.escreveNoCartao("Log.txt", "Cabeçalho teste");   // Cabeçalho
  delay(2000); // Usado para dar tempo suficiente para a alimentação de todo o circuito
}

void loop() {
  unsigned long tmpAtual = millis(); // Tempo atual em ms
 
  float temp = dht.readTemperature();
  float umd = dht.readHumidity();
  float pres = objBmp.lerPressaoAtm(bmp180);
  byte uvmIndUv = objUvm.lerIndiceUV(pino_sensorUv);

  String linhaSaida = (String)temp + ";" + (String)umd + ";" +  ";" + (String)uvmIndUv;
  Serial.println(linhaSaida);
  
  if((tmpAtual - tmpAnterior) < interval_datalloger)
  {
    tmpAnterior = tmpAtual; // Salva o tempo atual
    objDatalogger.escreveNoCartao("Log.txt", linhaSaida);
    
  }  
  
  delay(1000);
}
 
/*
if ((tmpAtual - tmpAnterior) > interval_datalloger) {
    float temp = objDht.lerTemperatura(dht);
    float humd = objDht.lerUmidade(dht);
    Serial.print("Humidade: ");
    Serial.println(humd);
    Serial.print("Temperatura: ");
    Serial.println(temp);
  }


*/
