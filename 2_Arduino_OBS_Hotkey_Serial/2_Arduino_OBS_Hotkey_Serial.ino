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


void setup() {
  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  // pinMode(3, INPUT_PULLUP);
  // pinMode(4, INPUT_PULLUP);
  // pinMode(7, INPUT_PULLUP);
  pinMode(ledRecord, OUTPUT);
  pinMode(ledPause, OUTPUT);

  //Serial.println("start");

}

void loop() {
if (Serial.available() > 0) {

    String received_data = Serial.readStringUntil('\n');  // Lese die empfangenen Daten bis zum Zeilenumbruch
    if (received_data == ("pause")) {
      digitalWrite(ledPause, HIGH);
      delay(3000);
      digitalWrite(ledPause, LOW);
    }
    else if (received_data == ("record")) {
      digitalWrite(ledRecord, HIGH);
      delay(3000);
      digitalWrite(ledRecord, LOW);
    }
  }
}
