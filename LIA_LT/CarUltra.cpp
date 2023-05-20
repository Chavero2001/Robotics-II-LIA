#include "CarUltra.h"

motor MyCar (50); //Create an object for the motors

CarUltra::CarUltra(int x){
x=spead;
};

void CarUltra::initCar(){
  MyCar.init(); //initilialize motors

};

void CarUltra::Ultrasonic(){
  dataR= analogRead(A0); //Read the data of the Right sensor
  dataM= analogRead(A1); //Read the data of the Midle sensor
  dataL= analogRead(A2); //Read the data of the Left sensor
    
Serial.print("DataR: ");   //Serial print the value of DataR to know the values of the sensor before coding, it also can help to debug
Serial.print(dataR);
Serial.print("    DataM: "); //Serial print the value of DataM to know the values of the sensor before coding, it also can help to debug
Serial.print(dataM);
Serial.print("    DataL: "); //Serial print the value of DataL to know the values of the sensor before coding, it also can help to debug
Serial.println(dataL);


if(dataR<360 && dataM>300 && dataL<300) { //If the values are in this thereshold 
Serial.println("Forward"); //print to debug
MyCar.forward(); //move forward while the data have those values
} 

if(dataR>200 && dataM<300 && dataL<40){ //If the car start moving to the left the sensor on the right will increase its value
  Serial.println("Right"); //print to debug
  MyCar.right(); //move to the right until the values allow to continue forward
  
}

if(dataR<40 && dataM<300 && dataL>500){ //If the car start moving to the right the sensor on the right will increase its value
  Serial.println("Left"); //print to debug
  MyCar.left(); //move to the left until the values allow to continue forward

}
if(dataR<50 && dataM<50 && dataL<50){ //if the car reach the end of the line
  Serial.println("Turn");    //print to debug
if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
      MyCar.left();      //turn back
  prevMillis = millis();

if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
  MyCar.stop();           //stop before continuing 
  prevMillis = millis();
  }
  } 
}

  
};