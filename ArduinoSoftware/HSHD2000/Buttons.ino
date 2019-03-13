//### btnStart
int btnStart = 2;

//### btnStop
int btnStop = 3;

//### btnServo
int btnServo = 4;

void ButtonsSetup(void) {
  pinMode(btnStart, INPUT);  
  pinMode(btnStop, INPUT);  
  pinMode(btnServo, INPUT);
}

int getBtnGreen() {
  return digitalRead(btnStart); 
}
int getBtnRed() {
  return digitalRead(btnStop);
}
int getButtonYellow() {
  return digitalRead(btnServo);
}

