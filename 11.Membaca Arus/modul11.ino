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
const int sensorPin = 34;
int mVperAmp = 185;           // this the 5A version of the ACS712 -use 100 for 20A Module and 66 for 30A Module
int Watt = 0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

void pembacaan(){
  Voltage = getVPP();
  VRMS = (Voltage/2.0) *0.707;   //root 2 is 0.707
  AmpsRMS = ((VRMS * 1000)/mVperAmp)-0.3; //0.3 is the error I got for my sensor
 
  Serial.print(AmpsRMS);
  Serial.print(" Amps RMS  ---  ");
  Watt = (AmpsRMS*240/1.2);
  Blynk.virtualWrite(V0, AmpsRMS);
  Blynk.virtualWrite(V1, Watt);
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

float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 4096;          // store min value here ESP32 ADC resolution
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the minimum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 3.3)/4096.0; //ESP32 ADC resolution 4096
      
   return result;
 }
