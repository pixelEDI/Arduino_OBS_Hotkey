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

enum State {
  IDLE,
  RECORD,
  PAUSE,
  RESUME,
  STOP
} state;

void checkKeyboard(){
  Keyboard.begin();  //begin keyboard

  if (digitalRead(8) == 1) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('8');
    delay(keypresseddelay);
    Keyboard.releaseAll();
  }
  else if (digitalRead(3) == 1) { 
    Keyboard.press(KEY_LEFT_ALT);                      
    Keyboard.press('5');
    Keyboard.releaseAll();
    delay(keypresseddelay);
  }
  else if (digitalRead(4) == 1) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('4');
    delay(keypresseddelay);
    Keyboard.releaseAll();

  }
  else if (digitalRead(7) == 1) {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('7');
    delay(keypresseddelay);
    Keyboard.releaseAll();

  }
}

void checkSerialFromPythonAndOBS(){
   if (Serial.available() > 0) {
    String received_data = Serial.readStringUntil('\n');  // Lese die empfangenen Daten bis zum Zeilenumbruch
    if (received_data == ("stop")) {
      state = STOP;
    } else if (received_data == ("record")) {
      state = RECORD;
    } else if (received_data == ("pause")) {
      state = PAUSE;
    } else if (received_data == ("resume")) {
      state = RESUME;
    }
    
    allLEDsOff();
  }
}

void allLEDsOff() {
  analogWrite(ledRecord, 0);
  analogWrite(ledPause, 0);
}

void setup() {
  Serial.begin(115200);

  pinMode(8, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(ledRecord, OUTPUT);
  pinMode(ledPause, OUTPUT);

  //Serial.println("start");
  state = IDLE;
}

void loop() {

  checkSerialFromPythonAndOBS();
  checkKeyboard();

  switch (state) {
    case IDLE:
      //nothing to do :)
      break;

    case STOP:
      allLEDsOff();
      break;
    case RECORD:
      analogWrite(ledRecord, 15);
      break;
    case PAUSE:
      analogWrite(ledPause, 15);
      break;
    case RESUME:
      analogWrite(ledRecord, 15);
      break;
  }
}
