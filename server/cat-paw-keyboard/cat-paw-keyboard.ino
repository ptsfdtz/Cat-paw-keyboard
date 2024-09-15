#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Keyboard", "ESP32", 100);

#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 5
#define BUTTON_PIN_3 12
#define BUTTON_PIN_4 13
#define BUTTON_PIN_5 14

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

    if (digitalRead(BUTTON_PIN_1) == LOW) {
      Serial.println("Button 1 pressed");
      bleKeyboard.press('z');
      Serial.println("Sent: z");
      delay(100);
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_2) == LOW) {
      Serial.println("Button 2 pressed");
      bleKeyboard.press('x');
      Serial.println("Sent: x");
      delay(100);
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_3) == LOW) {
      Serial.println("Button 3 pressed");
      bleKeyboard.press('c');
      Serial.println("Sent: c");
      delay(100);
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_4) == LOW) {
      Serial.println("Button 4 pressed");
      bleKeyboard.press('v');
      Serial.println("Sent: v");
      delay(100);zzzz
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_5) == LOW) {
      Serial.println("Button 5 pressed");
      bleKeyboard.press(KEY_LEFT_CTRL);
      Serial.println("Sent: KEY_LEFT_CTRL");
      delay(100);   
       }

  } 
  else {
    Serial.println("BLE not connected");
  }

  delay(10);
}