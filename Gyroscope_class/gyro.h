#ifndef gyroscope_H
#define gyroscope_H

#include <Arduino.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

class AcGyro {
  private:
    Adafruit_MPU6050 mpu;
  int _baud;


  public:
    AcGyro(){};
    AcGyro(int baud);
    
    void initMPU();  
    float readAccelerationX();
    float readAccelerationY();
    float readAccelerationZ();
    float readGyroX();
    float readGyroY();
    float readGyroZ();
    float readTemp();

};

#endif
