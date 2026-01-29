// 05_structured_data.ino
// Exemple de structuration des données de mesure

struct Measurement {
  float temperature;
  float humidity;
  float pressure;
  int airQuality;
};

void setup() {
  Serial.begin(115200);
  delay(1000);

  Measurement m;
  m.temperature = 23.4;
  m.humidity = 48.1;
  m.pressure = 1012.6;
  m.airQuality = 320;

  Serial.println("Mesure structurée :");
  Serial.print("Température : "); Serial.println(m.temperature);
  Serial.print("Humidité : "); Serial.println(m.humidity);
  Serial.print("Pression : "); Serial.println(m.pressure);
  Serial.print("Qualité de l'air : "); Serial.println(m.airQuality);
}

void loop() {}

