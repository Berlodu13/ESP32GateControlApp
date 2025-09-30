#include "config.h"
#include <Arduino.h>

String whitelist[] = {"+33612345678", "+33698765432"};
int whitelistSize = 2;

void setupConfig() {
  // Load config from SD or EEPROM if needed
}

bool isAuthorized(String number) {
  for (int i = 0; i < whitelistSize; i++) {
    if (whitelist[i] == number) {
      return true;
    }
  }
  return false;
}
