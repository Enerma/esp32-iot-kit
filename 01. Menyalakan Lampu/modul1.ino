#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLoyOWUPoA"
#define LED 2
#define LED1 4
#define LED2 5

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>

const int DHT_PIN = 15;
DHTesp dhtSensor;

char auth[] = "DacZVFOdBBcSm0_bnA56FK06VJLXO6Co";

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
 int pinValue = param.asInt();
 digitalWrite(LED,pinValue);
}

BLYNK_WRITE(V1)
{
 int pinValue1 = param.asInt();
 digitalWrite(LED1,pinValue1);
}
BLYNK_WRITE(V2)
{
 int pinValue2 = param.asInt();
 digitalWrite(LED2,pinValue2);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  Blynk.run();
}
