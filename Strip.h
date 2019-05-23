#include <stdint.h>
#include <stdlib.h>
#include "Arduino.h"
#include "FastLED.h"

#define STRIP_NUM 5
#define LED_NUM 70

class Strip{
    public:
        uint8_t stripNum; 
        uint16_t ledNum; 
        uint8_t stripBegin;
        uint8_t stripEnd;
        byte orientation;
        CRGB leds[STRIP_NUM][LED_NUM];

        Strip(const int dataPin, uint8_t stripBegin, uint8_t stripEnd, uint16_t ledNum,  uint8_t stripNum, byte orientation);
        
        void powerFunction(uint16_t powerreading, float currentreading);
        void msgFunction();
        void turnOff();
        bool magnetSensor(const uint8_t reedPin);
       
};
