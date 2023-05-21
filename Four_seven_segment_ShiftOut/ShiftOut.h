#ifndef ShiftOut_H
#define ShiftOut_H
#include <Arduino.h>

class ShiftOut {

private: 

int latch = 3; //pin to latch
int cs = 4; //clockpin
int data = 2; //pin to pass the information
int dPins[4] = {13, 12, 11, 10};  //pins that control the digits
 //pin 10= digit 1
 //pin 11= digit 2
 //pin 12= digit 3
 //pin 13= digit 4

 int step=0; //This varibale is used to change the switch case
//it starts at 0 to show the first digit, and increses to 3 for digit 4
unsigned long prevMillis=0; //variable used to record the previous millis

int time=5;//time required to change between each digit

const byte digits[10] = {  //It indicates which pins have to be on and off to display each number
//each byte has the information to print on the segments on or off in accordance with the digit
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B0000111,  // 7
  B01111111,  // 8
  B01101111,   // 9
};

int _x;
int _y;
int _w;
int _z;

public:

ShiftOut(){};
ShiftOut(int x,int y, int w, int z);

void init();
bool wait(unsigned long mill);
void print_num();

};

#endif