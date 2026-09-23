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

  // В текущем положении (как на фото) analogRead возвращает 0 — это максимум скорости (180).
  // В противоположном крайнем положении (1023) — полная остановка (90).
  int speedSignal = map(potValue, 0, 1023, 180, 90);

  // Синхронно передаем скорость на все 4 сервопривода
  servo1.write(speedSignal);
  servo2.write(speedSignal);
  servo3.write(speedSignal);
  servo4.write(speedSignal);

  delay(20);
}
