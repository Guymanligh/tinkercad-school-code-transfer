#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int potPin = A0;

// Точка остановки сервопривода.
// Обычно около 90, но у разных сервоприводов может отличаться.
const int STOP = 90;

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);

  // Полная остановка при включении
  servo1.write(STOP);
  servo2.write(STOP);
  servo3.write(STOP);
  servo4.write(STOP);
}

void loop() {
  int potValue = analogRead(potPin);

  // 0 = STOP
  // 1023 = максимальная скорость вправо
  int speed = map(potValue, 0, 1023, STOP, 180);

  servo1.write(speed);
  servo2.write(speed);
  servo3.write(speed);
  servo4.write(speed);

  delay(10);
}
