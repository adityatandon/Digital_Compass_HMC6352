
//------------------- Connections --------------------

// 5V ---- 5V, GND ---- GND
// For Arduino UNO, SDA ---- Pin 4, SCL ---- Pin 5
// For Arduino MEGA, SDA ---- Pin 20, SCL ---- Pin 21

//-----------------------------------------------------

#include <Wire.h>   //Include I2c Library for communication with the Compass.

void setup()
{
  Serial.begin(9600); // Initiate Serial
  Wire.begin();       // Initiate I2C, Join Bus as Master 
}
 
void loop()
{ //------- Read Data ---------
 //Ox21 is used as the Wire.h library uses a 7 Bit Address
  Wire.beginTransmission(0x21);
  Wire.write("A");             // Send "Get Data" command
  delay(100);                  // Time required for Response
  Wire.requestFrom(0x21, 2);    // Receive 2 bytes of Data 
   byte MSB = Wire.read(); 
  byte LSB = Wire.read(); 
  Wire.endTransmission();
 
 //----------------------------

 //--------- Computation of Data -----------
   float heading = ((MSB << 8) + LSB) / 10; 
   Serial.print(heading);                     // Display Data
   Serial.println(" Degrees");
   delay(100);
 //-----------------------------------------
}
