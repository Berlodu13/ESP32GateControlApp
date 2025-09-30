#include "rf_control.h"
#include "sms_control.h"
#include "gate_control.h"
#include "motion_detection.h"
#include "config.h"

void setup() {
  Serial.begin(9600);
  setupRF();
  setupSMS();
  setupGate();
  setupMotion();
  setupConfig();
}

void loop() {
  handleRF();
  handleSMS();
  handleMotion();
  // Additional logic can be added here
  delay(1000);
}
