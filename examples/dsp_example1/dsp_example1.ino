/*
  Example sketch that demonstrates the use of the DataSeriesPod library for the Arduino boards
  This sketch simulates the continous reading of a sensor. At predefined time intervals a summary
  is outputed and the whole process is repeated constantly.
  Created 2019 by Michael Matus
*/

// Import required library
#include <DataSeriesPod.h>

// create an instance of the DataSeriesPod class with a given name
DataSeriesPod dsp = DataSeriesPod("ID_1");

// define a time interval (in ms) to fetch statistical parameters
unsigned long timeInterval = 1000UL; // 1 second

void setup() {
  Serial.begin(9600);
}

void loop() {
  // record a data point
  dsp.update(getSensorData());
  // check for break condition
  if (dsp.getDuration() >= timeInterval) {
    // consume parameters
    outputResult();
    // after consuming the parameters, a restart() is required
    dsp.restart();
  }
}

// This function simulates sensor output
int getSensorData() {
  delay(random(1,100));
  return random(0, 1023);
}

// This function is called when the break condition is true
void outputResult() {
  Serial.println(dsp.toString());
  Serial.print("sample size: ");
  Serial.println(dsp.getSampleSize());
  Serial.print("duration in ms: ");
  Serial.println(dsp.getDuration());
  Serial.println();
}
