// 07_data_send.ino
// Envoi simple de données vers un serveur distant

#include <WiFi.h>
#include <HTTPClient.h>

const char* serverUrl = "http://example.com/data";

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"temperature\":22.5,\"humidity\":45.0}";
    int httpCode = http.POST(payload);

    Serial.print("Code de réponse serveur : ");
    Serial.println(httpCode);

    http.end();
  } else {
    Serial.println("Wi-Fi non connecté");
  }

  delay(10000);
}

