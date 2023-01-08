#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL7ryKsIz8"
#define BLYNK_DEVICE_NAME "Sensor DHT22"
#define BLYNK_AUTH_TOKEN "_kRvRchf7TKiwue8a2WCpXh3NJ5oCqB5"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
const int ldrPin = 34;
const float gama = 0.7;
const float rl10 = 50;

void pembacaan(){
  delay(10); // this speeds up the simulation
  int nilaiLDR = analogRead(ldrPin);
  nilaiLDR = map(nilaiLDR, 4095, 0, 1024, 0); //mengubah nilai pembacaan sensor LDR dari nilai ADC arduino menjadi nilai ADC ESP32
  float voltase = nilaiLDR / 1024.*5;
  float resistansi = 2000 * voltase / (1-voltase/5);
  float kecerahan = pow(rl10*1e3*pow(10,gama)/resistansi,(1/gama));
  Serial.print("Kecerahan = ");
  Serial.println(kecerahan);
  Blynk.virtualWrite(V0, nilaiLDR);
  Blynk.virtualWrite(V1, kecerahan);
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
