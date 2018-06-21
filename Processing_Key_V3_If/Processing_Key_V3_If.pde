import processing.serial.*; //Serial data
import java.awt.AWTException; 
import java.awt.Robot; 
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.KeyStroke;
Serial MyPort;                                
String KeyString = "";
int lastTime=0; //Store a time.
int currTime=0; //check to time now
int pressTime=300;
boolean forwardPressed=false;
void setup()
{
 System.out.println("Hi");
  size(200, 200);
  MyPort = new Serial(this, "COM5", 57600);// My Arduino is on COM3. Enter the COM on which your Arduino is on.
  MyPort.bufferUntil('\n');
}
void draw() {//Not really necessary
  background(0, 0, 0);
  fill(255, 0, 0);
  text("Press any key", 100, 175);
}
void serialEvent(Serial MyPort)throws Exception {
  KeyString = MyPort.readStringUntil('\n');
  //KeyString = KeyString.substring(0, KeyString.indexOf(':'));//The string is split. the whole string leaving the colon is taken
  //System.out.println(KeyString);//prints the serial string for debugging purpose
  String[] inputStr=KeyString.split(":");
  int i=0;
  Robot Arduino = new Robot();//Constructor of robot class
  //System.out.println("index value=" +i+" Array Value="+inputStr[i]);
  if (inputStr[i].equals("F")) { 
     ++i;
     //System.out.println("Forward");
   Arduino.keyPress(KeyEvent.VK_W);
    //delay(18);
   }
    //System.out.println("index value=" +i+" Array Value="+inputStr[i]);
  if (inputStr[i].equals("L")) {
    ++i;
    Arduino.keyPress(KeyEvent.VK_A);//presses up key
    //delay(18);
  }
   //dSystem.out.println("index value=" +i+" Array Value="+inputStr[i]);
   if (inputStr[i].equals("R")) {
     ++i;
    Arduino.keyPress(KeyEvent.VK_D);
    //delay(18);
   }
   if (inputStr[i].equals("S")) {   
     ++i;
    Arduino.keyPress(KeyEvent.VK_C);
    //delay(18);
   }
  if (inputStr[i].equals("D")) { 
    ++i;
    Arduino.keyPress(KeyEvent.VK_Z);
   //delay(18);
  }
  if (inputStr[i].equals("B")) { 
    ++i;
    Arduino.keyPress(KeyEvent.VK_S);
   //delay(18);
  }
   
   delay(17);
   Arduino.keyRelease(KeyEvent.VK_A);//releases up key
   Arduino.keyRelease(KeyEvent.VK_C);
   Arduino.keyRelease(KeyEvent.VK_S);  
   Arduino.keyRelease(KeyEvent.VK_T);
   Arduino.keyRelease(KeyEvent.VK_D);
}
