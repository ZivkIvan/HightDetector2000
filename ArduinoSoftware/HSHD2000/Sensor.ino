#include "NewPing.h"

//### ultrasoon sensor
const int trigPin = 8;// yellow on board //green on sensor
const int echoPin = 9;//orange on board // yellow on sensor

NewPing sonar(trigPin, echoPin, 15);


void SensorSetup(void){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int runSensor(void) {
  unsigned int uS = sonar.ping();
  unsigned int cm = sonar.convert_cm(uS);
  updateLCD(cm);
}

