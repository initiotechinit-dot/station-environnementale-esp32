// 03_bme280_read.ino
// Lecture du capteur BME280 (température, humidité, pression)

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  delay(1000);

  if (!bme.begin(0x76)) {
    Serial.println("Erreur : capteur BME280 non détecté.");
    while (true);
  }

  Serial.println("Capteur BME280 prêt.");
}

void loop() {
  Serial.print("Température : ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Humidité : ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pression : ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.println("----------------------");
  delay(3000);
}

