#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL7ryKsIz8"
#define BLYNK_DEVICE_NAME "Sensor DHT22"
#define BLYNK_AUTH_TOKEN "pmR6gBnAKTJ7XC9YJyQpFrjiRTUyFwB1"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>

const int DHT_PIN = 15;
DHTesp dhtSensor;

char auth[] = "pmR6gBnAKTJ7XC9YJyQpFrjiRTUyFwB1";
BlynkTimer timer;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";


void sendSensor()
{
 TempAndHumidity  data = dhtSensor.getTempAndHumidity();
 Serial.println("Temp: " + String(data.temperature, 2) + "°C");
 Serial.println("Humidity: " + String(data.humidity, 1) + "%");
 Serial.println("---");
 Blynk.virtualWrite(V0, data.temperature); 
 Blynk.virtualWrite(V1, data.humidity);//mengirimkan data ke Virtual pin di Blynk Cloud
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
