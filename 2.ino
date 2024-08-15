void setup() {
}
#include <Servo.h>

// Pin untuk sensor gas
const int gasSensorPin = A0; // Sensor gas pada pin A0
int gasThreshold = 300; // Ambang batas untuk mendeteksi sampah organik (sesuaikan nilai ini)

// Pin untuk sensor ultrasonik
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int distanceThreshold = 5; // Ambang batas jarak untuk mendeteksi tempat sampah penuh (dalam cm)

// Pin untuk servo motor dan buzzer/LED
const int servoPin = 6;
const int notificationPin = 7; // Bisa digunakan untuk LED atau buzzer

Servo servoMotor;

void setup() {
  // Inisialisasi pin
  pinMode(gasSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(notificationPin, OUTPUT);

  // Inisialisasi servo motor
  servoMotor.attach(servoPin);
  servoMotor.write(0); // Posisi awal servo

  // Inisialisasi serial monitor untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Membaca nilai dari sensor gas
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Menggerakkan servo berdasarkan nilai sensor gas
  if (gasValue > gasThreshold) {
    // Jika terdeteksi gas tertentu, pindahkan ke kompartemen sampah organik
    servoMotor.write(90); // Menggerakkan servo ke posisi 90 derajat
    delay(1000); // Tunggu 1 detik
    servoMotor.write(0); // Kembalikan ke posisi awal
  }

  // Mengukur jarak menggunakan sensor ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Menghitung jarak dalam cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // Logika untuk pemberitahuan tempat sampah penuh
  if (distance < distanceThreshold) {
    // Tempat sampah penuh, beri peringatan
void loop() {
}
