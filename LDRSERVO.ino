// include the library for the servo
#include <Servo.h>

// Set and object for the code
Servo myservo;

// Create intergers for variable:
int LDRpin = A0;
int LDR;
int val;

void setup() {
  // put your setup code here, to run once:
  // attch pin 9 to the servo object:
  myservo.attach(9);
  //intialize the serial monitor:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Calculate all neede values:
LDR = analogRead(LDRpin);              // Read the pin of the LDR
val = map(LDR, 0, 1023, 0 ,180);       // Transforms the values from 0-1023 to 0-180
myservo.write(val);                    // write the values to the motor
float volt = (5.00 / 180.00) *val;     // Figure out the voltage of the pin using y = mx + b
float current = 5.00 / 10000.00;       // With the volatge, calculate the current
int LDR = (5.00 - volt) / current;     // With the current and volatage, calculate the resistance

Serial.println("==============================================");  // Separate the first part from the second
Serial.print("Bit Value: ");                                       // print " Bit Value: "
Serial.println(LDRjoy);                                            // print the bit value
Serial.print("Voltage: ");                                         // Print "Voltage: "
Serial.println(volt);                                              // print the calculated voltage
Serial.print("LDR Resistance: ");                                  // print "LDR Resistance: "
Serial.print(LDR);                                                 // print the value of the LDR
Serial.println("Ω");                                               // print the ohm character
delay(500);                                                        // stop the program for hald a second
}
