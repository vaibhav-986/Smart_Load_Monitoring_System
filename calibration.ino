#include "HX711.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd( 8,  9,  4,  5,  6,  7);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = A2;
const int LOADCELL_SCK_PIN = A1;

HX711 scale;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Project By: ");
  lcd.setCursor(0,1);
  lcd.print("G V VAIBHAV ");
  delay(3000);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready()) {
    scale.set_scale();    
    delay(5000);
    scale.tare();
    lcd.clear();
    lcd.print("Tare done...");
    lcd.setCursor(0,1);
    lcd.print("Place a known weight on the scale...");
    delay(5000);
    long reading = scale.get_units(10);
    lcd.clear();
    lcd.print("Result: ");
    lcd.setCursor(0,1);
    lcd.print(reading);
    delay(5000);
  } 
  else {
    lcd.clear();
    lcd.print("HX711 not found.");
  }
  delay(2000);
}

