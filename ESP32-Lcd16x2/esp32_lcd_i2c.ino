/*
  ESP32 + LCD I2C (16x2) - Contoh Dasar
  Library dibutuhkan: LiquidCrystal I2C (Frank de Brabander)
  
  Wiring:
  LCD I2C GND -> ESP32 GND
  LCD I2C VCC -> ESP32 5V / VIN
  LCD I2C SDA -> ESP32 GPIO 21
  LCD I2C SCL -> ESP32 GPIO 22
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alamat I2C default biasanya 0x27 atau 0x3F
// Jika layar tidak muncul, coba scan alamat I2C dulu (lihat kode scanner terpisah)
LiquidCrystal_I2C lcd(0x27, 16, 2); // (alamat, kolom, baris)

void setup() {
  Serial.begin(115200);

  // Inisialisasi I2C dengan pin custom ESP32 (SDA, SCL)
  Wire.begin(21, 22);

  lcd.init();        // Inisialisasi LCD
  lcd.backlight();    // Nyalakan lampu latar

  lcd.setCursor(0, 0); // Kolom 0, Baris 0
  lcd.print("Halo, ESP32!");

  lcd.setCursor(0, 1); // Kolom 0, Baris 1
  lcd.print("LCD I2C Siap");
  delay(4000);
}

void loop() {
  // Contoh: tampilkan waktu berjalan (detik) di baris kedua
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis() / 1000);
  lcd.print("s   "); // spasi ekstra buat hapus sisa angka lama

  delay(1000);
}
