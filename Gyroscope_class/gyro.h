#ifndef gyroscope_H //Define if not defined

#define gyroscope_H

#include <Arduino.h> //Include arduino library 

#include <Adafruit_MPU6050.h> //Include library for MPU
#include <Adafruit_Sensor.h> //Include adafruit library
#include <Wire.h> //Include wire library for serial communication

class AcGyro { //create a class
  private:
    Adafruit_MPU6050 mpu; //Create an object 
  int _baud;  //Variable that stores the baud value


  public:
    AcGyro(){}; //Default constructor
    AcGyro(int baud); //Constructor that receives the value of the baud
    
    void initMPU();   //method to init Sensor
    float readAccelerationX();  //Method for acceleration in X
    float readAccelerationY(); //Method for acceleration in Y
    float readAccelerationZ(); //Method for acceleration in Z
    float readGyroX(); //Method for rotation in X
    float readGyroY(); //Method for rotation in Y
    float readGyroZ(); //Method for rotation in Z
    float readTemp(); //Method for temperature

};

#endif
