#include "Strip.h"

Strip::Strip(const int dataPin, uint8_t stripBegin, uint8_t stripEnd, uint16_t ledNum, uint8_t stripNum, byte orientation) {           

  FastLED.addLeds<NEOPIXEL, A4>(leds[0], 46);
}


void Strip::powerFunction(uint16_t powerreading, float currentreading){ 
    unsigned long previousMillis;
    byte interval;
    
    uint8_t brightness = (155/16)*(currentreading)+100;
    uint16_t velocity = (abs(powerreading) - 4400)/-23.5;
    if(currentreading >= 0.1){
        byte color = 32;
        byte value;  
              
        if(powerreading > 0)
           value = 1;
        
        if(powerreading < 0)
          value = -1;

        char Direction = value * orientation;
        
        int movement;
        movement++;
        
        byte j;   
        if(j < 14)
          j++;
        if(j >= 14)
          j = 0;

        uint8_t saturation;
          
        int val = round(brightness/2.0*(sin((Direction)*(movement)/(velocity)-((7-j)*0.7854))+1));  //<<< can just leave val as a integer, dont need array
        leds[stripNum][stripBegin+j] = CHSV(color, saturation, val);

      }
      else if(currentreading < 0.1){
        fill_solid( leds[stripNum], ledNum, CRGB(0,0,0)); 
      }
  FastLED.show();
}

void Strip::msgFunction(){
    int i;
    i+=1;
    if(stripEnd > stripBegin && i==25){
        stripEnd-=1;
        i=0;
    } 
    if(stripEnd == 0){
        byte message = 1;
        i=0;
    } 
    byte saturation;
    byte color = 96;

    leds[stripNum][stripEnd] = CHSV(color, saturation, 100);
    leds[stripNum][stripEnd+1] = CRGB::Black;
    FastLED.show();
}     
 /* if(plugin == false)
  {
    fill_solid( leds[stripNum], ledNum, CRGB(0,0,0));
    FastLED.show();
  }*/

bool Strip::magnetSensor(const uint8_t reedPin){
    pinMode(reedPin, INPUT_PULLUP);                     //button pin using internal pull up resistor
 
    byte plugin;
    byte reedVal = digitalRead(6);

    if (reedVal == LOW){
        plugin = 1;    //Serial.println("Magnet Detected");
    }
    if (reedVal == HIGH){
        byte msgState = 1;
        byte powerState = 0;
        plugin = 0;  //currently left as true for testing purposes(normally is false here) //Serial.println("No Magnet Detected")
        stripEnd = stripBegin;
    }
    return plugin;
} 

void Strip::turnOff(){
    fill_solid( leds[stripNum], ledNum, CRGB(0,0,0)); 
    FastLED.show();
}
