// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this
//Code help found here https://www.arduino.cc/en/Tutorial/LibraryExamples/MasterWriter
// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
char message[7] = "Charles";
void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);           // start serial for output
}



void loop()
{
  Serial.print("Sending over the line: ");
  Serial.println(message);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(message);              
  Wire.endTransmission();    // stop transmitting

  delay(500);
}
