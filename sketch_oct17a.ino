#include <CapacitiveSensor.h>
#include <Keyboard.h>

#include "capacitiveKey.h"
#include "mechanicalKey.h"

#define DISABLE_PIN 15

void setup() {
  Keyboard.begin();
  pinMode(DISABLE_PIN, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}
//capacitive keys:
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
//mech keys:
MechanicalKey mkey0 = MechanicalKey(
  21,   //Mechanical pin
  'd'
);
MechanicalKey mkey1 = MechanicalKey(
  19,   //Mechanical pin
  'f'
);
MechanicalKey mkey2 = MechanicalKey(
  14,   //Mechanical pin
  'j'
);
MechanicalKey mkey3 = MechanicalKey(
  10,   //Mechanical pin
  'k'
);

void loop() {
  bool keyboardActive = digitalRead(DISABLE_PIN);
  
mkey0.mkeyUpdate(keyboardActive);
mkey1.mkeyUpdate(keyboardActive);
mkey2.mkeyUpdate(keyboardActive);
mkey3.mkeyUpdate(keyboardActive);

//key0.keyUpdate(keyboardActive);
//key1.keyUpdate(keyboardActive);

//code for additional modificator keys
//  key2.keyUpdate(keyboardActive);
//    if (!key2.keyReleased)
  //  {
    //key0mod.keyUpdate(keyboardActive);
    //key1mod.keyUpdate(keyboardActive);
    //}
    //else
    //{
  //key0.keyUpdate(keyboardActive);
  //key1.keyUpdate(keyboardActive);
    //}
}
