// setting intergers for variables:
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int speed;

void setup() {
  // put your setup code here, to run once:
  // Setting everything HIGH to run the motor:
pinMode (speedPin,HIGH);
pinMode (dir1,HIGH);
pinMode (dir2,HIGH);
  // To make sure that it reads the joystick, we activate the serial port:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//read
int joystick = analogRead(A0);
//testing the reading
Serial.print("Resistance value: ");
Serial.print(joystick);
//when the joystick is up, the motor spins clockwise
if (joystick >= 512) {
  // Clockwise: 
digitalWrite(dir1,LOW);
digitalWrite(dir2,HIGH);     // if this is high, its clockwise
speed = (255.00/512.00) * joystick -255;
} 
//when the joystick is up, the motor spins counterclockwise
if (joystick <= 512) {  
  //counter Clockwise:
digitalWrite(dir1,HIGH);    //if this is high, its counter clockwise
digitalWrite(dir2,LOW);
speed = (-255.00/512.00) * joystick +255;
}
// choosing what speed the motor will go at.
analogWrite(speedPin,speed); 
Serial.print("    Speed:  ");
Serial.println(speed);
}
