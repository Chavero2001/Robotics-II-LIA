#ifndef Ultrasonic_H //Define if not defined
#define Ultrasonic_H

#include <motor.h> //include library for the motor
#include <Servo.h> //Includes library to control servo motor
#include <Arduino.h> //include arduino library

#define trigPin  13 //Pin that is connected to the Trigger pin
#define echoPin  12 //Pin that is connected to the Echo pin

class Ultrasonic { //Create a class for the ulstrasonic sensor

private:
  float duration; // Stores pulse duration value
  float distance; // Stores calculated distance in cm
  
  unsigned long previousMillis = 0; //Stores previous millis
  const long interval = 1350; //delay time
  unsigned long currentMillis; //varible for the current millis


public:

  Ultrasonic(){}; //default constructor
  Ultrasonic(int x); //constructor different from the default 
 

  void initUS(); //method to initilize 
  void ultrasonicMode(); //Read values and move the car

};

#endif