#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to pin 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin(); // Start the DS18B20 sensor
  Serial.println("DS18B20 Temperature Sensor");
}

void loop() {
  sensors.requestTemperatures(); // Request temperature from sensor
  float temperatureC = sensors.getTempCByIndex(0); // Get temperature in Celsius
  
  // Check for invalid reading
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor disconnected!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  }
  
  delay(1000); // Wait 1 second before the next reading
}
