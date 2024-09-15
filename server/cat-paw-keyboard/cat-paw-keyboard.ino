#include "header.h"

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);

  bleKeyboard.begin();
  Serial.println("BLE Keyboard started");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    Serial.println("BLE connected");

    checkContinuousPress(BUTTON_PIN_1, 'z');
    checkContinuousPress(BUTTON_PIN_2, 'x');
    checkContinuousPress(BUTTON_PIN_3, 'c');
    checkContinuousPress(BUTTON_PIN_4, 'v');
    checkContinuousPress(BUTTON_PIN_5, KEY_LEFT_CTRL); 
    
  } else {
    Serial.println("BLE not connected");
  }

  delay(10);
}

void checkContinuousPress(int pin, char key) {
  if (digitalRead(pin) == LOW) {
    bleKeyboard.press(key);
    Serial.printf("Sent: %c\n", key);
    delay(100); 
  } else {
    bleKeyboard.release(key);
  }
}
