#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int potPin = A0;
int currentAngle = 0; // Текущий угол поворота

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
}

void loop() {
  int potValue = analogRead(potPin);

  // Преобразуем значение потенциометра в задержку (скорость):
  // Когда потенциометр в положении как на фото (0) — задержка минимальная (2 мс), скорость максимальная.
  // Когда потенциометр выкручен в противоположную сторону (1023) — сервоприводы останавливаются.
  int stepDelay = map(potValue, 0, 1023, 2, 50);

  // Если потенциометр не в самом конце (не 0 скорость), крутим вправо
  if (potValue < 1015) {
    currentAngle++; // Увеличиваем угол (вращение в одну сторону)
    
    if (currentAngle > 180) {
      currentAngle = 0; // Сбрасываем в 0 для повторения цикла
    }

    // Синхронно передаем угол на все сервоприводы
    servo1.write(currentAngle);
    servo2.write(currentAngle);
    servo3.write(currentAngle);
    servo4.write(currentAngle);

    delay(stepDelay); // Задержка задает скорость вращения
  } else {
    // Полная остановка, если потенциометр выкручен до упора
    servo1.write(currentAngle);
    servo2.write(currentAngle);
    servo3.write(currentAngle);
    servo4.write(currentAngle);
    delay(20);
  }
}
