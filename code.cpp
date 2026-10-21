#include <Servo.h>

const int pingPin = 7;    // Датчик PING)))
const int servoPin = 9;   // Сервопривод
const int redPin = 3;     // Красный (RGB)
const int greenPin = 5;   // Зеленый (RGB)
const int bluePin = 6;    // Синий (RGB)

const int piezoPin = 12;  // Пьезоэлемент (зуммер)
const int buttonPin = 2;  // Кнопка ручного открытия

Servo gateServo;
int currentAngle = 0;     // Текущий угол для плавного движения

void setup() {
  gateServo.attach(servoPin);
  gateServo.write(0);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  
  // Включаем внутреннюю подтяжку для кнопки (резистор не нужен)
  pinMode(buttonPin, INPUT_PULLUP);
}

long getDistanceCm() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);
  return duration / 29 / 2;
}

// Вспомогательная функция для установки цвета RGB
void setColor(bool r, bool g, bool b) {
  digitalWrite(redPin, r ? HIGH : LOW);
  digitalWrite(greenPin, g ? HIGH : LOW);
  digitalWrite(bluePin, b ? HIGH : LOW);
}

// Плавный поворот сервопривода
void moveGateTo(int targetAngle) {
  while (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) currentAngle += 5;
    else currentAngle -= 5;
    gateServo.write(currentAngle);
    delay(15);
  }
}

void loop() {
  long distance = getDistanceCm();
  bool buttonPressed = (digitalRead(buttonPin) == LOW); // Нажата ли кнопка

  if (distance < 50 || buttonPressed) {
    // 1. Машина совсем близко (< 50 см) ИЛИ нажата кнопка охраны:
    // Включаем ЗЕЛЕНЫЙ, открываем шлагбаум и подаем прерывистый звук
    setColor(false, true, false);
    moveGateTo(90);
    tone(piezoPin, 1000, 100); // Короткий писк зуммера
    delay(200);
  } 
  else if (distance >= 50 && distance < 100) {
    // 2. Машина приближается (от 50 до 100 см):
    // Включаем ЖЕЛТЫЙ (Красный + Зеленый), шлагбаум готовится, но пока закрыт
    setColor(true, true, false);
    moveGateTo(0);
    noTone(piezoPin);
    delay(100);
  } 
  else {
    // 3. Машина далеко (> 100 см):
    // Включаем КРАСНЫЙ, шлагбаум закрыт, тишина
    setColor(true, false, false);
    moveGateTo(0);
    noTone(piezoPin);
    delay(100);
  }
}
