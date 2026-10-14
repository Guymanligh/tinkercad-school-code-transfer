#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Инициализация дисплея. 0x27 — стандартный адрес для I2C в Tinkercad (иногда бывает 0x20 или 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int solarPin = A0; // Пин, к которому подключена солнечная панель

// ВАЖНО: Укажите здесь точное сопротивление вашего резистора в Омах!
// В Tinkercad по умолчанию резистор имеет сопротивление 1 кОм (1000 Ом).
const float resistorValue = 1000.0; 

void setup() {
  Serial.begin(9600);
  
  lcd.init();       // Инициализация дисплея
  lcd.backlight();  // Включение подсветки
  lcd.clear();
}

void loop() {
  // Читаем сырое значение с аналогового пина (от 0 до 1023)
  int sensorValue = analogRead(solarPin);
  
  // Переводим это значение в напряжение (Вольты). 
  // Максимальное напряжение Arduino Uno = 5.0V
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Рассчитываем мощность в Ваттах (P = V^2 / R)
  float power_W = (voltage * voltage) / resistorValue;
  
  // Переводим в милливатты для более удобного отображения (1 Вт = 1000 мВт)
  float power_mW = power_W * 1000.0;
  
  // --- Вывод данных на LCD дисплей ---
  
  // Первая строка: Напряжение
  lcd.setCursor(0, 0);
  lcd.print("Volt: ");
  lcd.print(voltage);
  lcd.print(" V   "); // Пробелы в конце стирают старые символы
  
  // Вторая строка: Мощность (Энергия)
  lcd.setCursor(0, 1);
  lcd.print("Pwr:  ");
  lcd.print(power_mW);
  lcd.print(" mW  ");

  // --- Вывод в монитор порта (для отладки) ---
  Serial.print("Напряжение: ");
  Serial.print(voltage);
  Serial.print(" В | Мощность: ");
  Serial.print(power_mW);
  Serial.println(" мВт");

  // Пауза перед следующим измерением
  delay(500); 
}
