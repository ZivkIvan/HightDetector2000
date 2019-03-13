#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h"

#define I2C_ADDR 0x3F  // Add your address here.
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

#define MAX_DISTANCE 15 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void LCDSetup() {
  lcd.begin ( 16 , 2 );
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
}

//Het scherm wordt geupdate
void updateLCD(int sensDist) {

 int detectedHight = 12 - sensDist;
  if ( detectedHight < 0 || detectedHight > 12) {
    detectedHight = 0;
  }

  setDetectedHight(detectedHight);
  
  delay(1);

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print(detectedHight);
  lcd.print(" cm | Main:");
  lcd.print(Main_SSW);

  lcd.setCursor (0, 1);
  lcd.print(getHightLimit());
  lcd.print(" cm | ");
  lcd.print("St:");
  lcd.print(getStepCount());
}

void TestLCD() {
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Testmode is ON");

  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("_1234567890&%@^=");
}

