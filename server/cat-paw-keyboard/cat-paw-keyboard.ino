#include <BleKeyboard.h>

const char* deviceName = "ESP32 Keyboard";  
const char* deviceManufacturer = "ESP32";   

BleKeyboard bleKeyboard(deviceName, deviceManufacturer, 100); 

void setup() {
    Serial.begin(115200);
    bleKeyboard.begin();  
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (digitalRead(BUTTON_PIN_1) == LOW) {
      bleKeyboard.press('a');  
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_2) == LOW) {
      bleKeyboard.press('b'); 
      bleKeyboard.releaseAll();
    }

    if (digitalRead(BUTTON_PIN_3) == LOW) {
      bleKeyboard.press(KEY_RETURN);
      bleKeyboard.releaseAll();
    }
  }
  delay(10); 
}
