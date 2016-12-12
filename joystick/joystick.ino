/*****************************************************************
 Control - Analog Joystick Reading
 Use this program to see your joystick analog inputs and mapping values
*******************************************************************/
#include <CoDrone.h>
int Sent_YAW, Sent_THROTTLE, Sent_ROLL, Sent_PITCH;
int Received_YAW, Received_THROTTLE, Received_ROLL, Received_PITCH;
 
void setup()
{
 Serial.begin(115200);
}
 
void loop()
{
 Sent_YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3)); // YAW (turn left or right), port A3, reversed
 Sent_THROTTLE = CoDrone.AnalogScaleChange(analogRead(A4)); // THROTTLE (height), port A4, not reversed
 Sent_ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5)); // ROLL (tilt left or right), port A5, reversed
 Sent_PITCH = CoDrone.AnalogScaleChange(analogRead(A6)); // PITCH (tilt front or back), port A6, not reversed
 Received_YAW = (analogRead(A3));
 Received_THROTTLE = (analogRead(A4));
 Received_ROLL = (analogRead(A5));
 Received_PITCH = (analogRead(A6));
 
 Serial.print("RECIEVED::");
 Serial.print(" APin3: ");
 Serial.print(Received_YAW);
 Serial.print(" APin4: ");
 Serial.print(Received_THROTTLE);
 Serial.print(" APin5: ");
 Serial.print(Received_ROLL);
 Serial.print(" APin6: ");
 Serial.print(Received_PITCH);
 Serial.print(" SENT:: ");
 Serial.print("YAW: ");
 Serial.print(Sent_YAW);
 Serial.print(" THROTTLE: ");
 Serial.print(Sent_THROTTLE);
 Serial.print(" ROLL: ");
 Serial.print(Sent_ROLL);
 Serial.print(" PITCH: ");
 Serial.print(Sent_PITCH);
 Serial.println();
}
 
int CustomScaleChange(int input) {
 int ScaleChange = map(input, 0, 1023, -100, 100);
 const int analogOffset = 10;
 if ((ScaleChange > -1 * analogOffset) && (ScaleChange < analogOffset)) ScaleChange = 0;
 return ScaleChange;
}

