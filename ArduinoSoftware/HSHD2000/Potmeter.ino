//### potmeter
int customHight = analogRead(A0);
int hightLimit;

void setHight(void) {
  int customHight = analogRead(A0); // Reads the potentiometer
  hightLimit = (customHight / 100);
}

int getHightLimit(void){
  return hightLimit;
}

