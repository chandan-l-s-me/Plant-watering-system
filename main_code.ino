#include <Wire.h>
#include <LCD_ST7032.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Pins
#define RELAY_PIN 3
#define SOIL_PIN 6
#define TEMP_PIN 2  // DS18B20 data pin

// LCD and Temperature
LCD_ST7032 lcd;
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

int water;      // Soil sensor value
float tempC;    // Temperature value

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_PIN, INPUT);

  Serial.begin(9600);

  lcd.begin();
  lcd.setcontrast(40);
  lcd.clear();
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  Serial.println("System Ready");
  delay(2000);
  lcd.clear();

  sensors.begin();
}

void loop() {
  // Read soil moisture
  water = digitalRead(SOIL_PIN);
  Serial.print("Soil Moisture (digital): ");
  Serial.println(water);

  // Read temperature
  sensors.requestTemperatures();
  tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  // Show on LCD - Top Line: Soil Status
  lcd.clear();
  delay(100);
  if (water == LOW) {
    // Soil is moist
    digitalWrite(RELAY_PIN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Soil: Moist");
    Serial.println("Soil is moist. Skipping watering.");
  } else {
    // Soil is dry
    digitalWrite(RELAY_PIN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Soil: Dry");
    Serial.println("Soil is dry. Watering...");

    lcd.setCursor(1, 0);
    lcd.print("Watering 5 sec");
    delay(5000);

    digitalWrite(RELAY_PIN, HIGH);
    lcd.clear();
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("Watering Done");
    lcd.setCursor(1, 0);
    lcd.print("Relay OFF");
    Serial.println("Watering complete.");
    delay(2000);
  }

  // Show temperature on LCD (bottom line)
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  delay(5000); // Wait before next loop
}
