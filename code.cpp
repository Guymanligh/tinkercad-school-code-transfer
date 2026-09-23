#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int potPin = A0;

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
}

void loop() {
  int potValue = analogRead(potPin);

  // Потенциометр регулирует скорость:
  // 0   = максимальная скорость вправо
  // 1023 = остановка
  int speed = map(potValue, 0, 1023, 180, 90);

  servo1.write(speed);
  servo2.write(speed);
  servo3.write(speed);
  servo4.write(speed);

  delay(10);
}
