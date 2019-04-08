#include "FastLED.h"

#define NUM_LEDS 200
#define DATA_PIN 4
#define PI_EIGHTH 0.3927
#define PI_FOURTH 0.7854
#define PI_HALF 1.5708
#define PI_THREEFOURTH 2.3562

const int buttonPin = 5;     // BUTTON PIN

const int reedPin1 = 11;     // REED SENSOR PINS
const int reedPin2 = 10;
const int reedPin3 = 9;
const int reedPin4 = 8;
const int reedLED =  7;      // LED PINS (only for troubleshooting)
const int reedLED2, reedLED3, reedLED4;

CRGB leds[NUM_LEDS];

//button variables
unsigned long buttonPushCounter = 0;    //button counter
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

// magnetic plug in sensor variables
bool plugin1 , plugin2, plugin3, plugin4, plugin5 = true;
int reedVal1, reedVal2, reedVal3, reedVal4;

//message function variables
bool messageVal1 = false, messageVal2 = false, messageVal3 = false, messageVal4 = false;

//timer variables
int interval = 0;
unsigned long previousMillis1, previousMillis2, previousMillis3, previousMillis4, previousMillis5, prevMillis;

//LED strip parameters
int StripIndex1 = 0;
int StripIndex2 = 15;
int StripIndex3 = 30;
int StripIndex4 = 45;
int StripIndexSum = 60;

int StripEnd1 = 14;
int StripEnd2 = 29;
int StripEnd3 = 44;
int StripEnd4 = 59;
int StripEndSum = NUM_LEDS;

// Sine Wave variables
float sinValues[15] = { -7 * PI_FOURTH, -3 * PI_HALF, -5 * PI_FOURTH, -PI, -3 * PI_FOURTH, -PI_HALF, -PI_FOURTH, 0,
                        PI_FOURTH, PI_HALF, 3 * PI_FOURTH, PI, 5 * PI_FOURTH, 3 * PI_HALF,
                        7 * PI_FOURTH};
int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15;
byte brightness1, brightness2, brightness3, brightness4, brightness5;
float velocity1, velocity2, velocity3, velocity4, velocity5;
int value1, value2, value3, value4, value5;
byte color = 25;
byte saturation = 230;
int Direction1 = 0;
int Direction2 = 0;
int Direction3 = 0;
int Direction4 = 0;
int Direction5 = 0;

float currentreading1 = 4;
float currentreading2 = 4;
float currentreading3 = 4;
float currentreading4 = 4;
float currentsum = currentreading1 + currentreading2 + currentreading3 + currentreading4;

int powerreading1 = 500;
int powerreading2 = 1000;
int powerreading3 = -200;
int powerreading4 = -750;
int powersum = powerreading1 + powerreading2 + powerreading3 + powerreading4;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(buttonPin, INPUT_PULLUP);                     //button pin using internal pull up resistor
  pinMode(DATA_PIN, OUTPUT);
  pinMode(reedLED, OUTPUT);                             //LED on outlet which confirms magnet0
  pinMode(reedPin1, INPUT);
  pinMode(reedPin2, INPUT);
  pinMode(reedPin3, INPUT);
  pinMode(reedPin4, INPUT);
  Serial.begin(9600);

}

void loop()
{
  magnetSensor(&plugin1, &reedLED, &reedVal1, &reedPin1);          //outlet 1
  magnetSensor(&plugin2, &reedLED2, &reedVal2, &reedPin2);         //outlet 2
  magnetSensor(&plugin3, &reedLED3, &reedVal3, &reedPin3);         //outlet 3
  magnetSensor(&plugin4, &reedLED4, &reedVal4, &reedPin4);         //outlet 4

  button();                                      //button function (on/off)
  if (buttonPushCounter % 2 == 0)
  {
    colorWipe(&StripIndex1);
    colorWipe(&StripIndex2);
    colorWipe(&StripIndex3);
    colorWipe(&StripIndex4);
    colorWipe(&StripIndexSum);
  }
  if (buttonPushCounter % 2 != 0)                    // if button was pushed begin program
  {
    LEDStrip(&StripIndex1, &color, &saturation, &brightness1, &velocity1, &currentreading1, &powerreading1, &previousMillis1, &Direction1, &value1, &plugin1);
    LEDStrip(&StripIndex2, &color, &saturation, &brightness2, &velocity2, &currentreading2, &powerreading2, &previousMillis2, &Direction2, &value2, &plugin2);
    LEDStrip(&StripIndex3, &color, &saturation, &brightness3, &velocity3, &currentreading3, &powerreading3, &previousMillis3, &Direction3, &value3, &plugin3);
    LEDStrip(&StripIndex4, &color, &saturation, &brightness4, &velocity4, &currentreading4, &powerreading4, &previousMillis4, &Direction4, &value4, &plugin4);
    LEDStrip(&StripIndexSum, &color, &saturation, &brightness5, &velocity5, &currentsum, &powersum, &previousMillis5, &Direction5, &value5, &plugin5);

  }
}

