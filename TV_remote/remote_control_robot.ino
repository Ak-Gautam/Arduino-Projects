#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
int sled = 13;
int LED1 = 39;
int LED2 = 40;
int HOR = 22;
#include <AFMotor.h>
AF_DCMotor motor(4, MOTOR12_64KHZ);
AF_DCMotor motor1(1, MOTOR12_64KHZ);
int RECV_PIN = 26;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
   irrecv.enableIRIn(); // Start the receiver
   motor.setSpeed(250); 
  motor1.setSpeed(250);
  pinMode(sled,OUTPUT);
  digitalWrite(sled,LOW);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(HOR,OUTPUT);
 
}

void loop() {
    if (irrecv.decode(&results)){
      digitalWrite(sled,HIGH);
      irrecv.resume();
  if(results.value == 0x40BFD827){ // These codes vary per remote and must be checked beforehand.
  motor.run(FORWARD);      // Robot going
  motor1.run(BACKWARD);     // forward
  }
   
  else if(results.value == 0x40BFF807){
  motor1.run(FORWARD);      // Robot going
  motor.run(BACKWARD);     // backward 
  }
  else if(results.value == 0x40BF58A7){
  motor1.run(FORWARD);      // Robot going
  motor.run(FORWARD);     // right 
  }
  else if(results.value == 0x40BF7887){
  motor1.run(BACKWARD);      // Robot going
  motor.run(BACKWARD);     // LEFT 
  }
  else if(results.value == 0x40BF30CF){
    motor1.run(RELEASE);      // Robot Stops
  motor.run(RELEASE);     // at the place
  }
 { if(results.value == 0x40BF807F){
    digitalWrite(LED1,HIGH);}
   if(results.value == 0x40BF40BF)
   digitalWrite(LED2,HIGH);
   if(results.value == 0x40BFC03F)
   digitalWrite(HOR,HIGH);

  delay(720);  
  if(results.value == 0x40BF807F){
    digitalWrite(LED1,LOW);}
   if(results.value == 0x40BF40BF)
   digitalWrite(LED2,LOW);
   if(results.value == 0x40BFC03F)
   digitalWrite(HOR,LOW);

}
delay(40);        // delay in between reads for stability
    }
}
