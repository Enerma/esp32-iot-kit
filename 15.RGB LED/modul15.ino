#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3MM-rqtp"
#define BLYNK_DEVICE_NAME "rgb led"
#define BLYNK_AUTH_TOKEN "ypBgyMKBzPDLpsrLMGGxlkSArIoOWSvw"

#define PIN_RED   23 // GIOP23
#define PIN_GREEN  22 // GIOP22
#define PIN_BLUE   21 // GIOP21

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
int R,G,B=0;

BlynkTimer timer;
BLYNK_WRITE(V0)
  {
    R = param.asInt();
    analogWrite(PIN_RED,   R);
  }

BLYNK_WRITE(V1)
  {
    G = param.asInt();
    analogWrite(PIN_GREEN, G);
  }

BLYNK_WRITE(V2)
  {
    B = param.asInt();
    analogWrite(PIN_BLUE,  B);
  }

void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}


void loop() {
Blynk.run();
}

