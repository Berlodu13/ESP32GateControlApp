#include "gate_control.h"
#include <Arduino.h>

const int relayFull = 5;
const int relayPedestrian = 18;

void setupGate() {
  pinMode(relayFull, OUTPUT);
  pinMode(relayPedestrian, OUTPUT);
}

void openGateFull() {
  digitalWrite(relayFull, HIGH);
  delay(2000);
  digitalWrite(relayFull, LOW);
}

void openGatePedestrian() {
  digitalWrite(relayPedestrian, HIGH);
  delay(2000);
  digitalWrite(relayPedestrian, LOW);
}
