#include "gyro.h" //Include header file

AcGyro::AcGyro (int baud){ //Assign the baud value for the serial communication
 _baud=baud;
};

void AcGyro::initMPU(){ //Method to init sensor
 
Serial.begin(_baud); //Initialize serial communication
  while (!Serial)

  Serial.println("Adafruit MPU6050 test!"); //Print at the start 

  // Try to initialize
  if (!mpu.begin(0x69)) { //If there is no communication the serial monitor will indicate it
    Serial.println("Failed to find MPU6050 chip"); 
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!"); //The serial monitor will notify if the sensor was found

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); 
  Serial.print("Accelerometer range set to: "); //Print the range of the sensor for acceleration
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); //Print the range of the sensor for rotation
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: "); //Print the filter of the sensor
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
  Serial.println("");
  
};

float AcGyro::readAccelerationX(){ //method to get acceleration in x
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float AccelerationX=a.acceleration.x;   //Save the value for acceleration
  unsigned long previousMillis = 0;  // Millis function to avoid using a delay 
  const long interval = 500;   //Delay of 500 milliseconds
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return AccelerationX; //return acceleration on X 
  }
};

float AcGyro::readAccelerationY(){ //method to get acceleration in y
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float AccelerationX=a.acceleration.y;   //Save the value for acceleration
  unsigned long previousMillis = 0;  
  const long interval = 500;  //Delay of 500 milliseconds
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return AccelerationX; //return acceleration on y 
    //Despite the name of the variable says Acceleration X, it doesn't affect, as the value is savinf and retunning is acceleration in Y
  }
};

float AcGyro::readAccelerationZ(){ //method to get acceleration in z
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float AccelerationX=a.acceleration.z; //Save the value for acceleration
  unsigned long previousMillis = 0;  
  const long interval = 500;  //Delay of 500 milliseconds
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return AccelerationX; //return acceleration on z
  }
};

float AcGyro::readGyroX(){ //method to get rotation in x
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float value=g.gyro.x; 
  unsigned long previousMillis = 0;
  const long interval = 500;   //delay
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return value;
  }
};

float AcGyro::readGyroY(){ //method to get rotation in y
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float value=g.gyro.y; 
  unsigned long previousMillis = 0; 
  const long interval = 500;  //delay
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return value;
  }
};

float AcGyro::readGyroZ(){ //method to get rotation in z
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float value=g.gyro.z; 
  unsigned long previousMillis = 0;  
  const long interval = 500;   //delay
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return value;
  }
};

float AcGyro::readTemp(){ //method to get temperature
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); //Get the event for all the variables of the sensor
  float value=temp.temperature;  //only save temperature 
  unsigned long previousMillis = 0;  
  const long interval = 500;   //delay 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return value;
  }
};
