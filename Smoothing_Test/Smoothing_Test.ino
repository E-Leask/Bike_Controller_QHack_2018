const int LEFT = A0;
const int FORWARD = A1;
const int RIGHT = A2;
const int SPECIAL = A3;
const int DRIFT = A4;


int delayTime=750;
long currTime =0;
bool firstInput=true;


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
   Serial.begin(9600);
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

 if (average <1000 ) { //THIS MAY BREAK CHANGE TO analogRead
    currTime = millis();
   
  }

   if ((currTime + delayTime) > millis()&&millis()>(delayTime+50)) {
  // Serial.print("Current Time:");
    //Serial.print(currTime);
    //Serial.print(" Millis():");
    //Serial.println(millis());
    checkIfFirstInput();
    Serial.print("F:");
  }
   if (digitalRead(LEFT) == LOW) {
    checkIfFirstInput();
    Serial.print("L:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
  }

  if (digitalRead(RIGHT) == LOW) {
    checkIfFirstInput();
    Serial.print("R:");
  }
   if (digitalRead(SPECIAL) == LOW) {
    checkIfFirstInput();
    Serial.print("S:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
  }
 //Serial.print(0);
  //Serial.print(",");
  //Serial.print(100);
  //Serial.print(",");
  //Serial.println(average);
  if(firstInput==false){
  Serial.println("N");
  }
  firstInput=true;
  delay(25);        // delay in between reads for stability
}
//--------------------------FIRST INPUT?----------------------
void checkIfFirstInput() {
  if (firstInput == true) {
  firstInput = false;}
  
}

