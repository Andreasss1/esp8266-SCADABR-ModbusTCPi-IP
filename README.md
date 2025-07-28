# 🌡️ Temperature Monitoring with ESP8266 and DHT22 via Modbus TCP to ScadaBR

This project demonstrates how to use an **ESP8266** microcontroller with a **DHT22 temperature sensor** to read temperature data in real time and send it to **ScadaBR** using the **Modbus TCP/IP** protocol.

## 🖼️ ScadaBR Interface

![ScadaBR Interface](https://github.com/Andreasss1/esp8266-SCADABR-ModbusTCPi-IP/blob/main/esp8266-dht22-SCADABR.png)

## 🧰 Hardware Components

- ESP8266 (NodeMCU)
- DHT22 Temperature and Humidity Sensor
- Wi-Fi Network
- Computer running ScadaBR

## 🔌 DHT22 to ESP8266 Wiring

| DHT22 Pin | ESP8266 Pin |
|-----------|-------------|
| VCC       | 3.3V        |
| DATA      | D4 / GPIO2  |
| GND       | GND         |

## 📦 Required Arduino Libraries

- [ModbusIP_ESP8266](https://github.com/andresarmento/modbus-esp8266)
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
- [Adafruit Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor)

> 📁 The complete Arduino source code is available in a separate file within this repository.

## 🔄 Modbus Register Mapping

| Register | Description           |
|----------|-----------------------|
| 0        | Temperature (integer) |
| 1        | Temperature (decimal) |

**Example**:  
If `Hreg 0 = 30` and `Hreg 1 = 75`, then the displayed temperature is **30.75 °C**.

## 📊 Visualization in ScadaBR

The temperature data is displayed in real-time within the ScadaBR interface, as shown in the image above. ScadaBR is configured to poll the ESP8266 using Modbus TCP and map the registers into graphical widgets or digital displays.

<div align="center">

## 📬 Need a Similar Project? Let's Collaborate!
If you need a **custom IoT project** for **smart home, agriculture, industrial monitoring**, or other use cases,  
I’m ready to assist you!  

📧 **Reach out at:**  
### andreas.sebayang9999@gmail.com  

Let’s create something amazing together! 🚀

</div>
