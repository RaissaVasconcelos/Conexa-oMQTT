/*=============================================================================
Programa: Conexão MQTT com maquina local
Autor: Raissa Vasconcelos Mendes
==============================================================================*/
/*Bibliotecas*/
#include <Arduino.h>
#include<WiFi.h>
#include<PubSubClient.h>

/*Variaveis Globais*/

//Constantes Conexao Internet
const char* ssid = "ADM";
const char* password = "Hub@DMs2"; 
/*
ssid = "ADM";
password = "Hub@DMs2";
ssid = "dlink-AA73";
const char* password = "uigds50953";
*/ 

//Constantes MQTT
const char* mqttServer = "192.168.0.107";
//"127.0.0.1"; //id localhost
const int mqttPort = 1883; //porta sem criptografica
WiFiClient espClient; //objeto cliente Wifi
PubSubClient mqttClient(espClient); //objeto cliente mqtt
#define MQTT_TOPIC "teste/esp/1245" //Topico Mqtt
#define MQTT_ID "pomano1111"

/*Prototipos de Funções*/
void conectionWifi();
void conectionMQTT();
void reconectMQTT();

void conectionWifi(){
  WiFi.mode(WIFI_STA);//Modo de operação Cliente Wireless
  WiFi.begin(ssid, password); //Conexao a rede Wifi
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Conetando a Rede...");
  }
  Serial.print("Conectado a:"); Serial.println(ssid);
  Serial.print("Endereço de ip:"); Serial.println(WiFi.localIP());
}//endConectionWifi

void conectionMQTT(){
  mqttClient.setServer(mqttServer,mqttPort); //Conectando ao broker
}//end conectionMQTT

void reconectMQTT(){
  while(!mqttClient.connected())
  {
    Serial.print("Conectando..."); 
    
    if(mqttClient.connect(MQTT_ID)){
      Serial.print("Conectado ao Broker");
     } //end if
    else
    {
      Serial.println("Falha na conexão com o Broker");
      Serial.print("Estado:");Serial.println(mqttClient.state());
      delay(1000);
    }//end else
  }//end while
}//end reconectMQTT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  conectionWifi();
  conectionMQTT();
}//end Setup

void loop() {
  // put your main code here, to run repeatedly:
  reconectMQTT();
  mqttClient.publish(MQTT_TOPIC, "Hello MQTT");
  delay(2000);
}//end Loop
