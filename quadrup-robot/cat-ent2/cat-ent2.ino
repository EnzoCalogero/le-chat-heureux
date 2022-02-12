
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)
uint8_t servonum = 0;

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   
   return pulse;
}


void next_status( int status[])
{
  for(int i=0;i<8;i++){
//  Serial.println(i);
//  Serial.println(status[i]);
 switch (i) {

 //##################### Legs ############################################## 
          case 0: //leg front right
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(30));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(120));
                 break;
          case 1: //leg front left
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(30));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(45));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(100));
                break;
          case 2: //leg back right
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(45));

                break;
          case 3: //leg back left
                if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(60));
                break;
////######################## hips    ###################  
          case 4: //leg front right
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(50));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(160));
                break;
          case 5: //leg front left
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(60));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(40));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(140));
                break;
          case 6: //leg back right
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(160));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(70));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(40));
                break;
          case 7: //leg back left
                if(status[i] == 0) pwm.setPWM(i, 0, angleToPulse(90));
                else if(status[i] == 2) pwm.setPWM(i, 0, angleToPulse(150));
                else if(status[i] == 1) pwm.setPWM(i, 0, angleToPulse(120));
                else if(status[i] == -1) pwm.setPWM(i, 0, angleToPulse(600));
                else if(status[i] == -2) pwm.setPWM(i, 0, angleToPulse(40));
                break;
          }
  }
}  

void up_down(void) {
int a[8] = { 0, 0, 0, 0, -2, -2, -2, -2};
//next_status(a);
for (int k=-2; k < 2; k++){
  for(int i=4;i<8;i++){ // Posizione sull'array
     a[i]=k;
    }
  next_status(a);
  delay(500);
}
  
  for (int k=1; k > -2; k--){
  for(int i=4;i<8;i++){ // Posizione sull'array
     a[i]=k;
    }
  next_status(a);
  delay(500);
  }

}


void step1(void) {
int a[8] = { 0, 0, 0, 0, -1, -1, -1, -1};
next_status(a);
delay(250);
//int b[8] = { 1, 0, 0, 0, 2, 2, 0, 0};
//next_status(b);
delay(250); 
  }


void setup() {
 // Serial.begin(9600);
 // Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
// step1();
}


void loop(void) { 
up_down();
}
