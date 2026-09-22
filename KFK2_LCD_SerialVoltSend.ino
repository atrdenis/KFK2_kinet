/*this is a sketch for working with KFK2 photocolorimeter
it displays LCD1602 voltage, transmission and absorption
sends voltage values to Serial for further processing*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int inputPin = A0;
const int numReadings = 5;
const int delayTime = 100;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Указываем адрес и размеры экрана

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  lcd.init();
  lcd.backlight();  // Включаем подсветку экрана
  lcd.setCursor(0, 0);  // Устанавливаем курсор в начало первой строки
  lcd.print("Voltage:      mV");
  lcd.setCursor(0, 1);  // Устанавливаем курсор в начало второй строки
  lcd.print("T:      A:      ");
}

void loop() {
  float voltage = 0.0;
  
  for (int i = 0; i < numReadings; i++) {
    int sensorValue = analogRead(inputPin);
    float currentVoltage = sensorValue * (1.1 / 1023.0);
    voltage += currentVoltage;
    delay(delayTime);
  }
  
  voltage /= numReadings;
  float transmittance = voltage/0.1*100;  // Пропускание равно напряжению, деленному на 1.0 (1 V)
  float absorbance = -log10(transmittance/100);
  

  Serial.println(voltage, 4);
  
  lcd.setCursor(9, 0);  // Устанавливаем курсор в первую строку, восьмой символ
  lcd.print("     mV");  // Очищаем прежние данные на экране
  lcd.setCursor(9, 0);
  lcd.print(voltage*1000, 0);  // Выводим значение напряжения на экран
  lcd.setCursor(3, 1);  // Устанавливаем курсор во вторую строку, четырнадцатый символ
  lcd.print("     ");  // Очищаем прежние данные на экране
  lcd.setCursor(3, 1);
  lcd.print(transmittance, 0);  // Выводим значение пропускания на экран
  lcd.setCursor(11, 1);  // Устанавливаем курсор в третью строку, четырнадцатый символ
  lcd.print("     ");  // Очищаем прежние данные на экране
  lcd.setCursor(11, 1);
  lcd.print(absorbance, 3);  // Выводим значение поглощения на экран
  
}
