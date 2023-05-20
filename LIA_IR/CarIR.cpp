#include "CarIR.h" //include heade file
 
IRrecv irrecv(9); //create an object for the IR sensor and assign a pin 
decode_results results; 
motor MyCar (250); //create an object for the car and assign a value for speed

CarIRrev::CarIRrev(int x){
//Constructor different from default
};

void CarIRrev::initMyIR(){ //Funtion to initialize both IR sensor and Car
  
  irrecv.enableIRIn(); //Enable Infrared sensor
  MyCar.init(); //Initialize motor
   
};

void CarIRrev::readIR () { //Function to read IR value and react to that 
  
    if (irrecv.decode(&results)) { 
        Serial.println(results.value, HEX); //print in HEX to debug
          
  switch (results.value) { //switch case for different codes
    
case  0xFFFFFFFF:
   results.value = lastCode; //repeat the previous code
   if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break; //break when finish
  prevMillis = millis();}
 
   
case  0xFF629D: //Code to move car forward
    lastCode = results.value;        //save the value in lastCode to repead 
    MyCar.forward(); //move car forward
    Serial.println("F");
  
  if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break; //break after the delay 
  prevMillis = millis();}
  
case 0xFFA857:
lastCode = results.value;       
            MyCar.backward();  //move backwards
            Serial.println("B");
if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break;//break after the delay 
  prevMillis = millis();}

case 0xFFC23D:
  lastCode = results.value;       
            MyCar.right(); //turn right
            Serial.println("r");

  if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break; //break after the delay 
  prevMillis = millis();}

case 0xFF22DD:
lastCode = results.value;        
            MyCar.left(); //turn left
 if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break; //break after the delay 
  prevMillis = millis();}



default: //stop if any other code is received
  MyCar.stop(); //stop car
  Serial.println("Stop");
  if(millis()-prevMillis>=mill){ //it uses millis() to avoid using delay
    break; //break after the delay 
  prevMillis = millis();}
  }
    irrecv.resume(); //continue reading
    
  };
  
  }
  