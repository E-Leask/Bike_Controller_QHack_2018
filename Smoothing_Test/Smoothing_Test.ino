const int LEFT = A0;
const int FORWARD = A1;
const int RIGHT = A2;
const int SPECIAL = A3;
const int DRIFT = A4;


int delayTime = 500;
long currTime = 0;
long millisSec = 0;
int delayMillisSec=25;
bool firstInput = true;

bool printVal[] = {false, false, false, false, false};
// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.

const int numReadings = 3;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average



void setup() {
  Serial.begin(57600);
  pinMode(FORWARD,  INPUT);
  pinMode(LEFT,     INPUT);
  pinMode(RIGHT,    INPUT);
  pinMode(SPECIAL,  INPUT);


  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);

  //delay(delayTime+50);
  // initialize serial communication with computer:

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // if(millisSec<millis()){
  //Serial.println(average);
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(FORWARD);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println(average);

  if (average < 1000 ) { //THIS MAY BREAK CHANGE TO analogRead
    currTime = millis();

  }

  if ((currTime + delayTime) > millis() && millis() > (delayTime + 50)) {
    // Serial.print("Current Time:");
    //Serial.print(currTime);
    //Serial.print(" Millis():");
    //Serial.println(millis());
    checkIfFirstInput();
    //Serial.print("F:");
    printVal[0] = true;
  }
  if (digitalRead(LEFT) == LOW) {
    checkIfFirstInput();
    //Serial.print("L:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
    printVal[1] = true;

  }

  if (digitalRead(RIGHT) == LOW) {
    checkIfFirstInput();
    //    Serial.print("R:");
    printVal[2] = true;
  }
  if (digitalRead(SPECIAL) == LOW) {
    checkIfFirstInput();
    //Serial.print("S:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
    printVal[3] = true;
  }
  if (digitalRead(DRIFT) == LOW) {
    checkIfFirstInput();
    //Serial.print("S:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
    printVal[4] = true;
  }
  //Serial.print(0);
  //Serial.print(",");
  //Serial.print(100);
  //Serial.print(",");
  //Serial.println(average);

  if (millisSec < millis()) {
    if (firstInput == false) {
      if (printVal[0] == true) {
         Serial.print("F:");
      }  
      if (printVal[1] == true) {
         Serial.print("L:");
      } 
      if (printVal[2] == true) {
         Serial.print("R:");
      }  
      if (printVal[3] == true) {
        Serial.print("S:");
      } 
      if (printVal[4] == true) {
        Serial.print("D:");
      }
      Serial.println("N");
    }
//    for (int i = 0; i < 5; ++i)
//    Serial.println(printVal[i]);
    millisSec=millis()+delayMillisSec;
    firstInput = true;
    for (int i = 0; i < 5; ++i)
    printVal[i] = false;
    
  }
}
//--------------------------FIRST INPUT?----------------------
void checkIfFirstInput() {
  if (firstInput == true) {
    firstInput = false;
  }

}

