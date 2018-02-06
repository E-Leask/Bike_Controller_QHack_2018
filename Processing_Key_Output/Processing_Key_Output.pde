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
  MyPort = new Serial(this, "COM4", 115200);// My Arduino is on COM3. Enter the COM on which your Arduino is on.
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
  case "Left" :
    Arduino.keyPress(KeyEvent.VK_ALT);//presses up key.adddddddddddcccccccccccccccbbbbbbbbbbbbbaaaaaaaaa
    Arduino.keyRelease(KeyEvent.VK_ALT);//releases up key
    break;
  case "Right" :
    Arduino.keyPress(KeyEvent.VK_CONTROL);
    Arduino.keyRelease(KeyEvent.VK_CONTROL);      
    break;
  case "Special" :
    Arduino.keyPress(KeyEvent.VK_SPACE);
    Arduino.keyRelease(KeyEvent.VK_SPACE);      
    break;
    //case "Drift" :
   // Arduino.keyPress(KeyEvent.VK_TAB);
   // Arduino.keyRelease(KeyEvent.VK_TAB);      
   // break;
  case "Forward" :
    Arduino.keyPress(KeyEvent.VK_SHIFT);
    //lastTime=millis()+pressTime;
   //forwardPressed=true;
   Arduino.keyRelease(KeyEvent.VK_SHIFT);
    break;
  }
   //System.out.println(millis());
  //currTime=millis();
  // System.out.println("lastTime: "+lastTime+" currentTime: "+millis()+ " pressed? "+forwardPressed);
 // if (lastTime<millis()&& forwardPressed==true) {
   // Arduino.keyRelease(KeyEvent.VK_D);
   // forwardPressed=false;
 //}
 //System.out.println("lastTime: "+lastTime+" currentTime: "+millis()+ " pressed? "+forwardPressed);

}