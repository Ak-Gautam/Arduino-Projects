#include <AFMotor.h>

bool senL;
bool senR;
bool senS;

AF_DCMotor motor1(1);
AF_DCMotor motor2(4);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //Serial.begin(9600);
  //Serial.println("Starting....");
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);

}

void loop() {
  senL = digitalRead(26);
  senR = digitalRead(27);
  senS = digitalRead(28);
  //Stop sign when all sensors on black line
  if((senL==1) && (senS==1) && (senR==1))
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    Serial.println("STOP");
    delay(5000);
  }
  //Forward
  else if((senL==0) && (senS==1) && (senR==0))
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    Serial.println("Forward");
  }
  //Go Left
  else if((senL==1) && (senS==1) && (senR==0))
  {
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    Serial.println("Left");
  }
  //Go Right
  else if((senL==0) && (senS==1) && (senR==1))
  {
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    Serial.println("Right");
  }
  //Edge case: no line
  else if((senL==0) && (senS==0) && (senR==0))
  {
    Serial.println("No line");
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    delay(500);
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    delay(500);
  }
  //Edge case: two other situations
  else{
    Serial.println("Other edge cases");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200); 
    }
}
