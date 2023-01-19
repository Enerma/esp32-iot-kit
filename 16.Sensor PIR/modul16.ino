#define BLYNK_TEMPLATE_ID "TMPLDxGTT61f"
#define BLYNK_DEVICE_NAME "PIR"
#define BLYNK_AUTH_TOKEN "V73Ol3KqNrbuTRg9U20urZBq6FqCY_PS"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
int inputPin = 15; 

void pembacaan(){
  int val = digitalRead(inputPin);
  Blynk.virtualWrite(V0, val);
  Serial.println(val);
  if(val==1){
    Serial.println("Motion Detected");
  }
  else{
    Serial.println("No Motion Detected");
  }
}

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, pembacaan);
}

void loop()
{
  Blynk.run();
  timer.run(); 
}
