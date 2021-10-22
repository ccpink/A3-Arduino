/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-library
 *
 * This example:
 *   + uses debounce for multiple buttons.
 *   + reads state of multiple buttons
 *   + detects the pressed and released events of multiple buttons
 */
#include <LiquidCrystal.h> 
#include <ezButton.h>

ezButton nickleBtn(2);  // create ezButton object that attach to pin 6;
ezButton looneyBtn(4);  // create ezButton object that attach to pin 7;
LiquidCrystal lcd(7,8,9,10,11,12);
int dollars = 0;
int change = .00;

void setup() {
  Serial.begin(9600);
  nickleBtn.setDebounceTime(50); // set debounce time to 50 milliseconds
  looneyBtn.setDebounceTime(50); // set debounce time to 50 milliseconds
  lcd.begin(16,2);
  lcd.print("Coin Machine");
}

void loop() {
  lcd.setCursor(0,1);
  nickleBtn.loop(); // MUST call the loop() function first
  looneyBtn.loop(); // MUST call the loop() function first
  

  if(nickleBtn.isPressed()){
    Serial.println("The button 1 is pressed");
    if((change + 25) != 100){
      change = change + 25;
    } else {
      dollars = dollars + 1;
      change = 0;
    }
  }
  if(looneyBtn.isPressed()){
    Serial.println("The button 2 is pressed");
    dollars = dollars + 1;
  }
  
  if(change <= 0 && dollars == 0){
    lcd.print(String(dollars) + "."  + String(change)+ "0");
  }
  else if(change == 0){
    lcd.print(String(dollars) + "."  + String(change) + "0");
    }
  else{
    lcd.print( String(dollars) + "."  + String(change) );
  }
}
