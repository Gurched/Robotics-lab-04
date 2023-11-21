// Include 2 libraries, Stepper and IR remote:
#include <Stepper.h>
#include <IRremote.h>

// Define the receiver pin to pin 2
#define IR_RECEIVE_PIN 2

//  Give intergers to variables:
int stepsPerRevolution = 2048;
int motSpeed = 20;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

// Enable pins to work with the motor:
Stepper mystepper(stepsPerRevolution, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                         // start the Serial monitor
  mystepper.setSpeed(motSpeed);                               // Setting a speed to the motor
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);      // Start the pin for IR receiving
}

void loop() {
  // put your main code here, to run repeatedly:

const int command = IrReceiver.decodedIRData.command;         // give an interger for command to decode the buttons when pressed

// If the IR receiver receives data, it will decode this data
if (IrReceiver.decode()) {

    Serial.println(command);    // this will print the value of the data
    delay(100);                 // adding a pause to the program to read the data
    IrReceiver.resume();        // Resume the ir reciever to recieve
  }
  // If the IR remote is pressed on play/pause, it will stop the program
if (command == 21) {
  // This will stop the program
  mystepper.step(0);
}
  // If the IR remote is pressed on down, it will turn clockwise
if (command == 9) {
  // This will spin clockwise
  mystepper.step(1);
}
  // If the IR remote is pressed on up, it will turn counter clockwise
if (command == 7) {
  // This will spin counter clockwise
  mystepper.step(-1);

}
}
