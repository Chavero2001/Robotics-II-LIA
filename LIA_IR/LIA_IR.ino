#include "CarIR.h" //Include header file

CarIRrev Test1(250); //create an object and pass the car speed

void setup() {

  Serial.begin(9600); //Serial begin to debug if necessary 
  Test1.initMyIR(); //initialize Car
}

void loop() {
  
 Test1.readIR(); //Keep runing the code to read the IR sensor
}
