#include <CoDrone.h>

int HAS_STARTED;
unsigned long StartTime;

void setup() {
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x20, 0xB8, 0x3C, 0xEA, 0x4A, 0x88};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);

  HAS_STARTED = 0;
}
 
void loop() {
  byte bt1 = digitalRead(11);
  byte bt8 = digitalRead(18);
 
  if (bt1) {
    CoDrone.FlightEvent(Stop);
    CoDrone.Buzz(5000, 7);
    HAS_STARTED = 1;
  }
 
  if (!bt1 && bt8 && HAS_STARTED == 0) {
    HAS_STARTED = 1;

    // Start music
    CoDrone.Buzz(4000, 10);
    CoDrone.Buzz(8000, 10);
    CoDrone.Buzz(2000, 2);

    delay(200);
    StartTime = millis();
  }
 
  if (HAS_STARTED == 1) {
    if (millis() - StartTime < 1000) {
      THROTTLE = 50;
      CoDrone.Control();
    }
    else if (millis() - StartTime < 3000) {
      THROTTLE = -10;
      PITCH = 40;
      //ROLL = 0;
      CoDrone.Control();
    }
    else if (millis() - StartTime < 7000) {
      THROTTLE = -10;
      //PITCH = 0;
      ROLL = 50;
      CoDrone.Control();
    }
    else if (millis() - StartTime < 9000) {
      THROTTLE = -10;
      PITCH = -40;
      ROLL = 20;
      CoDrone.Control();
    }
    else if (millis() - StartTime < 11000) {
      THROTTLE = -10;
      //PITCH = 0;
      ROLL = -50;
      CoDrone.Control();
    }
    else {
      CoDrone.FlightEvent(Landing);
    }
  }
}

