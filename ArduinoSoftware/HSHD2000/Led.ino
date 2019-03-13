//### status led Red
int ledRed = 10;

//### status led Green
int ledGreen = 11;

//### status led Yellow
int ledYellow = 12;


void LedSetup() {
  pinMode(ledRed, OUTPUT);  
  pinMode(ledGreen, OUTPUT); 
  pinMode(ledYellow, OUTPUT);
}

// Led status
void loopLed(void) {
  if ( redLedActive == true) {
    digitalWrite(ledRed, HIGH);
  } else {
    digitalWrite(ledRed, LOW);
  }
  if ( greenLedActive == true) {
    digitalWrite(ledGreen, HIGH);
  } else {
    digitalWrite(ledGreen, LOW);
  }
  if ( yellowLedActive == true) {
    digitalWrite(ledYellow, HIGH);
  } else {
    digitalWrite(ledYellow, LOW);
  }
}

void LedTest(void) {
  digitalWrite(ledRed, HIGH);
  delay(500);
  digitalWrite(ledRed, LOW);
  delay(500);
  digitalWrite(ledGreen, HIGH);
  delay(500);
  digitalWrite(ledGreen, LOW);
  delay(500);
  digitalWrite(ledYellow, HIGH);
  delay(500);
  digitalWrite(ledYellow, LOW);
  delay(500);
}
