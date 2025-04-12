# 🌱 Arduino Smart Irrigation System


This project is an **automated irrigation system** that monitors **soil moisture** and **temperature** using an LCD display, relay-controlled water pump, and DS18B20 temperature sensor.

The system automatically turns on the water pump when the soil is dry and stops it when moisture is detected. It also continuously displays soil and temperature status on the LCD.

---

## 🛠️ Hardware Required

- Arduino UNO or compatible board  
- LCD ST7032 (I2C)  
- DS18B20 Temperature Sensor  
- Soil Moisture Sensor (Digital)  
- Relay Module  
- Jumper Wires  
- Breadboard or PCB  
- Power Supply or USB

---

## 📦 Required Libraries

Install the following Arduino libraries via Library Manager (`Sketch > Include Library > Manage Libraries`):

- `LCD_ST7032`  
- `OneWire`  
- `DallasTemperature`

---

## 🔌 Pin Connections

| Component              | Arduino Pin |
|------------------------|-------------|
| Relay Module (IN)      | D3          |
| Soil Sensor (Digital)  | D6          |
| DS18B20 Data           | D2          |
| LCD (ST7032 I2C)       | SDA/SCL     |

**Note:** Use a 4.7k ohm pull-up resistor between the DS18B20 data line and 5V.

---



