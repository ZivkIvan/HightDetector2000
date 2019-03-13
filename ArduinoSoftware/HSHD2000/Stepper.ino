//### Spepper motor
const int stepPin = 6;// blue on board
const int dirPin = 7;// midle green on board
int stepCount;         // To keep track of the steps


void StepperSetup(void) {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH); //Enables the motor to move CounterClickWise
}

void stopStepper() {
  digitalWrite(stepPin, LOW);
  stepCount = 0;
}

void runStepper(void) {
    digitalWrite(dirPin, HIGH);
    stepCount++;
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(10);
}

int getStepCount(void) {
  return stepCount;
}

void setStepCount(int setCountTo) {
  stepCount = setCountTo;
}

void StepperTest(void) {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(10);
}
