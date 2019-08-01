/* Simple example code for Force Sensitive Resistor (FSR) with Arduino. More info: https://www.makerguides.com */
// Define FSR pin:

#include "src\FSR\FSR.h"
#include <string.h>

//Define variable to store sensor readings:
int fsrreading; //Variable to store FSR value
void setup() {

  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  Serial.println("Fin Setup");
}
void loop() {
  t_result res;
  String line;
  /*
  // Read the FSR pin and store the output as fsrreading:
  fsrreading = analogRead(fsrpin);
  // Print the fsrreading in the serial monitor:
  // Print the string "Analog reading = ".
  Serial.print("Analog reading = ");
  // Print the fsrreading:
  Serial.print(fsrreading);
  // We can set some threshholds to display how much pressure is roughly applied:
  if (fsrreading < 10) {
    Serial.println(" - No pressure");
  } else if (fsrreading < 200) {
    Serial.println(" - Light touch");
  } else if (fsrreading < 500) {
    Serial.println(" - Light squeeze");
  } else if (fsrreading < 800) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }*/
  res.reading = 0;
  FSR::read_and_eval(0, NULL, &res);
  Serial.print(res.reading);
  Serial.println(' ' + res.pressure_applied);
  
  delay(500); //Delay 500 ms.
}

