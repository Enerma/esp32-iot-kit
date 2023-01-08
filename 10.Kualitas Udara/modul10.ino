#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL7ryKsIz8"
#define BLYNK_AUTH_TOKEN "_kRvRchf7TKiwue8a2WCpXh3NJ5oCqB5"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
const int sensor = 34;


void pembacaan(){
  delay(10); // this speeds up the simulation
  int nilaisensor = analogRead(sensor);
  int kualitas=map(nilaisensor,0,4095,0,500);
  Blynk.virtualWrite(V0, nilaiLDR);
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(500L, pembacaan);
}

void loop()
{
  Blynk.run();
  timer.run();
}
