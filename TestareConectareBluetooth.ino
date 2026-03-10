#define USE_NIMBLE
#include <BleKeyboard.h>

#include <Wire.h>
#include "paj7620.h"

BleKeyboard bleKeyboard("Magic Keyboard", "Apple", 100);

const int buttonUp = 25;
const int buttonDown = 26;
const int buttonNext = 32;
const int buttonPrev = 33;

void setup() {
  Serial.begin(115200);
  Serial.println("Incepe testarea!");
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonPrev, INPUT_PULLUP);
  pinMode(buttonNext, INPUT_PULLUP);
  
  bleKeyboard.begin();
  Wire.begin(21, 22);

  uint8_t error = paj7620Init();
  Serial.println("Setup is ok!");
}

void loop() {
  //Citirea de la senzor
  uint8_t data = 0;
  paj7620ReadReg(0x43, 1, &data);
  
  if(data!= 0 && bleKeyboard.isConnected()) {
    //Dreapta = next track
    if (data == 0x02){
      Serial.println("Next track");
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      delay(200);
    }

    //Stanga = prev track
    if (data == 0x01){
      Serial.println("Prev track");
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      delay(200);
    }

    //Clockwise = volume up
    if (data == 0x40){
      Serial.println("Volum +");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      delay(200);
    }

    //Anticlockwise = volume down
    if (data == 0x80){
      Serial.println("Volum -");
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      delay(200);
    }
  }
}