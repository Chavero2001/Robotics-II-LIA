#include "ShiftOut.h"

ShiftOut::ShiftOut(int w, int x, int y, int z){
_x=x;
_y=y;
_w=w;
_z=z;

};

bool ShiftOut::wait(unsigned long mill){ //funtion to wait and change the steps in the switch case
  if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
  step++; //One is added to step variable each time it reaches 5 milliseconds...
          //this changes the switch case to the next step 
  prevMillis = millis(); //prevMillis is updated to the current millis
    }
  
};

void ShiftOut::init(){
  pinMode(latch, OUTPUT);
 	pinMode(cs, OUTPUT);
 	pinMode(data, OUTPUT);
 	pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);   
};

void ShiftOut::print_num( ){ //function to print 4 digits
  switch (step){ //this switch case has the function to display first on digit 1, then on 2 and 3, until reaching the fourth digit
case 0:
//First digit
	digitalWrite(13, HIGH); //high means that is not active
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW); //the output has to be low to display the digit
  digitalWrite(latch, LOW);
 	shiftOut(data, cs, MSBFIRST, digits[_z]); //shiftOut the data contained in the digits array for the value on the first digit
 	digitalWrite(latch, HIGH); //active the lacth to display 

  //delay(5);
wait(time); //use the function wait to wait 5 milisecond, and then changing to the next step 
break; //break the case

case 1:
//Secon digit
	digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW); //now this has to be low and the rest high to display only on the second digit
  digitalWrite(10, HIGH);
  digitalWrite(latch, LOW);
 	shiftOut(data, cs, MSBFIRST, digits[_y]); //the value now will be the one passed on y 
 	digitalWrite(latch, HIGH);   
  
 // delay(5);

wait(time); //wait and change the step 
break;

case 2:
//Third digit
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(latch, LOW);
 	shiftOut(data, cs, MSBFIRST, digits[_x]);
 	digitalWrite(latch, HIGH);
  
  //delay(5);
wait(time);//wait and change the step 
break;

case 3:
//Four digit
digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(latch, LOW);
 	shiftOut(data, cs, MSBFIRST, digits[_w]);
 	digitalWrite(latch, HIGH);
   
  //delay(5);
wait(time); //wait and change the step 
break;

default:
step=0; //step is reseted to 0, starting again
break;

};
} ;