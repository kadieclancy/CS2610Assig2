
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  // photo cell
  Serial.print(analogRead(A0));
  Serial.print("\t");
  
  // force sensors
  Serial.print(analogRead(A1));
  Serial.print("\t");
  Serial.print(analogRead(A2));
  Serial.print("\t");
  Serial.println();
  delay(2);
}
