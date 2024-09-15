#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Keyboard", "ESP32", 100);

#define BUTTON_PIN_1 12
#define BUTTON_PIN_2 13
#define BUTTON_PIN_3 14

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);

  bleKeyboard.begin();
  Serial.println("BLE Keyboard started");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    Serial.println("BLE connected");

    if (digitalRead(BUTTON_PIN_1) == LOW) {
      Serial.println("Button 1 pressed");
      bleKeyboard.press('a');
      Serial.println("Sent: a");
      delay(100);
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_2) == LOW) {
      Serial.println("Button 2 pressed");
      bleKeyboard.press('b');
      Serial.println("Sent: b");
      delay(100);
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_3) == LOW) {
      Serial.println("Button 3 pressed");
      bleKeyboard.press(KEY_RETURN);
      Serial.println("Sent: RETURN");
      delay(100);
      bleKeyboard.releaseAll();
    }
  } else {
    Serial.println("BLE not connected");
  }

  delay(10);
}