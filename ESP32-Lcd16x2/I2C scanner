/*
  I2C Scanner untuk ESP32
  Fungsi: mencari alamat I2C dari LCD (atau device I2C lain)
  Buka Serial Monitor (baud 115200) setelah upload untuk lihat hasilnya
*/

#include <Wire.h>

void setup() {
  Wire.begin(21, 22); // SDA = GPIO 21, SCL = GPIO 22
  Serial.begin(115200);
  while (!Serial);
  Serial.println("\nMulai I2C Scanner...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device ditemukan di alamat 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0) {
    Serial.println("Tidak ada device I2C ditemukan. Cek wiring!");
  } else {
    Serial.println("Selesai scan.\n");
  }

  delay(5000); // Scan ulang tiap 5 detik
}
