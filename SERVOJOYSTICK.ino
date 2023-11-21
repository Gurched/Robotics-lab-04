// Include the library for the Servo:
#include <Servo.h>

// Gives the code an object to call by
Servo myservo;

// give intergers to variables:
int jpin = A0;
int jstick;
int val;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);    // Set servo pin to 9 
}

void loop() {
  // put your main code here, to run repeatedly:
jstick = analogRead(jpin);           // Reads the value of the joystick
val = map(jstick, 0, 1023, 0 ,180);  // Calculate the values of 0-1023 to turn into 0-180
myservo.write(val);                  //  Send the values to the Servo

delay(25);        // Stop the program for 25 ms
}
