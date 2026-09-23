#include <Servo.h>

// Создаем объекты сервоприводов
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int potPin = A0;       // Пин потенциометра
const int centerAngle = 90;  // Центральное положение сервоприводов

void setup() {
  // Подключение сервоприводов к пинам
    servo1.attach(2);
      servo2.attach(3);
        servo3.attach(4);
          servo4.attach(5);

            // Установка в исходное (нейтральное) положение
              servo1.write(centerAngle);
                servo2.write(centerAngle);
                  servo3.write(centerAngle);
                    servo4.write(centerAngle);

                      delay(1000);
                      }

                      void loop() {
                        // Чтение значения потенциометра (от 0 до 1023)
                          int potValue = analogRead(potPin);

                            // 1. Преобразование значения в амплитуду колебаний (от 0° до 40°)
                              int amplitude = map(potValue, 0, 1023, 0, 40);

                                // 2. Преобразование значения в задержку (скорость толчков):
                                  // при минимальной силе задержка 150 мс, при максимальной — 25 мс
                                    int speedDelay = map(potValue, 0, 1023, 150, 25);

                                      // Если ручка потенциометра повернута выше "мертвой зоны"
                                        if (amplitude > 2) {
                                            // Имитация хаотических сейсмических колебаний (разные смещения для каждого привода)
                                                int shift1 = random(-amplitude, amplitude + 1);
                                                    int shift2 = random(-amplitude, amplitude + 1);
                                                        int shift3 = random(-amplitude, amplitude + 1);
                                                            int shift4 = random(-amplitude, amplitude + 1);

                                                                // Подача сигналов на сервоприводы
                                                                    servo1.write(centerAngle + shift1);
                                                                        servo2.write(centerAngle + shift2);
                                                                            servo3.write(centerAngle + shift3);
                                                                                servo4.write(centerAngle + shift4);
                                                                                  } else {
                                                                                      // Режим покоя при нулевой силе
                                                                                          servo1.write(centerAngle);
                                                                                              servo2.write(centerAngle);
                                                                                                  servo3.write(centerAngle);
                                                                                                      servo4.write(centerAngle);
                                                                                                        }

                                                                                                          delay(speedDelay);
                                                                                                          }
                                                                                                          