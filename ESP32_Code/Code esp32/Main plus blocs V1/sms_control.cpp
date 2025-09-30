#include "sms_control.h"
#include "gate_control.h"
#include "config.h"
#include <Arduino.h>

void setupSMS() {
  // Initialize SIM800L module here
}

void handleSMS() {
  String sender = "+33612345678"; // Simulated sender
  String message = "OUVRIR"; // Simulated message

  if (isAuthorized(sender)) {
    if (message == "OUVRIR") {
      openGateFull();
    } else if (message == "PIETON") {
      openGatePedestrian();
    }
  }
}
