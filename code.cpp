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


  // 0 = стоп
  // 1023 = максимальная скорость вправо
  int speed = map(potValue, 0, 1023, 90, 180);


  servo1.write(speed);
  servo2.write(speed);
  servo3.write(speed);
  servo4.write(speed);


  delay(10);
}

