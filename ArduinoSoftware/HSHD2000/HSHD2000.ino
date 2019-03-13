/*  High Speed Hight Detector 2000

  System that detects the hight of an object and compares it with the given hight.
  If the hight is different, the object will be removed from the production.

  Hardware:
  - Stepper motor
  - Servo
  - US Sensor
  - Potentionmeter
  - 12V 1.5A adapter
  - 3 buttons
  - 3 led
  - Arduino

  Green Button:
  Automatich production is started. Green Led is on.
  If the sensor detects a difrent hight, Yellow led is going on and servo is activated.
  The transport needs to stop after a amount of steps, so the servo can push the object of the production.

  Yellow Button:
  Activates the Yellow led, stops the transport(if it is running) and activates the servo.

  Red Button:
  The Production is stopped. Red led is on.

    by Ivan Zivkovic

*/

// defines pins numbers
#include <Servo.h>

Servo MyServo;

unsigned int detectedHight;


boolean stepperActive;
boolean servoActive;
boolean sensorActive;
boolean redLedActive;
boolean greenLedActive;
boolean yellowLedActive;

boolean autoProduction;
boolean kickOff;


int hightOffset = 1; // a tolerance of the given hight
int brakeOffset = 180; // ammount of stepps between sensor and servo



int Main_SSW;
int memStepCount;

unsigned long time;
unsigned long stepper;
char incomingOption;

void setup(void) {

  time = millis();
  stepper = millis();

  LCDSetup();
  LedSetup();
  SensorSetup();
  ServoSetup();
  ButtonsSetup();
  StepperSetup();
  SerialSetup();


  stepperActive = false;
  servoActive = false;
  sensorActive = false;
  redLedActive = false;
  greenLedActive = false;
  yellowLedActive = false;

  autoProduction = false;
  kickOff = false;

}

void loop(void) {

  if (millis() > stepper + 10) {
    loopStepper();
    stepper = millis();
  }

 if (millis() > time + 500) {
    runSensor();
    time = millis();
  }
  
  GetCommand();
  loopLed();
  setHight();
  runServo(servoActive);

  int btnGreen = getBtnGreen();
  int btnRed = getBtnRed();
  int btnYellow = getButtonYellow();

  if (btnGreen == LOW && btnRed == HIGH && btnYellow == HIGH) { // start bitton
    Main_SSW = 9;
    delay(10);
  }
  if (btnRed == LOW && btnGreen == HIGH && btnYellow == HIGH) { // StopButton
    Main_SSW = 0;
    delay(10);
  }
  if (btnYellow == LOW && btnRed == HIGH && btnGreen == HIGH) { // servobutto
    Main_SSW = 1;
    delay(10);
  }

  switch (Main_SSW) {
    case 0:// stop everything
      greenLedActive = false;
      redLedActive = true;
      stepperActive = false;
      yellowLedActive = false;
      servoActive = false;
      autoProduction = false;
      kickOff = false;
      break;

    case 1:
      kickOff = true;
      servoActive = true;
      yellowLedActive = true;
      Main_SSW = 2;
      break;

    case 2:
      delay(300);
      if (servoActive == true) {
        Main_SSW = 3;
      }
      break;

    case 3:
      if (runServo(servoActive) == true) {
        Main_SSW = 4;
      }
      break;

    case 4:
      servoActive = false;
      Main_SSW = 5;
      break;

    case 5:
      if (servoActive == false) {
        Main_SSW = 6;
      }
      break;
    case 6:
      if (runServo(servoActive) == false) {
        if (autoProduction == true) {
          Main_SSW = 10;
        }
        else if (kickOff == true) {
          Main_SSW = 0;
        }
      }
      break;

    case 9:
      autoProduction = true;
      Main_SSW = 10;
      break;

    case 10:
      if (autoProduction == true) {
        stepperActive = true;
        greenLedActive = true;
        redLedActive = false;
        yellowLedActive = false;
        Main_SSW = 11;
      }
      break;

    case 11:
      if (detectedHight > 1) {
        if (detectedHight - hightOffset > getHightLimit() || detectedHight + hightOffset < getHightLimit()) {
          memStepCount = getStepCount();
          Main_SSW = 12;
        }
        break;
      }
      break;
    case 12:

      if (getStepCount() >= memStepCount + brakeOffset) {
        stepperActive = false;
        servoActive = true;
        Main_SSW = 13;
        //stepCount = 0;
        setStepCount(0);
      }
      break;

    case 13:
      if (stepperActive == false) {
        Main_SSW = 2;
      }
      break;
  }
}

void loopStepper(void) {
  if ( stepperActive == true) {
    runStepper();
  } else {
    stopStepper();
  }
}

void setDetectedHight(int detHight) {
  detectedHight = detHight;
}

void externalCommand(String cmnd) {
  if (cmnd == "btn:Start") {
    Main_SSW = 9;
    cmnd = "";
  }
  if (cmnd == "btn:Stop") {
    Main_SSW = 0;
    cmnd = "";
  }
  if (cmnd == "btn:Servo") {
    Main_SSW = 1;
    cmnd = "";
  }
}






