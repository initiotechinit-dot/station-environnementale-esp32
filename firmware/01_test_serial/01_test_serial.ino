// 01_test_serial.ino
// Test de base de la communication série avec l'ESP32

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 prêt. Communication série fonctionnelle.");
}

void loop() {
  Serial.println("Système actif...");
  delay(2000);
}

