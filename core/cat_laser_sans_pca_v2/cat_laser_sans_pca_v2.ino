//#include <Wire.h>
#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo

// our servo # counter
//uint8_t servonum = 0;
int D0 = 2; // Left eye
int D1 = 3; // Right eye

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int center_high=120;
int base_a=10;
int base_b=170;
int high_a=100;
int high_b=170;


/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */





void traject(){
  int delta_base;
  int delta_high;
  int base;
  int high;
  int base_a=random(30,140);
  int high_a=random(120,160);
  while(check_button()==1){
    int base_b=random(30,140);
    int high_b=random(120,160);
    for( int i =0; i<10; i +=1){
        delta_base=(base_a - base_b)/10;
        delta_high=(high_a - high_b)/10;
        base=base_a-delta_base*i;
        high=high_a-delta_high*i;
        //pwm.setPWM(1, 0, angleToPulse(base) );
        //pwm.setPWM(0, 0, angleToPulse(high) );
        myservo1.write(base);
        myservo0.write(high);
        delay(random(50,500)); //200
        
        }
    base_a=base_b;
    high_a=high_b;
  }
}



void box_drow(void)
{       
        // basso dx
        myservo1.write(base_a);
        myservo0.write(center_high);
        delay(1000);
        // basso sx
        myservo1.write(base_b);
        myservo0.write(center_high);
        delay(1000);
        // alto sx
        myservo1.write(base_b);
        myservo0.write(center_high);
        delay(1000);
        // alto dx
        myservo1.write(base_a);
        myservo0.write(center_high);
        delay(1000);
  }


void setup() { 
//  Serial.begin(9600);
//  Serial.println("16 channel Servo test!");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, HIGH); 
  myservo0.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
 // pwm.begin();
 // pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}


int check_button(void) {
buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    return 1;
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    return 0;
  }
}


void loop() {

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (check_button()) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    traject();
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    box_drow();
  } 
//temp change
//center_high=center_high+5;

//traject();
//base();
//box_drow();
}
