#ifndef carir_h //Define if not defined

#define carir_h 

#include <Arduino.h> //Include arduino library
#include <IRremote.h> //Include IR library
#include <motor.h> //Include motor library
#include <Servo.h> //Includes library to control servo motor


class CarIRrev { //Create a class 
 private:
    
    int spead;  
    unsigned long lastCode; //variable to assign the lastCode 

    unsigned long previousMillis = 0; //store previous millis 
    unsigned long currentMillis; //store current milliseconds
    
    
 public:

CarIRrev(){}; //default constructor
CarIRrev(int x); //constructor
void initMyIR(); //Method to start motors and sensor
void readIR(); //Move the car in accordance with the sensor values

};

#endif