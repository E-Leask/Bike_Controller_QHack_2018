const int LEFT = A0;
const int INP1 = A1;
const int INP2 = A5;
const int RIGHT = A2;
const int SPECIAL = A3;
const int DRIFT = A4;

long dif[3] = {1, 1, 1};
long t[3];
byte v[3];
int i = 0;

int delayTime = 500;
long currTime = 0;
long millisSec = 0;
int delayMillisSec = 25;
bool firstInput = true;

bool printVal[] = {false, false, false, false, false, false};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(INP2, INPUT);
  pinMode(INP1,  INPUT);
  pinMode(LEFT,     INPUT);
  pinMode(RIGHT,    INPUT);
  pinMode(SPECIAL,  INPUT);
  pinMode(DRIFT,    INPUT);

  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);

  attachInterrupt(digitalPinToInterrupt(INP1), upd81, RISING);
  attachInterrupt(digitalPinToInterrupt(INP2), upd82, RISING);
}

void loop() {
  if (!digitalRead(INP1) ) { //THIS MAY BREAK CHANGE TO analogRead
    currTime = millis();
  }

  if ((currTime + delayTime) > millis() && millis() > (delayTime + 50)) {
    checkIfFirstInput();
    printVal[0] = true;
  }
  if (digitalRead(LEFT) == LOW) {
    checkIfFirstInput();
    //Serial.print("L:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
    printVal[1] = true;
  }
  if (digitalRead(RIGHT) == LOW) {
    checkIfFirstInput();
    printVal[2] = true;
  }
  if (digitalRead(SPECIAL) == LOW) {
    checkIfFirstInput();
    printVal[3] = true;
  }
  if (digitalRead(DRIFT) == LOW) {
    checkIfFirstInput();
    printVal[4] = true;
  }
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
      if(printVal[5} == true){
        Serial.print("B:");
      }
      Serial.println("N");
    }
    millisSec = millis() + delayMillisSec;
    firstInput = true;
    for (int i = 0; i < 6; ++i)
      printVal[i] = false;
    //on interrupt
  }

  void upd81() {
    if (v[2] != INP1) {
      t[0] = t[1];//Rotating times
      t[1] = t[2];
      t[2] = millis(); //newest time

      dif[1] = t[2] - t[1];
      dif[2] = t[3] - t[2];

      v[0] = v[1];
      v[1] = v[2];
      v[2] = INP1;
    }
  }
  void upd82() {
    if (v[2] != INP2) {
      t[0] = t[1];
      t[1] = t[2];
      t[2] = millis();
      dif[1] = t[2] - t[1];
      dif[2] = t[3] - t[2];
      v[0] = v[1];
      v[1] = v[2];
      v[2] = INP2;
    }
  }
  void output{
    
    if (dif[1] < dif[2]) {//forward
    printVal[0]=true;
    }
    else if(dif[2] < dif[1]){
    printVal[5]=true;  
    }
if(dif[1]==dif[2]){
  println("dif1=dif2");
} 
}
void checkIfFirstInput() {
  if (firstInput == true) {
    firstInput = false;
  }

}

