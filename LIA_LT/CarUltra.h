#ifndef carultra_h  
#define carultra_h  //Define if not defined 

#include <Arduino.h> //Include arduino library
#include <motor.h> //Include motor library


class CarUltra { //Create a class for the line tracker segment
private: 
  int mill = 500; //interval for delay 
  unsigned long prevMillis; //Store de value of the previous milliseconds
  int spead; //variable for the speed of the car
  int dataR; //variable in which will be store the value of the R sensor
  int dataM; //variable in which will be store the value of the M sensor
  int dataL; //variable in which will be store the value of the L sensor


public:
CarUltra(){}; //default constructor
CarUltra(int x); //constructor
void initCar(); //Method to initialize motors and 
void Ultrasonic(); //Method to read the values and move the car


};

#endif