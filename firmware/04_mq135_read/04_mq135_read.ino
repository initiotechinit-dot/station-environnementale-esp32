// 04_mq135_read.ino
// Lecture analogique du capteur de qualité de l'air MQ-135

#define MQ135_PIN 34  // Entrée analogique de l'ESP32

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Lecture du capteur MQ-135");
}

void loop() {
  int airQuality = analogRead(MQ135_PIN);

  Serial.print("Valeur MQ-135 : ");
  Serial.println(airQuality);

  delay(2000);
}

