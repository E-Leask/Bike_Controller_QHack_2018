#include <Keyboard.h>
// constants won't change. They're used here to set pin numbers:
const int buttonPin = A0;     // the number of the pushbutton pin

// variables will change:


void setup() {
  Keyboard.begin();
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin,HIGH);
}

void loop() {
  // read the state of the pushbutton value:

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println(digitalRead(buttonPin));
      Serial.println("hi");
  
  } else {
    // turn LED off:
 
    
  }
  delay(50);
}
