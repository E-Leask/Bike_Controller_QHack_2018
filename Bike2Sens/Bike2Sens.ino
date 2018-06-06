#define inp1 1;
#define inp2 2;
long dif[3] = {1, 1, 1};
long t[3];
int v[3] = {0, 0, 0};
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inp1, INPUT);
  pinMode(inp2, INPUT);
  attachInterrupt(digitalPinToInterrupt(inp1), upd81, RISING);
  attachInterrupt(digitalPinToInterrupt(inp2), upd82, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (dif[0] != dif[1]) {

    if (dif[1] < dif[2]) {

    }
    else {

    }
  }
  //on interrupt
}

void upd81() {
  t[0] = t[1];//Rotating times
  t[1] = t[2];
  t[2] = millis(); //newest time

  dif[1] = t[2] - t[1];
  dif[2] = t[3] - t[2];
  //  v[0] = v[1];
  //  v[1] = v[2];
  //  v[2] = inp1;
}
void upd82() {
  t[0] = t[1];
  t[1] = t[2];
  t[2] = millis();
  dif[1] = t[2] - t[1];
  dif[2] = t[3] - t[2];
//  v[0] = v[1];
//  v[1] = v[2];
//  v[2] = inp2;
}
void output{
  if (t[1] < t[2]) { //short, long
    //counter clockwise spin//reverse
  }
  else{//long,short
    //
  }
}
