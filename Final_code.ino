#include <FastLED.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <NewPing.h>
#define NUM_LEDS  30
#define LED_PIN   3
#define SOFTSERIAL_RX_PIN  8
#define SOFTSERIAL_TX_PIN  9
#define trigPin  10
#define echoPin 11
#define maxDistance 400

SoftwareSerial softSerial(SOFTSERIAL_RX_PIN, SOFTSERIAL_TX_PIN);
int pos = 0;
Servo Servo1;

CRGB leds[NUM_LEDS];
uint8_t patternCounter = 0;

NewPing sonar( trigPin, echoPin, maxDistance);
const char *voiceBuffer[] =
{
  "Turn on the light",
  "Turn off the light",
  "Play music",
  "Pause",
  "Next",
  "Previous",
  "Up",
  "Down",
  "Turn on the TV",
  "Turn off the TV",
  "Increase temperature",
  "Decrease temperature",
  "What's the time",
  "Open the door",
  "Close the door",
  "Left",
  "Right",
  "Stop",
  "Start",
  "Mode 1",
  "Mode 2",
  "Go",
};



void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
 
  Serial.begin(9600);
  
  softSerial.begin(9600);
  softSerial.listen();
  Servo1.attach(6);

}

void loop() {
    char cmd;

    if(softSerial.available())
    {
        cmd = softSerial.read();
        
        Serial1.println(voiceBuffer[cmd - 1]);
        }
  
 if(cmd==19){
    Servo1.write(0); 
   delay(1000); 

   Servo1.write(90); 
   delay(1000); 

   Servo1.write(180); 
   delay(1000);  }
 
  if ( sonar.ping_cm() <= 5) {
    rainbowBeat();
    FastLED.setBrightness(200);
    Serial.println(sonar.ping_cm());
   
   
  }
  else if (sonar.ping_cm() > 5 && sonar.ping_cm() <= 30) {
    yellowRed();
    FastLED.setBrightness(120);
   Serial.println(sonar.ping_cm());

  }
  else {
    greenBlue();
    FastLED.setBrightness(50);
   Serial.println(sonar.ping_cm());
 
  }
  FastLED.show();
}



void yellowRed() {


  uint16_t sinBeat3  = beatsin16(30, 0, NUM_LEDS - 1, 0, 21845);
  uint16_t sinBeat4  = beatsin16(30, 0, NUM_LEDS - 1, 0, 43690);

  leds[sinBeat3]   = CRGB::Yellow;
  leds[sinBeat4]  = CRGB::Red;


  fadeToBlackBy(leds, NUM_LEDS, 10);
}


void rainbowBeat() {

  uint16_t beatA = beatsin16(30, 0, 255);
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_rainbow(leds, NUM_LEDS, (beatA + beatB) / 2, 8);
}


void greenBlue() {

  uint16_t sinBeat   = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  uint16_t sinBeat2  = beatsin16(30, 0, NUM_LEDS - 1, 0, 10923);


  leds[sinBeat]   = CRGB::Blue;
  leds[sinBeat2]  = CRGB::Green;

  fadeToBlackBy(leds, NUM_LEDS, 10);
}
