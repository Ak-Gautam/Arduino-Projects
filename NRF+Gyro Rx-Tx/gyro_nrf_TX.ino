/* This is the programm for the tx
 *  A simple project to demonstrate the use of MPU6050 with BRF24L01 to create a motion control tx for 3 channels.
 * It can be used as an begginer project. 
*/
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <SPI.h>
#include <RF24.h>
 
MPU6050 mpu;
 

RF24 radio(14, 15); // CE, CSN
const uint64_t pipe = 0xE8E8F0F0E1LL;      //The address which will be used by the NRF module
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Define the data packet for the direction (X,Z axis and Y axis)
int data[3];  //Using 3 as we will use only three channels for x, y, z data

 

 
void setup(void)
{
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();              //Initialize the MPU object
  radio.begin();                 //Start the nRF24 communicate     
  radio.openWritingPipe(pipe);   //Sets the address of the receiver to which the program will send data.

}
 
void loop()
{
   //With this function, the acceleration and gyro values of the axes are taken. 
   // These values can be interchanged to change the axis
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);    // All the 'a' value like 'az' are the accelerometer values and 'g' are gyro values

// we are sending only the accelerometer values to the rx 
  data[0] = map(ax, -17000, 17000, 0, 180 ); //Send X axis data
  data[1] = map(ay, -17000, 17000, 0, 180);  //Send Y axis data
  data[2] = map(az, -11300, 21200, 0, 180);  //Send Y axis data
  radio.write(data, sizeof(data));
}
