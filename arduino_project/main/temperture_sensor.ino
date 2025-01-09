#include <OneWire.h>
#include <DallasTemperature.h>

// DS18B20 Temperature Sensor Setup
#define ONE_WIRE_BUS 7 // Data pin for the temperature sensor
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Function to initialize the temperature sensor
void initializeTemperatureSensor() {
  Serial.begin(9600);
  Serial.println("Initializing DS18B20 Temperature Sensor...");
  sensors.begin();
  Serial.println("Temperature Sensor Ready.");
}

// Function to read temperature
float readTemperature() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
