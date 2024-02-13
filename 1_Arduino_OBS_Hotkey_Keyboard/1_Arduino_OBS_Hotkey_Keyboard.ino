/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
   _ __  ___  _____| | |__  | |  | || |
  | '_ \| \ \/ / _ \ |  __| | |  | || |
  | |_) | |>  <  __/ | |____| |__| || |_
  | .__/|_/_/\_\___|_|______|_____/_____|
  | |
  |_|

  >> https://links.pixeledi.eu <<
  DIY Hotkeys | V1.0 | 02.2024

*/

#include <Keyboard.h>

const byte ledRecord = 6;
const byte ledPause = 9; 

int keypresseddelay = 400;

void checkKeyboard(){
  Keyboard.begin();  //begin keyboard

  if (digitalRead(8) == 1) {
    Keyboard.press('8');
    delay(keypresseddelay);
    Keyboard.releaseAll();
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(8, INPUT_PULLUP);
  // pinMode(3, INPUT_PULLUP);
  // pinMode(4, INPUT_PULLUP);
  // pinMode(7, INPUT_PULLUP);
  pinMode(ledRecord, OUTPUT);
  pinMode(ledPause, OUTPUT);

}

void loop() {
  checkKeyboard();
}
