void setup() {
 Serial.begin(115200);
 delay(1000);
 Serial.println("Test Sensors");
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(14, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
}
 
void loop() {
  int D1 = digitalRead(11);
  int D2 = digitalRead(12);
  int D3 = digitalRead(13);
  int D4 = digitalRead(14);
  int D5 = digitalRead(16);
  int D6 = digitalRead(17);
  int D7 = digitalRead(18);
  int A1 = analogRead(19);
  int A2 = analogRead(20);
  int A3 = analogRead(21);
 
  Serial.print("Bottom Sensors: ");
  Serial.print(D1);
  Serial.print(" ");
  Serial.print(D2);
  Serial.print(" ");
  Serial.print(D3);
  Serial.print(" ");
  Serial.print(D4);
  Serial.print(" ");
  Serial.print(D5);
  Serial.print(" ");
  Serial.print(D6);
  Serial.print(" ");
  Serial.print(D7);
  Serial.print(" ");
  Serial.print("  Top Sensors: ");
  Serial.print(A1);
  Serial.print(" ");
  Serial.print(A2);
  Serial.print(" ");
  Serial.println(A3);
}

