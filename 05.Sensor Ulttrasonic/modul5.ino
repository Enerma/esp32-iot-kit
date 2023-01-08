
#define BLYNK_TEMPLATE_ID "TMPLOUqzX6sc" //ID Template
#define BLYNK_AUTH_TOKEN "tkP9vOGi3nM6YSwUcKXL36BKFTicOfYz" // Token dari Blynk
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>  // Token dari Blynk

#define triggerPin  23 // set Trigger ke pin 26/IO26
#define echoPin     22 // set Echo ke pin 25/IO25

char auth[] = BLYNK_AUTH_TOKEN;


char ssid[] = "Wokwi-GUEST";   // Nama Hotspot / WiFi
char pass[] = ""; // Password WiFi



long duration;
int jarak;

BlynkTimer timer;


void myTimerEvent()
{
  Blynk.virtualWrite(V0, millis() / 1000);
}


void setup()
{
  // Debug console
  pinMode(triggerPin, OUTPUT);  // Set triggerPin sbg Output
  pinMode(echoPin, INPUT);   // Set echoPin sbg Input
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
void sendSensor()
{
  digitalWrite(triggerPin, LOW);   //Set triggerPin low
  delayMicroseconds(2);       // delay 2 micro second

  digitalWrite(triggerPin, HIGH);  // Set triggerPin high
  delayMicroseconds(10);      // triggerPin high selama 10 micro seconds
  digitalWrite(triggerPin, LOW);   // triggerPinPin low

  duration = pulseIn(echoPin, HIGH);   //Pembacaan Echo pin dan durasi
  jarak = duration * 0.034 / 2;   ///Menghitung jarak yg sebenarnya

  Serial.println("jarak :"); //Output jarak pada serial monitor
  Serial.print(jarak);
  Serial.println(" cm");
  delay(250);

  Blynk.virtualWrite(V0, jarak);
  delay(1000);
}
