#ifndef motor_H

#define motor_H
//define if is not defined yer
#include <Arduino.h> //include Arduino library
 
class motor{ //create a class to control the motors 

private:

//hide and protect the pins assigned to the motors 
int pinS1=5; //pin to control speed of motor A
int pinD1=7; //pin to control direction of motor A
int pinS2=6; //pin to control speed of motor B
int pinD2=8; //pin to control direction of motor B
int pinAct=3; //pin to enable the motors
int sd; //variable for speed

public:

motor(){}; //default constructor
motor(int Spead); //constructor in which the speed is passed


void init(); //initialize the motor

void move(int d1, int s1, int d2, int s2); //general function for motors

void forward (); //use the move function to to move forward

void backward (); //move backward

void stop (); //stop the car

void left (); //move left

void right (); //move right

void leftforward (); //move leftforward

void rightforward (); //move rightforward

};

#endif