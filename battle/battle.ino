#include <CoDrone.h>
void setup()
{
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x20, 0xB8, 0x3C, 0xEA, 0x4A, 0x88};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
  //CoDrone.AutoConnect(NearbyDrone);
  CoDrone.DroneModeChange(Flight);
  CoDrone.BattleBegin(TEAM_GREEN);     //  Choose a team : TEAM_RED  / TEAM_BLUE
}                                     //  TEAM_GREEN  / TEAM_YELLOW / FREE_PLAY

void loop()
{
  CoDrone.BattleReceive();

  byte bt1 = digitalRead(11);
  byte bt4 = digitalRead(14);
  byte bt8 = digitalRead(18);

  if (bt1 && !bt4 && !bt8)
  {
    CoDrone.FlightEvent(Stop);
  }

  if (!bt1 && !bt4 && bt8)
  {
    CoDrone.BattleShooting();
  }

  //if (!bt1 && bt4 && !bt8)
  //{
  //  CoDrone.FlightEvent(Landing);
  //}

  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3));
  THROTTLE  = CoDrone.AnalogScaleChange(analogRead(A4));
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5));
  PITCH = CoDrone.AnalogScaleChange(analogRead(A6));
  CoDrone.Control(SEND_INTERVAL);

}

