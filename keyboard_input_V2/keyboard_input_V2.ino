//const int DRIFT = A4;
const int FORWARD = A1;
const int SPECIAL = A2;
const int LEFT = A3;
const int RIGHT = A0;

#define LEDG1 6
#define LEDG2 5
#define LED3  4
#define LED4  3
#define LED5  2

int currTime = 0;
bool dropPeak = true;//Has it dropped from its peak? int currTime = millis();
int pastTime = 0;

int holdTime = 350;

int slow = 1000;
int fast = 500;
int hyper = 350;
int ludicrous = 300; //Shoutout to the spaceball fans
int maximum_overdrive = 150;

void setup() {
  Serial.begin(9600);
  pinMode(FORWARD,  INPUT);
  pinMode(LEFT,     INPUT);
  pinMode(RIGHT,    INPUT);
  pinMode(SPECIAL,  INPUT);

  pinMode(LEDG1, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

}

void loop() {
 //  Serial.print("L:"+analogRead(LEFT));
   // Serial.print("R:"+analogRead(RIGHT));
   
    
  //--------------------INPUTS------------------------------
  //if (digitalRead(FORWARD) == HIGH && digitalRead(FORWARD) == HIGH && digitalRead(FORWARD) == HIGH) {
    //Serial.println("Forwardboost:");
    //}
  //else 
bool drive=digitalRead(FORWARD);
  
  if (drive == HIGH && dropPeak == true) { //THIS MAY BREAK CHANGE TO analogRead

    pastTime = currTime;
    currTime = millis();
    drive=LOW;
    dropPeak = false;

    delay(2);
  } else{
  //else if (digitalRead(FORWARD) == LOW) { //THIS MAY BREAK CHANGE TO analogRead
    drive=LOW;
    dropPeak = true;
  }

  if (digitalRead(LEFT) == HIGH) {
    Serial.println("Left:");//It doesn't matter what you print. Just have a colon at the end to make it easier to parse the string.
    delay(15);
  }

  if (digitalRead(RIGHT) == HIGH) {
    Serial.println("Right:");
    delay(15);
  }

  if (digitalRead(SPECIAL) == HIGH) {
    Serial.println("Special:");
    delay(15);
  }
  
  //if (currTime+350>millis()){
    //Serial.println("Forward:");   
   // Serial.println("Forward:Extra");
   // delay(50);
  //  }

  ledSpeed(currTime, pastTime); //Set the speed lights
}
//-------------------------------LED----------------------------
void ledSpeed(int CT, int PT) {
  int deltaT = CT - PT;
  if (deltaT >= slow) {
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LEDG2, LOW);
    digitalWrite(LEDG1, LOW);
  } 
  else if (deltaT < maximum_overdrive) { //
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDG1, HIGH);
  }
  else if (deltaT < ludicrous) {
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LEDG2, HIGH);
    digitalWrite(LEDG1, LOW);
  }
  else if (deltaT < hyper) {
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LEDG2, LOW);
    digitalWrite(LEDG1, LOW);
  }
 else if (deltaT < fast) {
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LEDG2, LOW);
    digitalWrite(LEDG1, LOW);            
  }
  else if (deltaT < slow) {
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LEDG2, LOW);
    digitalWrite(LEDG1, LOW);
  }
  else {
  }
}
/*Add or subtract to the code for your application. Just make sure you do a Serial.println()
  with a colon when you want to simulate a keypress.
*/
