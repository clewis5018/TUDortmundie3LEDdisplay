# TUDortmundie3LEDdisplay
LED Display of 'Plug n Control' system

Code describing a LED strip which shows the data from Smart Grid sensors (communicating the data using Modbus IP)
  Requires:
      - on/off button
      - magnetic (reed) sensors on outlets and magnets in plugs (boolean expressions used to know whether something is plugged in)
      
      HARDWARE:
      - WS2812B LED Strip
      - Arduino Nano (IDE 1.8.8)
      - 4x 10k ohm Resistors 
      - 5v DC power supply
      
      LIBRARY:
      - FastLED (Version 3.2.0)
