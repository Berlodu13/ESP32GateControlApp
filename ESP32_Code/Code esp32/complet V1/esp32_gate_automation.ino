
#include <SoftwareSerial.h>
#include <SD.h>

// Define pins
#define RELAY_FULL_OPEN 5
#define RELAY_PEDESTRIAN 18
#define RF_PIN 4
#define PIR_SENSOR 19
#define SIM_RX 10
#define SIM_TX 11
#define SD_CS 13

SoftwareSerial sim800(SIM_RX, SIM_TX);

// Whitelist phone numbers
String whitelist[] = {"+33612345678", "+33698765432"};
int whitelistSize = 2;

// Setup function
void setup() {
  pinMode(RELAY_FULL_OPEN, OUTPUT);
  pinMode(RELAY_PEDESTRIAN, OUTPUT);
  pinMode(RF_PIN, INPUT);
  pinMode(PIR_SENSOR, INPUT);
  Serial.begin(9600);
  sim800.begin(9600);

  if (!SD.begin(SD_CS)) {
    Serial.println("SD card initialization failed!");
  } else {
    Serial.println("SD card ready.");
  }
}

// Function to check if number is whitelisted
bool isWhitelisted(String number) {
  for (int i = 0; i < whitelistSize; i++) {
    if (whitelist[i] == number) return true;
  }
  return false;
}

// Function to open gate fully
void openGateFull() {
  digitalWrite(RELAY_FULL_OPEN, HIGH);
  delay(3000);
  digitalWrite(RELAY_FULL_OPEN, LOW);
  Serial.println("Full gate opened.");
}

// Function to open gate for pedestrian
void openGatePedestrian() {
  digitalWrite(RELAY_PEDESTRIAN, HIGH);
  delay(2000);
  digitalWrite(RELAY_PEDESTRIAN, LOW);
  Serial.println("Pedestrian gate opened.");
}

// Function to check RF signal
void checkRF() {
  if (digitalRead(RF_PIN) == HIGH) {
    openGateFull();
  }
}

// Function to check SMS
void checkSMS() {
  if (sim800.available()) {
    String sms = sim800.readString();
    if (sms.indexOf("+CMT:") >= 0) {
      int start = sms.indexOf(""") + 1;
      int end = sms.indexOf(""", start);
      String sender = sms.substring(start, end);
      if (isWhitelisted(sender)) {
        if (sms.indexOf("OUVRIR") >= 0) openGateFull();
        else if (sms.indexOf("PIETON") >= 0) openGatePedestrian();
      } else {
        Serial.println("Unauthorized number: " + sender);
      }
    }
  }
}

// Function to log motion detection
void logMotion() {
  if (digitalRead(PIR_SENSOR) == HIGH) {
    File logFile = SD.open("motion.txt", FILE_WRITE);
    if (logFile) {
      logFile.println("Motion detected at: " + String(millis()));
      logFile.close();
      Serial.println("Motion logged.");
    }
  }
}

// Main loop
void loop() {
  checkRF();
  checkSMS();
  logMotion();
  delay(1000);
}
