#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLOUqzX6sc"
#define BLYNK_DEVICE_NAME "Membaca Analog"
#define BLYNK_AUTH_TOKEN "tkP9vOGi3nM6YSwUcKXL36BKFTicOfYz"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>

BlynkTimer timer;
char auth[] = "tkP9vOGi3nM6YSwUcKXL36BKFTicOfYz";

char ssid[] = "Wokwi-GUEST";
char pass[] = "";
const int potPin = 34;

void pembacaan(){
  int adc=analogRead(potPin);
  float tegangan=adc*3.3/4095;
  Blynk.virtualWrite(V0, adc);
  Blynk.virtualWrite(V1, tegangan);
  Serial.println(adc);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(500L, pembacaan);
}

void loop()
{
  Blynk.run();
  timer.run();
}
