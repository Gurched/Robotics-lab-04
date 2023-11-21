// Include Stepper motor library
#include <Stepper.h>

// give intergers to variables:
int stepsPerRevolution = 2048;
int motSpeed = 20;
int jpin = A0;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int opt;

// Enables pins to work:
Stepper mystepper(stepsPerRevolution, 8, 10, 9, 11); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);             // turn on the Serial Monitor
  mystepper.setSpeed(motSpeed);   // Sets a speed to the motor
  pinMode(jpin, INPUT);           // Setting jpin as an input 
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(jpin);       // Reads the bit value of the pin 
  opt = map(val, 0, 1023, 0, 2);    // Converts the value from 0-1023 to 0-2 without decimals
  Serial.println(opt);              // Print out the values of the options to see if it functions

  // If the option is 1 (middle on the joystick), the motor will not roatet
  if (opt == 1) {
    mystepper.step(0);    // Not rotating 
  } else
  // if the option is 0 (down on the joystick), the motor wil rotate clockwise.
  if (opt == 0) {
    mystepper.step(1);
  } else
  // if the option is 2 (up on the joystick), the motor wil rotate counterclockwise.
  if (opt == 2) {
    mystepper.step(-1);
  }
}
