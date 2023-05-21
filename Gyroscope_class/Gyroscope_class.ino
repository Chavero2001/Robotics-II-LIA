#include "gyro.h"

AcGyro Test(9600);

void setup() {
  // put your setup code here, to run once:
  Test.initMPU();
}

void loop() {
  // put your main code here, to run repeatedly:
 float aX=Test.readAccelerationX();
 float aY=Test.readAccelerationY();
 float aZ=Test.readAccelerationZ();
   Serial.print("Acceleration X: ");
     Serial.print(aX);
     Serial.print(" Acceleration Y: ");
     Serial.print(aY);
     Serial.print(" Acceleration Z: ");
     Serial.print(aZ);

 float gX=Test.readGyroX();
 float gY=Test.readGyroY();
 float gZ=Test.readGyroZ();
   Serial.print(" Rotation X: ");
     Serial.print(gX);
     Serial.print(" Rotation Y: ");
     Serial.print(gY);
     Serial.print(" Rotation Z: ");
     Serial.print(gZ);

 float tem=Test.readTemp();
 Serial.print(" Temp: ");
     Serial.println(tem); 
     
}
