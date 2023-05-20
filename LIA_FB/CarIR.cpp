#include "CarIR.h" // include header file

IRrecv irrecv(9); //create an object for the IR sensor and assign it a pin
decode_results results;
motor MyCar (150);   //Create an object for motors normal speed
motor MyCarMAX (250); //Second object for motors, but for maximum speeed
 
Servo myservo;  //Create an object for the servo

CarIRrev::CarIRrev(int x){
  x=spead;
};

void CarIRrev::initMyIR(){
  
  irrecv.enableIRIn(); //Enable Infrared sensor
  MyCar.init(); //initiliaze motors
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo.write(90); //move the servo to the central position 
};

void CarIRrev::readIR () {
  
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); //print in HEX 
          
  switch (results.value) { //Switch case for different codes
        
case 0xFF02FD: //Stop the car
  MyCar.stop();
  Serial.println("S");
  
    break;
    
case  0xFFFFFFFF: //repeat last code if any button is pressed multiple times
   results.value = lastCode; 
    break;
 
   
case  0xFF629D: //Move car forward 
    lastCode = results.value;       
    MyCar.forward(); 
    Serial.println("F");
  
    break;
  
case 0xFFA857: //move car backwards
lastCode = results.value;       
            MyCar.backward(); 
            Serial.println("B");
    break;

case 0xFFC23D: //turn right 
  lastCode = results.value;       
            MyCar.right(); 
            Serial.println("r");

    break;

case 0xFF22DD: //turn left
lastCode = results.value; 
Serial.print("l");        
            MyCar.left(); 
    break;

case 0xFF6897: //Move the servo to hit the ball with the support
Serial.print("Shoot"); 
    previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      myservo.write(180); //move servo to left
    }
    previousMillis = currentMillis;
    while ((currentMillis - previousMillis) < 500) { //wait for servo to move
        currentMillis = millis();
        myservo.write(90); //return servo to original position
      }
    previousMillis = currentMillis;
    while ((currentMillis - previousMillis) < 500) { //wait for servo to move
        currentMillis = millis();
        myservo.write(180); //return servo to original position
      }
      break;
      
case 0xFF9867: //Move the servo to hold the ball while moving
Serial.print("Hold"); 
    previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      myservo.write(90); //move servo to the center
    }
      break;
      
case 0xFFB04F: //move the car at max speed for 2 seconds
Serial.print("Dash"); 
    previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 2000) { //wait for servo to move
      currentMillis = millis();
      MyCarMAX.forward(); //move sensor to the left 
      
    }
      MyCarMAX.stop()   ;
      break;
      

case 0xFF30CF: //Quickly turn to the left
Serial.print("Q Left"); 
    previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      MyCarMAX.left(); //move sensor to the left 
    }
      MyCarMAX.stop();
      break;

case 0xFF18E7: //Quickly turn to the right
Serial.print("Q Right"); 
    previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      MyCarMAX.right(); //move sensor to the left 
    }
      MyCarMAX.stop();
      break;
      
      
default:
  //If there are multiple IR sensors in use, the interferance from the other sensors will keep the car stopped. 
    //MyCar.stop(); 
    //Serial.println("Stop");
  break;
  
  }
    irrecv.resume();  //Resume reading

  }
}
  