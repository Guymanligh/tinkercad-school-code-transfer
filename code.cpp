#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int potPin = A0;
int currentAngle = 0;

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
}

void loop() {
  int potValue = analogRead(potPin);

  // Если потенциометр повернут вправо (близко к 1023) — останавливаем движение
  if (potValue < 1000) {
    // Чем ближе ручка к положению как на фото (0), тем меньше задержка (2 мс) и выше скорость
    int stepDelay = map(potValue, 0, 1000, 2, 60);

    currentAngle++;
    if (currentAngle > 180) {
      currentAngle = 0; // Сброс в 0 для постоянного кручения вправо
    }

    servo1.write(currentAngle);
    servo2.write(currentAngle);
    servo3.write(currentAngle);
    servo4.write(currentAngle);

    delay(stepDelay);
  }
}
