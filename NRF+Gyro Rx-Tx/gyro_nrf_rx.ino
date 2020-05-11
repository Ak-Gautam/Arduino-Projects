/* This is the progrsm for the rx
 *  we are using 3 servos as the output  
*/

#include <SPI.h>      //SPI library for communicate with the nRF24L01
#include "RF24.h"     //The main library of the nRF24L01
#include "Servo.h"
  
Servo servo0;
Servo servo1;
Servo servo2;

//Define packet for the direction 
int data[3]; //Remember we sent 3 channels so we need to recieve 3 channels as well

//Define object from RF24 library 
RF24 radio(8,7); // pins CE, CSN  on the arduino

const uint64_t pipe = 0xE8E8F0F0E1LL; // The addresss which is same as tx
int val0;
int val1;
int val2;
int pVal0; // These 3 extra variables are for storing last loop values so thst servo doesn't jitter
int pVal1;
int pVal2;
 
void setup()
{

    servo0.attach(2); // pin 2 for servo0
    servo1.attach(3); // pin 3 for servo1
    servo2.attach(4);

  radio.begin();                    //Start the nRF24 communicate            
  radio.openReadingPipe(1, pipe);   //Sets the address of the transmitter to which the program will receive data.
  radio.startListening();    
}
 
void loop()
{
    if (radio.available()){
    radio.read(data, sizeof(data));
    val0 = data[0];
    val1 = data[1];
    val2 = data[2];
    
    // Servo0
    if (val0 != pVal0)
    {
        servo0.write(val0);
        pVal0 = val0;
    }
    
    // Servo1
    if (val1 != pVal1)
    {
        servo1.write(val1);
        pVal1 = val1;
    }

     // Servo2
    if (val2 != pVal2)
    {
        servo2.write(val2);
        pVal2 = val2;
    }
  }

}
