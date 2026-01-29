// 02_i2c_scan.ino
// Scan du bus I2C pour détecter les périphériques connectés
// Auteur : Initio Tech

#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Scan du bus I2C...");
  Wire.begin();

  byte error, address;
  int devicesFound = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Périphérique I2C détecté à l'adresse 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      devicesFound++;
    }
  }

  if (devicesFound == 0) {
    Serial.println("Aucun périphérique I2C détecté");
  } else {
    Serial.println("Scan terminé");
  }
}

void loop() {
  // Rien ici
}

