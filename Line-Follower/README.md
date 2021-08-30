---
Name: Line Follower
Desc: A simple line follower with one extra sensor.
Author: '@Gautam-flash'
---

It's a simple build. The purpose was to test the body of the robot for an upcoming bigger project. <br>
[Here](Basic_bot.ino) is the Arduino code

## BOM

|Comp   | Name               |No.|
|-------|--------------------|---|
|MCU    | Arduino mega 2560  | 1 |
|Battery| 7.4 V, 2s Li-ion   | 1 |
|Motor  | 400RPM Gear motor  | 2 |
|Driver | AF Motor shield V1 | 1 |
|Sensors| IR Proximity sensor| 3 |

*The Adafruit Motor shield V1 is embedded on the board with Arduino Mega 2560

## Schematics
|Part| Arduino Pin|
|----|------------|
|Motor1| AF_Motor shield port2|
|Motor2| AF_Motor shield port4|
|IR Sen Left| pin 26|
|IR Sen Center| pin 28|
|IR Sen Right| pin 27|

*Onboard LED on pin13 is used to signal for edge cases <br>
*This single battery powers both the Arduino and the motors using the AF_Motor shield

## Some images

![image2](bot1.jpeg)

<hr>

![image3](bot4.jpeg)

<hr>

![image4](bot5.jpeg)
