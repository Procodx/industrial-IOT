/*
  Refrence:
    WiFiClient (Arduino pre-built example)
    WiFiClientBasic (Arduino pre-built exaample)
    
*/

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

int dt_out = 25; //dt_out ==> delay timer out (out denoting the end of the void loop)
int dt = 5000; //dt ==> delay timer
int minDt = 0.5; //minDt ==> minimum timer
int eMotorStartPin  = LED_BUILTIN;

#define ssid "esp8266"
#define password "forTheLoveOfEmbededSystem"

#define host "192.168.115.87" //host subject to change always untill app is hosted
int port = 3565;

void setup(){ 

  pinMode(eMotorStartPin, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.begin (115200);
  
  while (WiFi.status() != WL_CONNECTED) {

     delay(dt);
     Serial.print("Connecting to Wifi network...");
     Serial.println(".");

  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  
}

void loop() {

//   Use WiFiClient class to create TCP connections

  WiFiClient client;

  if (!client.connect(host, port)) {

    Serial.println("connection failed");
    delay(5000);
    return;

  }  
  
  // Make a POST request to the server

  client.println("POST /query HTTP/1.1");
  client.println();

  // Check for response from the server

  int timeOut = 0;
  
  while (!client.available() && timeOut < 60000) {

    timeOut ++;
    delay(minDt);

  }

  // Read data from the buffer

  if (client.available() > 0){
  
    String value = client.readString();

    int json = value.indexOf("{");
    String jsonData = value.substring(json);    

    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, jsonData);

    if (error) {

      Serial.println("Deserialization failed: " + String(error.c_str()));
      return;

    }

    int motorState = doc["success"];

     if (motorState == 1){

        digitalWrite(eMotorStartPin, HIGH);
      
      }

      else{

        digitalWrite(eMotorStartPin,LOW);

      }    

  }

  else{

    Serial.println("client.available() timed out ");

  }

  delay (dt_out);

}