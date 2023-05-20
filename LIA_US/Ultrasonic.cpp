#include "Ultrasonic.h"

Servo myservo;  // create servo object to control a servo

motor MyCar(100); //Create an object for the motors and define the velocity

Ultrasonic::Ultrasonic (int x){ 
}

void Ultrasonic::initUS(){ //Init method
  MyCar.init(); //initilize motors
  pinMode(trigPin, OUTPUT); //define trigger pin as an output
  pinMode(echoPin, INPUT); //define echo pin as an input
  myservo.attach(11);  // attaches the servo on pin 11 to the servo object
  myservo.write(90); //Rotate the servo the center 
}

void Ultrasonic::ultrasonicMode (){
   digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); //sends a pulse with the trigger pin 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); //times the duration of the pulse 
  distance = (duration/2)*0.0343;  //calculates the distance with the duration read

   Serial.print("Distance: "); //Serial print to debug
  
if (distance > 15) {  //If the distance is greater than 15cm
    MyCar.forward(); //move forward because there's no obstacle 
  } else {
    Serial.println("Stop"); //print to debug
    MyCar.stop(); //stop if the distance is less than 15cm
    Serial.println("Left"); //print to debug
    
    unsigned long previousMillis = currentMillis;
     while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      myservo.write(180); //move sensor to the left  
    }
    
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //sends a pulse with the trigger pin 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); //read distance again
    distance = (duration/2)*0.0343;
    
    if (distance > 15) { //if there is no obstacle to the left
     
        unsigned long previousMillis = currentMillis;
        while ((currentMillis - previousMillis) < 250) { //wait for turn to complete
        currentMillis = millis();
         MyCar.left(); //turn to the left
      }
      previousMillis = currentMillis;
      while ((currentMillis - previousMillis) < 500) { //wait for servo to move
        currentMillis = millis();
        myservo.write(90); //return servo to original position
      }
      
    } else {
      MyCar.stop(); //stop if the distance is less than 15cm
      Serial.println("Right "); //print to debug
       unsigned long previousMillis = currentMillis;
      while ((currentMillis - previousMillis) < 500) { //wait for servo to move
      currentMillis = millis();
      myservo.write(0); //move sensor to the left  
    }
      
      digitalWrite(trigPin, LOW); 
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH); //sends a pulse with the trigger pin 
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH); //read distance again
      distance = (duration/2)*0.0343;
      
      if (distance > 15) { //if there is no obstacle to the right
      unsigned long previousMillis = currentMillis;
        while ((currentMillis - previousMillis) < 250) { //wait for turn to complete
        currentMillis = millis();
         MyCar.right(); //turn to the right
      }
      previousMillis = currentMillis;
      while ((currentMillis - previousMillis) < 500) { //wait for servo to move
        currentMillis = millis();
        myservo.write(90); //return servo to original position
      }
    } else {
      unsigned long previousMillis = currentMillis;
        while ((currentMillis - previousMillis) < 750) { //wait for turn to complete
        currentMillis = millis();
         MyCar.right(); //turn to the left
      }
      myservo.write(90); //Return servo to its original position
     }
    }
  }
}
