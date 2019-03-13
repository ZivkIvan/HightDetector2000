#include <Servo.h>

//### Servo
int servoPin = 5; // // paars on board // wellow servo

Servo myservo;

void ServoSetup(void) {
  myservo.attach(servoPin);
}

//Servo gaat op eind positie en komt weer terug
bool runServo(bool kickOff) {
  if ( servoActive == true) {
    myservo.write(130);
    return true;
  } else {
    myservo.write(50);
    return false;
  }
}

void ServoTest(void) {
  myservo.write(130);
  delay(500);
  myservo.write(50);
  delay(500);
  myservo.write(130);
  delay(500);
  myservo.write(50);
  delay(500);
  myservo.write(130);
  delay(500);
  myservo.write(50);
}
