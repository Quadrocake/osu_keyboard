class MechanicalKey {
  public:
    bool pressed;
    bool keyReleased = true;
    char key;
    uint8_t newRecievePin;
    unsigned int releaseDelay = 20;
    unsigned int releaseTimer;
    
    MechanicalKey(uint8_t receivePin, char keyboardKey)  {
      newRecievePin = receivePin;
      key = keyboardKey;
    }

    void mkeyUpdate(bool keyboardActive) {
      pressed = digitalRead(newRecievePin);
      if (pressed == LOW) {
        if (keyReleased) {
          if (keyboardActive)
          {
              Keyboard.press(key);
          }
          keyReleased = false;
        }
        releaseTimer = releaseDelay;
      }
      else {
        if (!keyReleased) {
          if (releaseTimer == 0) {
            Keyboard.release(key);
            keyReleased = true;
          }
          else {
            releaseTimer--;
          }
        }
      }
    }
};
