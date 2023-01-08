
#define BLYNK_TEMPLATE_ID "TMPLOUqzX6sc"
#define BLYNK_DEVICE_NAME "Servo"
#define BLYNK_AUTH_TOKEN "PcefTEHMKA0_Qp_diJC_6V7OdyE2WQWz"

#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int servoPin = 18;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;
Servo servo;

int pos = 0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(servoPin, 500, 2400);
}

BLYNK_WRITE(V0)
{
 int pos = param.asInt();
 servo.write(pos);
}

void loop() {
Blynk.run();
}

