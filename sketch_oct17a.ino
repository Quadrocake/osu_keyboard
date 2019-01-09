#include <CapacitiveSensor.h>
#include <Keyboard.h>

#include "capacitiveKey.h"

#define DISABLE_PIN 15

bool butReleased = true;
unsigned int butreleaseTimer;

void setup() {
  Keyboard.begin();
  pinMode(DISABLE_PIN, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
}

CapacitiveKey key0 = CapacitiveKey(
  2,    //Capacitive Send Pin
  7,    //Capacitive Sense Pin
  5,    //Capacitive Treshold
  'z'
);
CapacitiveKey key1 = CapacitiveKey(
  4,    //Capacitive Send Pin
  8,    //Capacitive Sense Pin
  5,    //Capacitive Treshold
  'x'
);
CapacitiveKey key2 = CapacitiveKey(
  21,    //Capacitive Send Pin
  18,    //Capacitive Sense Pin
  3,    //Capacitive Treshold
  KEY_LEFT_SHIFT
);
CapacitiveKey key0mod = CapacitiveKey(
  2,    //Capacitive Send Pin
  7,    //Capacitive Sense Pin
  3,    //Capacitive Treshold
  KEY_F1
);
CapacitiveKey key1mod = CapacitiveKey(
  4,    //Capacitive Send Pin
  8,    //Capacitive Sense Pin
  3,    //Capacitive Treshold
  KEY_F2
);

void loop() {
  bool keyboardActive = digitalRead(DISABLE_PIN);

  if (digitalRead(16) == LOW) {
    if (butReleased) {
      if (keyboardActive)
          {
              Keyboard.press('a');
          }
          butReleased = false;
        }
        butreleaseTimer = 20;
  }
      else {
        if (!butReleased) {
          if (butreleaseTimer == 0) {
            Keyboard.release('a');
            butReleased = true;
          }
          else {
            butreleaseTimer--;
          }
        }
      }

//  key2.keyUpdate(keyboardActive);
//    if (!key2.keyReleased)
  //  {
    //key0mod.keyUpdate(keyboardActive);
    //key1mod.keyUpdate(keyboardActive);
    //}
    //else
    //{
  key0.keyUpdate(keyboardActive);
  key1.keyUpdate(keyboardActive);
    //}
}
