#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

#define ONE_WIRE_BUS 2
#define DHTPIN 3
#define DHTTYPE DHT22
#define MOISTURE_PIN A0

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature compostSensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE);

int readMoistureAverage(int samples = 10) {
  long total = 0;

  for (int i = 0; i < samples; i++) {
    total += analogRead(MOISTURE_PIN);
    delay(10);
  }

  return total / samples;
}

void printTelemetry(float compostTemp, float ambientTemp, float humidity, int moistureValue) {
  Serial.print("Compost Temp: ");
  Serial.print(compostTemp);
  Serial.print(" C | Ambient Temp: ");
  Serial.print(ambientTemp);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | Moisture Signal: ");
  Serial.println(moistureValue);
}

void setup() {
  Serial.begin(9600);
  compostSensors.begin();
  dht.begin();
  Serial.println("Arduino Compost Monitoring System Starting");
}

void loop() {
  compostSensors.requestTemperatures();
  float compostTemp = compostSensors.getTempCByIndex(0);

  float humidity = dht.readHumidity();
  float ambientTemp = dht.readTemperature();

  int moistureValue = readMoistureAverage();

  if (compostTemp == DEVICE_DISCONNECTED_C) {
    Serial.println("DS18B20 sensor error: compost probe disconnected.");
    delay(3000);
    return;
  }

  if (isnan(humidity) || isnan(ambientTemp)) {
    Serial.println("DHT22 sensor error: invalid ambient reading.");
    delay(3000);
    return;
  }

  printTelemetry(compostTemp, ambientTemp, humidity, moistureValue);

  delay(5000);
}
