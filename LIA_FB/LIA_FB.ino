#include "CarIR.h" //Include IR library

CarIRrev Test1(250); //Create an object for the car

void setup() {
 
  Serial.begin(9600); //Serial 
  Test1.initMyIR(); //Initilize motor, sensor and servos
}

void loop() {
 Test1.readIR(); //Read the values and move the car in accordance to the values
}
