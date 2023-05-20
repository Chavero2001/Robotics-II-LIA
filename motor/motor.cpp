#include "motor.h" //include the header file


motor::motor(int Spead){
 sd=Spead; //pass the speed value 
}


void motor::init(){ //function to initialize
  pinMode(pinS1,OUTPUT); //define pins as outputs
  pinMode(pinD1,OUTPUT);
  pinMode(pinS2,OUTPUT);
  pinMode(pinD2,OUTPUT);
  pinMode(pinAct,OUTPUT);
  digitalWrite(pinAct,1); //enable motors 
}

void motor::move(int d1, int s1, int d2, int s2){ //general function for movement
  digitalWrite(pinD1,d1);
  analogWrite(pinS1,s1);
  digitalWrite(pinD2,d2);
  analogWrite(pinS2,s2);  
}

void motor::forward (){ //function for moving forward with x speed
  move(1,sd,1,sd); //use the move function and pass the values to the function 
}

void motor::backward (){ //function for moving backwards with x speed
  move(0,sd,0,sd); //use the move function and pass the values to the function 
}

void motor::stop (){ //function for stopping
  move(1,0,1,0); //any movement with 0 speed will stop the car
}

void motor::left (){ //function for moving left with x speed
  move(1,sd,0,sd); //use the move function and pass the values to the function 
}

void motor::right (){ //function for moving rigth with x speed
  move(0,sd,1,sd); //use the move function and pass the values to the function 
}

void motor::leftforward (){ //function for moving leftforward with x speed
  move(1,sd,1,sd/2); //use the move function and pass the values to the function 
}

void motor::rightforward (){ //function for moving rightforward with x speed
  move(1,sd/2,1,sd); //use the move function and pass the values to the function 
}

