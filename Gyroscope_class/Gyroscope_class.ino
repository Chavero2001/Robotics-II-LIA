#include "gyro.h" //Add library

AcGyro Test(9600); //Create the object and define the velocity

void setup() {

  Test.initMPU(); //Initialize MPU
}

void loop() {
  
 float aX=Test.readAccelerationX(); //Get acceleration of X
 float aY=Test.readAccelerationY(); //Get acceleration of y
 float aZ=Test.readAccelerationZ(); //Get acceleration of z
   Serial.print("Acceleration X: ");    //Print acceleration of X
     Serial.print(aX);
     Serial.print(" Acceleration Y: "); //Print acceleration of y
     Serial.print(aY);
     Serial.print(" Acceleration Z: "); //Print acceleration of z
     Serial.print(aZ);

 float gX=Test.readGyroX(); //Get values from the gyroscope on the X axis
 float gY=Test.readGyroY(); //Get values from the gyroscope on the Y axis
 float gZ=Test.readGyroZ(); //Get values from the gyroscope on the Z axis
   Serial.print(" Rotation X: "); //Print values
     Serial.print(gX);
     Serial.print(" Rotation Y: ");
     Serial.print(gY);
     Serial.print(" Rotation Z: ");
     Serial.print(gZ);

 float tem=Test.readTemp(); //Get values for temperature 
 Serial.print(" Temp: "); //Printe Temperature values
     Serial.println(tem); 
     
}
