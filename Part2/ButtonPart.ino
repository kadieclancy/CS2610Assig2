const int buttonPin = 13;     // the number of the pushbutton pin
const int ledPin1 = 1;      // the number of the LED pin
const int ledPin2 = 2;
const int ledPin3 = 3;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int previousState = -1;
int ledToLight = 0;
 
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    if (previousState == buttonState)
    {
      
      }
    else
    {
      ledToLight = incrementLed(ledToLight);
      lightALed(ledToLight);
    }
    //digitalWrite(ledPin, HIGH);
  } else {
  }
  previousState = buttonState;
}

int incrementLed(int ledNumber_)
{
  ledNumber_ = ledNumber_ + 1;
  if(ledNumber_ > 3)
  {
    ledNumber_ = 0;
    }
    return ledNumber_;
}

void lightALed(int ledNumber_)
{
  if(ledNumber_ == 0)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    
    }
  if(ledNumber_ == 1)
  {
    digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    }
  if(ledNumber_ == 2)
  {
    digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin3, LOW);
    }
  if(ledNumber_ == 3)
  {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    }
  
  }

