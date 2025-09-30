#include "rf_control.h"
#include "gate_control.h"
#include <Arduino.h>

const int rfPin = 4;

void setupRF() {
  pinMode(rfPin, INPUT);
}

void handleRF() {
  if (digitalRead(rfPin) == HIGH) {
    openGateFull();
  }
}
