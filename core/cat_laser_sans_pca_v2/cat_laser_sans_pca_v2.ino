#include <Servo.h>
// our servo # counter
Servo myservo0;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo
int D0 = 2; // Left eye
int D1 = 3; // Right eye
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
// states variables
//int delta_x = 40;
int high_center;
int lateral_x;
int base_l=90;

void traject(){
high_center = analag_read_h();
lateral_x = analag_read_x();
  int delta_base;
  int delta_high;
  int base;
  int high;
  int base_a=random(base_l - lateral_x, base_l + lateral_x);
  int high_a=random(high_center - 30, high_center + 30 );
  while(check_button()==1){
    int base_b=random(base_l - lateral_x, base_l + lateral_x);
    int high_b=random(high_center - 30, high_center + 30);
    for( int i =0; i<10; i +=1){
        delta_base=(base_a - base_b)/10;
        delta_high=(high_a - high_b)/10;
        base=base_a-delta_base*i;
        high=high_a-delta_high*i;
        myservo1.write(base);
        myservo0.write(high);
        delay(random(50,500)); //200
        }
    base_a=base_b;
    high_a=high_b;
  }
}

void box_drow1(void)
{       
        high_center = analag_read_h();
        lateral_x = analag_read_x();
        // basso dx
        myservo1.write(base_l + lateral_x);
        myservo0.write(high_center);
        delay(500);
        // basso sx
        high_center = analag_read_h();
        lateral_x = analag_read_x();
        myservo1.write(base_l-lateral_x);
        myservo0.write(high_center);
        delay(500);
        // alto sx
 //       high_center = analag_read_h();
 //       lateral_x = analag_read_x();
 //       myservo1.write(base_l-lateral_x);
 //       myservo0.write(high_center+30);
 //       delay(500);
 //       high_center = analag_read_h();
 //       lateral_x = analag_read_x();
 //       myservo1.write(base_l+lateral_x);
 //       myservo0.write(high_center+30);
 //       delay(500);
  }

void setup() { 
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D1, HIGH); 
  myservo0.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}


int check_button(void) {
buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
  digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
  return 1;
  } else {
    // turn LED off:
  digitalWrite(D0, LOW);   // turn the LED on (HIGH is the voltage level)
  return 0;
  }
}

int analag_read_h() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  high_center = map(sensorValue, 0, 1023, 30, 150);
  return high_center;
}

int analag_read_x() {
  // read the input on analog pin 1:
  int sensorValue = analogRead(A1);
  int lenght_x = map(sensorValue, 0, 1023, 0, 70);
  return lenght_x;
}

void loop() {
if (check_button()) {
    traject();
  } else {
    box_drow1();
  }
}
