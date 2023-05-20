//LIA Ultrasonic
#include "Ultrasonic.h" //include library for Ultrasonic sensor

Ultrasonic Test (10); //create an object and assign a pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //intialize serial monitor
  Test.initUS(); //Initialize ultrasonic sensor
}


void loop() {

  Test.ultrasonicMode(); //Keep looping the function to move 
}
