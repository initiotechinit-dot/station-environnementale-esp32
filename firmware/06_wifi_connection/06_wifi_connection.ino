// 06_wifi_connection.ino
// Connexion Wi-Fi de base avec l'ESP32

#include <WiFi.h>

const char* ssid = "VOTRE_SSID";
const char* password = "VOTRE_MOT_DE_PASSE";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("Connexion au réseau Wi-Fi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnecté au Wi-Fi");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

void loop() {}

