#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLoyOWUPoA"
#define Relay 2
#define Relay1 4

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "DacZVFOdBBcSm0_bnA56FK06VJLXO6Co";

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
 int pinValue = param.asInt();
 digitalWrite(Relay,pinValue);
}

BLYNK_WRITE(V1)
{
 int pinValue1 = param.asInt();
 digitalWrite(Relay1,pinValue1);
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
}

void loop()
{
  Blynk.run();
}
