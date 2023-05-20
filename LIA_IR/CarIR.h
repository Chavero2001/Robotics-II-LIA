#ifndef carir_h //define if not defined yet
#define carir_h

#include <Arduino.h> //Include arduino library
#include <IRremote.h> //include library for the sensor 
#include <motor.h> //include library to move the car


class CarIRrev { //create a class
 private:
    
    unsigned long lastCode; //variable to assign the lastCode 
    
    int mill = 100; //varible to desing the delay
    unsigned long prevMillis; //variable to store millis
    
    
 public:

CarIRrev(){}; //default constructor
CarIRrev(int x); //constructor
void initMyIR(); //function to initialize car
void readIR(); //function to read the values and act on those values

};

#endif