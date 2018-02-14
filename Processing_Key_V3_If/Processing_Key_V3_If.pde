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
  size(700, 500);
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
  KeyString = KeyString.substring(0, KeyString.indexOf(':'));//The string is split. the whole string leaving the colon is taken
  System.out.println(KeyString);//prints the serial string for debugging purpose
  Robot Arduino = new Robot();//Constructor of robot class
  switch(KeyString) {
  case "L" :
    Arduino.keyPress(KeyEvent.VK_A);//presses up key
    delay(18);
    Arduino.keyRelease(KeyEvent.VK_A);//releases up key
    break;
  case "R" :
    Arduino.keyPress(KeyEvent.VK_C);
    delay(18);
    Arduino.keyRelease(KeyEvent.VK_C);      
    break;
  case "S" :
    Arduino.keyPress(KeyEvent.VK_S);
    delay(18);
    Arduino.keyRelease(KeyEvent.VK_S);      
    break;
  case "D" :
    Arduino.keyPress(KeyEvent.VK_T);
    delay(18);
    Arduino.keyRelease(KeyEvent.VK_T);      
    break;
  case "F" :
    Arduino.keyPress(KeyEvent.VK_D);
    delay(18);
    Arduino.keyRelease(KeyEvent.VK_D);
    break;
  }
}