void LEDStrip(int *StripIndex , byte *color, byte *saturation, byte *brightness, float *velocity,
              float *currentreading, int *powerreading, unsigned long *previousMillis,
              int  *Direction, int *value, bool *plugin)
{
  *brightness = (155 / 16) * (*currentreading) + 100;
  *velocity = (abs(*powerreading) - 4400) / -23.5;

  if (*currentreading >= 0.1  && *plugin == true)
  {
    if (millis() - *previousMillis >= interval)
    {
      if (*powerreading > 0)
      {
        *Direction++;
        *value = 1;
      }
      if (*powerreading < 0)
      {
        *Direction++;
        *value = -1;
      }
      val1 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - (7 * PI_FOURTH)) + 1));
      val2 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - (3 * PI_HALF)) + 1));
      val3 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - (5 * PI_FOURTH)) + 1));
      val4 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - PI) + 1));
      val5 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - (3 * PI_FOURTH)) + 1));
      val6 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - PI_HALF) + 1));
      val7 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) - PI_FOURTH) + 1));
      val8 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity)) + 1));
      val9 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + PI_FOURTH) + 1));
      val10 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + PI_HALF) + 1));
      val11 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + (3 * PI_FOURTH)) + 1));
      val12 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + PI) + 1));
      val13 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + (5 * PI_FOURTH)) + 1));
      val14 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + (3 * PI_HALF)) + 1));
      val15 = round(*brightness / 2.0 * (sin((*value) * (*Direction) / (*velocity) + (7 * PI_FOURTH)) + 1));

      leds[*StripIndex + 0] = CHSV(*color, *saturation, val1);
      leds[*StripIndex + 1] = CHSV(*color, *saturation, val2);
      leds[*StripIndex + 2] = CHSV(*color, *saturation, val3);
      leds[*StripIndex + 3] = CHSV(*color, *saturation, val4);
      leds[*StripIndex + 4] = CHSV(*color, *saturation, val5);
      leds[*StripIndex + 5] = CHSV(*color, *saturation, val6);
      leds[*StripIndex + 6] = CHSV(*color, *saturation, val7);
      leds[*StripIndex + 7] = CHSV(*color, *saturation, val8);
      leds[*StripIndex + 8] = CHSV(*color, *saturation, val9);
      leds[*StripIndex + 9] = CHSV(*color, *saturation, val10);
      leds[*StripIndex + 10] = CHSV(*color, *saturation, val11);
      leds[*StripIndex + 11] = CHSV(*color, *saturation, val12);
      leds[*StripIndex + 12] = CHSV(*color, *saturation, val13);
      leds[*StripIndex + 13] = CHSV(*color, *saturation, val14);
      leds[*StripIndex + 14] = CHSV(*color, *saturation, val15);

      FastLED.show();

      *previousMillis = millis();
    }

  }
  else if (*currentreading < 0.1 || *plugin == false)
  {
    leds[*StripIndex + 0] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 1] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 2] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 3] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 4] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 5] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 6] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 7] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 8] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 9] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 10] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 11] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 12] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 13] = CHSV(*color, *saturation, 0);
    leds[*StripIndex + 14] = CHSV(*color, *saturation, 0);

    FastLED.show();

  }

}

void button()                   //button
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
  {
    if (buttonState == LOW)
    {
      buttonPushCounter++;
    }
    else
    {
    }
    delay(25);
  }
  lastButtonState = buttonState;

}
/*
   Function turns off all the LEDs on the strip
*/
void colorWipe(int *StripIndex)
{
    leds[*StripIndex + 0] = CHSV(0, 0, 0);
    leds[*StripIndex + 1] = CHSV(0, 0, 0);
    leds[*StripIndex + 2] = CHSV(0, 0, 0);
    leds[*StripIndex + 3] = CHSV(0, 0, 0);
    leds[*StripIndex + 4] = CHSV(0, 0, 0);
    leds[*StripIndex + 5] = CHSV(0, 0, 0);
    leds[*StripIndex + 6] = CHSV(0, 0, 0);
    leds[*StripIndex + 7] = CHSV(0, 0, 0);
    leds[*StripIndex + 8] = CHSV(0, 0, 0);
    leds[*StripIndex + 9] = CHSV(0, 0, 0);
    leds[*StripIndex + 10] = CHSV(0, 0, 0);
    leds[*StripIndex + 11] = CHSV(0, 0, 0);
    leds[*StripIndex + 12] = CHSV(0, 0, 0);
    leds[*StripIndex + 13] = CHSV(0, 0, 0);
    leds[*StripIndex + 14] = CHSV(0, 0, 0);
    
    FastLED.show();
}

/*
   Function reads the magnetic sensor pin, which tells the system that the outlet has a plug in it
*/
void magnetSensor(bool *plugin, const int *reedLED, int *reedVal, const int *reedPin)
{

  *reedVal = digitalRead(*reedPin);
  if (*reedVal == HIGH)
  {
    *plugin = true;
    digitalWrite(*reedLED, HIGH);
    //Serial.println("Magnet Detected");
  }
  if (*reedVal == LOW)
  {
    *plugin = true;                     //currently left as true for testing purposes(normally is false here)
    digitalWrite(*reedLED, LOW);
    //Serial.println("No Magnet Detected");
  }
}
