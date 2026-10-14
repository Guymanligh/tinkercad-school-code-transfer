#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

const int solarPin = A0;
const float resistorValue = 1000.0; // Сопротивление резистора в Омах
const int servoPin = 9;             // Пин для оранжевого провода сервопривода

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  myServo.attach(servoPin);
  // Для сервопривода постоянного вращения (continuous): 90 — это остановка
  myServo.write(90); 
}

void loop() {
  int sensorValue = analogRead(solarPin);
  
  // Расчеты энергии
  float voltage = sensorValue * (5.0 / 1023.0);
  float power_W = (voltage * voltage) / resistorValue;
  float power_mW = power_W * 1000.0;
  
  // Обновление данных на экране
  lcd.setCursor(0, 0);
  lcd.print("Volt: ");
  lcd.print(voltage);
  lcd.print(" V   ");
  
  lcd.setCursor(0, 1);
  lcd.print("Pwr:  ");
  lcd.print(power_mW);
  lcd.print(" mW  ");

  // Вращение сервопривода в зависимости от полученной энергии
  if (voltage < 0.2) {
    // Если света почти нет, останавливаем мотор
    myServo.write(90); 
  } else {
    // Конвертируем уровень света в скорость. 
    // 90 - стоп, 180 - максимальная скорость вперед
    int speed = map(sensorValue, 0, 1023, 90, 180);
    myServo.write(speed); 
  }

  delay(500); 
}
