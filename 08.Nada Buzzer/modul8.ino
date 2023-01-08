#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLoyOWUPoA"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int speakerPin = 21;

int length1 = 15; 
char notes1[] = "ccggaagffeeddc "; 
int beats1[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };

int length2 = 15; 
char notes2[] = "cecefggcecefgg ";
int beats2[] = { 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 4, 4 };

int length3 = 16; 
char notes3[] = "cdefgabCCbagfedc"; 
int beats3[] = { 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1,4 };

int tempo = 300;

char auth[] = "WGG8uTwlmw32huVt4vPbe-EVLcKLlcrK";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0)
{
 int state = param.asInt();
 if(state==1){
   nada1();
 }
}

BLYNK_WRITE(V1)
{
 int state = param.asInt();
 if(state==1){
   nada2();
 }
}

BLYNK_WRITE(V2)
{
 int state = param.asInt();
 if(state==1){
   nada3();
 }
}


void loop(){
  Blynk.run();
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void nada1() {
  for (int i = 0; i < length1; i++) {
    if (notes1[i] == ' ') {
      delay(beats1[i] * tempo); // rest
    } else {
      playNote(notes1[i], beats1[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }
}
void nada2() {
  for (int i = 0; i < length2; i++) {
    if (notes2[i] == ' ') {
      delay(beats2[i] * tempo); // rest
    } else {
      playNote(notes2[i], beats2[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }
}
void nada3() {
  for (int i = 0; i < length3; i++) {
    if (notes3[i] == ' ') {
      delay(beats3[i] * tempo); // rest
    } else {
      playNote(notes3[i], beats3[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }
}
