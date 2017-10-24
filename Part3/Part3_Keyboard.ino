#include "pitches.h"

const int threshold = 20;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_B3, NOTE_C4
};

void setup() {
}

void loop() {
    int sensorReading0 = analogRead(4);

    // if the sensor is pressed hard enough:
    if (sensorReading0 > threshold) {
        // play the note corresponding to this sensor:
        tone(8, NOTE_CS8, 10);
      }
      
    int sensorReading1 = analogRead(1);

    if (sensorReading1 > threshold) {
        // play the note corresponding to this sensor:
        tone(8, NOTE_B3, 10);
      }
}
