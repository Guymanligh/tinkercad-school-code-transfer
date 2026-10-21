#include <Servo.h>

const int pingPin = 7;  // Пин SIG датчика PING)))
const int servoPin = 9; // Пин сервопривода
const int redPin = 3;   // Красный канал RGB
const int greenPin = 5; // Зеленый канал RGB
const int bluePin = 6;  // Синий канал RGB

Servo gateServo;

void setup() {
  gateServo.attach(servoPin);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

long getDistanceCm() {
  // Отправляем импульс
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // Принимаем отраженный сигнал на том же пине
  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);

  // Переводим время в сантиметры
  return duration / 29 / 2;
}

void loop() {
  long distance = getDistanceCm();

  if (distance < 50) {
    // Машина близко (меньше 50 см): открываем шлагбаум, включаем ЗЕЛЕНЫЙ
    gateServo.write(90);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else {
    // Путь свободен: закрываем шлагбаум, включаем КРАСНЫЙ
    gateServo.write(0);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  delay(100);
}
