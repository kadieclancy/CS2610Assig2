const int ledPin0 = 0; 
const int ledPin1 = 1; 
const int ledPin2 = 2; 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a 500ms
  digitalWrite(ledPin0, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a 500ms
  
  digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a 500ms
  
  digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a 500ms
  digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a 500ms
}
