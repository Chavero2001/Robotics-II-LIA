//LIA Line Tracker 

#include "CarUltra.h" //Include library for the line tracker

CarUltra Test(70); //Create the 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //intialize serial monitor
  Test.initCar(); //Intialize motor and sensors
}

void loop() {
  
  Test.Ultrasonic();//Keep running the code
//Despite saying ultrasonic, it is for the line tracker
}
