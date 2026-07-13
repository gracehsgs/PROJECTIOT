const int ENA = 5;   // PWM kecepatan
const int IN1 = 8;
const int IN2 = 9;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Motor putar maju
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100); // kecepatan 0-255, sesuaikan
  delay(3000);

  // Motor berhenti sebentar
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);

  // Motor putar mundur
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100);
  delay(3000);

  // Motor berhenti lagi
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
}