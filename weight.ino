#include <Arduino.h>
#include "HX711.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd( 8,  9,  4,  5,  6,  7);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = A2;
const int LOADCELL_SCK_PIN = A1;

// values for overweight and underweight detection 
const int WEIGHT_OVERLOAD = 60;
const int WEIGHT_UNDERLOAD = 15;



HX711 scale;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Project By: ");
  lcd.setCursor(0,1);
  lcd.print("G V VAIBHAV ");
  delay(3000);
  
  lcd.clear();
  lcd.print("System Init..");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
  scale.read();

  scale.read_average(20);

  scale.get_value(5);

  scale.get_units(5);
            
// this value is obtained by calibrating the scale with known weights;
scale.set_scale(-750.44);


  scale.tare();               // reset the scale to 0

  delay(1000);

// print a raw reading from the ADC
  scale.read();

// print the average of 20 readings from the ADC
  scale.read_average(20);

// print the average of 5 readings from the ADC minus the tare weight, set with tare()
  scale.get_value(5);

// print the average of 5 readings from the ADC minus tare weight, divided
  scale.get_value(5);

  lcd.clear();
  lcd.print("Start Measurement:");
  delay(2000);
}

void loop() {
  long weight = 0;
  scale.get_units(5);
  weight = scale.get_units(10);
  lcd.clear();
  lcd.print("Measured Wt: ");
  lcd.print(weight);
  lcd.setCursor(0,1);
  if (weight< WEIGHT_UNDERLOAD) {
    lcd.print("Under Weight");
  } else if (weight> WEIGHT_OVERLOAD) {
    lcd.print("Over Weight");
  } else {
    lcd.print("Control Weight");
  }

  delay(2000);
}