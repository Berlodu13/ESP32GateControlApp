#include "motion_detection.h"
#include <Arduino.h>
#include <SD.h>

const int pirPin = 19;

void setupMotion() {
  pinMode(pirPin, INPUT);
  SD.begin();
}

void handleMotion() {
  if (digitalRead(pirPin) == HIGH) {
    File file = SD.open("/motion.txt", FILE_WRITE);
    if (file) {
      file.println("Motion detected");
      file.close();
    }
  }
}
