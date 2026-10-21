#include <Servo.h>

const int pingPin = 7;    // Датчик PING))) на пине 7
const int servoPin = 9;   // Сервопривод на пине 9
const int redPin = 3;     // Красный (RGB) на пине 3
const int bluePin = 5;    // Синий (RGB) на пине 5
const int greenPin = 6;   // Зеленый (RGB) на пине 6
const int piezoPin = 12;  // Зуммер на пине 12 (если подключен)

Servo gateServo;

void setup() {
  Serial.begin(9600);
  gateServo.attach(servoPin);
  gateServo.write(0); // Исходное положение — закрыто

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
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

void setColor(int r, int g, int b) {
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
  digitalWrite(bluePin, b);
}

void loop() {
  long distance = getDistanceCm();
  
  // Выводим расстояние в монитор порта для проверки
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 50) {
    // Ближе 50 см: ОТКРЫВАЕМ шлагбаум (90 градусов) + ЗЕЛЕНЫЙ свет
    gateServo.write(90);
    setColor(LOW, HIGH, LOW);
    digitalWrite(piezoPin, HIGH); // Сигнал зуммера без конфликта таймеров
  } 
  else if (distance >= 50 && distance < 100) {
    // От 50 до 100 см: машина подъезжает -> ПРИОТКРЫВАЕМ (45 градусов) + ЖЕЛТЫЙ свет
    gateServo.write(45);
    setColor(HIGH, HIGH, LOW);
    digitalWrite(piezoPin, LOW);
  } 
  else {
    // Дальше 100 см: ЗАКРЫВАЕМ шлагбаум (0 градусов) + КРАСНЫЙ свет
    gateServo.write(0);
    setColor(HIGH, LOW, LOW);
    digitalWrite(piezoPin, LOW);
  }

  delay(100);
}
