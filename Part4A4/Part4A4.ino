/*
  74HC595 Shift Register Demonstration 1
  74hc595-demo.ino
  Count in Binary and display on 8 LEDs
 
  Modified from "Hello World" example by Carlyn Maw,Tom Igoe and David A. Mellis
 
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
 
// Define Connections to 74HC595
 
// ST_CP pin 12
const int latchPin = 10;
// SH_CP pin 11
const int clockPin = 11;
// DS pin 14
const int dataPin = 12;

const char common = 'c';    // common anode
bool decPt = false;  // decimal point display flag

int D1 = 2;
int D2 = 3;
int D3 = 4;
int D4 = 5;

int number = 0;

unsigned long storeMillis = 0;
const int delay_duration = 1000;

 
void setup ()
{
  // Setup pins as Outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT); 

  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
}
 

void loop() {
  unsigned long currentMillis = millis();

  digitalWrite(D2, HIGH);
  digitalWrite(D1, LOW);
  updateDisplay(numToBits(number % 10));    // display alphanumeric digit
  
  if(number >= 10){
    digitalWrite(D2, LOW);
    digitalWrite(D1, HIGH);
    updateDisplay(numToBits(number / 10));    // display alphanumeric digit
  }
 
 if (currentMillis - storeMillis > delay_duration) {
  storeMillis = currentMillis; //update and store the value of storeMillis for the next iteration
  if(number < 59){
    number++;
    }else {
      number = 0;
    }
  }
  
}

void updateDisplay(byte eightBits) {
  if (common == 'a') {                  // using a common anonde display?
    eightBits = eightBits ^ B11111111;  // then flip all bits using XOR 
  }
  digitalWrite(latchPin, LOW);  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, eightBits); // send data
  digitalWrite(latchPin, HIGH); // update display
}


//TestCase
byte numToBitsTest(int someNumber) {
  return B11111001;     
}


byte numToBits(int someNumber) {
  switch (someNumber) {
    case 0:
      return B10100000;
      break;
    case 1:
      return B11111001;
      break;
    case 2:
      return B11000100;
      break;
    case 3:
      return B11010000;
      break;
    case 4:
      return B10011001;
      break;
    case 5:
      return B10010010;
      break;
    case 6:
      return B10000010;
      break;
    case 7:
      return B11111000;
      break;
    case 8:
      return B10000000;
      break;
    case 9:
      return B10011000;
      break;
  
  }
}
