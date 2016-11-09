//#include <DHT.h>

/*-----------------------------------------------------------------
DHT Tester
Contoh penggunaan DHT11 dengan library yang dibuat oleh ladyada
Dapat digunakan untuk DHT22 dan DHT21
Author : Gerai Cerdas
Date   : 20 Oktober 2012
-----------------------------------------------------------------*/

#include "DHT.h"

#define DHTPIN 7 // definisikan pin yang digunakan utk sensor DHT11
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Tentukan jenis DHT yang digunakan (pilih salah satu)
// Saat ini yang dipilih adalah DHT11
#define DHTTYPE DHT11 // DHT 11 
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  // Baca humidity dan temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Cek hasil pembacaan, dan tampilkan bila ok
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Lembab: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    lcd.setCursor(0,0);
  lcd.print("LEMBAB: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("SUHU: ");
  lcd.print(t);
  lcd.print(" C");
  }
  delay(1000);
}

