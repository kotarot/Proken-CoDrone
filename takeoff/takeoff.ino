#include <CoDrone.h>
 
void setup()
{
  Serial.println("start");
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x20, 0xB8, 0x3C, 0xEA, 0x4A, 0x88};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}

void loop()
{
  byte bt1 = digitalRead(11);
  byte bt4 = digitalRead(14);
  byte bt8 = digitalRead(18);
  if (bt1) {
    Serial.println("bt1 on");
  } else {
    Serial.println("bt1 off");
  }
 
  if (bt1)
  {
    CoDrone.FlightEvent(Stop);
  }
 
  if (PAIRING == true)
  {
    YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3));
    THROTTLE  = CoDrone.AnalogScaleChange(analogRead(A4));
    ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5));
    PITCH = CoDrone.AnalogScaleChange(analogRead(A6));
 
    CoDrone.Control();
  }
}

