// defines pins numbers
const int trigPin = 25;
const int echoPin = 29;
// defines variables
long duration;
int distance;
#include <AFMotor.h>
AF_DCMotor motor(4, MOTOR12_64KHZ);
AF_DCMotor motor1(1, MOTOR12_64KHZ);

void setup()
{
motor.setSpeed(250); 
motor1.setSpeed(250);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  if(distance<=9)
  {
  motor1.run(BACKWARD);      // Robot going
  motor.run(RELEASE);     // right
  delay(800);
  }
  else
  {
   motor.run(BACKWARD);      // Robot going
  motor1.run(FORWARD);     // forward 
  }
  delay(50);
}

