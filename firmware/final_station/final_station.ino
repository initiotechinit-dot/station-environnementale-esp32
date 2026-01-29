// final_station.ino
// Station environnementale complète - ESP32
// Mesure périodique + capteurs + Wi-Fi + affichage série
// Auteur : Initio Tech

#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define MQ135_PIN 34
#define SEALEVELPRESSURE_HPA 1013.25

// ---- Wi-Fi (à configurer par l'utilisateur) ----
const char* ssid = "VOTRE_SSID";
const char* password = "VOTRE_MOT_DE_PASSE";

// ---- Capteur ----
Adafruit_BME280 bme;

// ---- Gestion du temps ----
unsigned long lastMeasurement = 0;
const unsigned long measurementInterval = 10000; // 10 secondes

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Démarrage de la station environnementale");

  // Initialisation I2C
  Wire.begin();

  // Initialisation BME280
  if (!bme.begin(0x76)) {
    Serial.println("Erreur : capteur BME280 non détecté.");
    while (true);
  }

  Serial.println("Capteur BME280 prêt");

  // Connexion Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connexion Wi-Fi");

  unsigned long startAttempt = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttempt < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connecté");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWi-Fi non disponible, mode hors ligne");
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMeasurement >= measurementInterval) {
    lastMeasurement = currentMillis;

    // Lecture capteurs
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() / 100.0F;
    int airQuality = analogRead(MQ135_PIN);

    // Affichage
    Serial.println("----- Mesure -----");
    Serial.print("Température : ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidité : ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Pression : ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("Qualité de l'air (brut) : ");
    Serial.println(airQuality);

    Serial.println("------------------");

    // Vérification Wi-Fi
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Wi-Fi déconnecté");
    }
  }
}

