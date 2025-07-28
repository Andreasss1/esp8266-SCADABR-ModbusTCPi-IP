#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>
#endif
#include <ModbusIP_ESP8266.h>
#include <DHT.h>

// DHT22 sensor configuration
#define DHT_PIN 2     // GPIO2 (D4 pada NodeMCU) - pin untuk DHT22
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

// Sensor data
float temperature = 0.0;

// ModbusIP object
ModbusIP mb;

// millis================================
// Set every 5 sec to update sensor data
unsigned long previousMillis = 0;
const long interval = 1000; // time interval in milliseconds (5 seconds)
//======================================

void setup() {
  Serial.begin(9600);

  // Initialize DHT sensor
  dht.begin();
  Serial.println("DHT22 sensor initialized");

  WiFi.begin("Arkaosi", "25011971");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mb.server();

  // Configure holding registers for temperature data only
  mb.addHreg(0); // Temperature integer value
  mb.addHreg(1); // Temperature decimal value

}

void loop() {
  delay(500);
  unsigned long currentMillis = millis();
  
  // Check if it's time to update sensor data
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the task was run
    previousMillis = currentMillis;

    // Read temperature from DHT22
    temperature = dht.readTemperature();
    
    // Check if reading failed
    if (isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");
      temperature = 0.0; // Set to 0 if read fails
    }

    // Print temperature data
    Serial.print("Temperature (DHT22) = ");
    Serial.print(temperature);
    Serial.println(" C");

    // Write temperature to Holding registers
    int t_int = int(temperature);
    int t_dec = int((temperature - t_int) * 100);
    mb.Hreg(0, t_int);
    mb.Hreg(1, t_dec);
  }

  // Call once inside loop()
  mb.task();
}