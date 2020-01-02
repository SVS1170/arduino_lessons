#include <LiquidCrystalRus_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystalRus_I2C lcd(0x3f, 20, 4);

void setup()
{
  lcd.begin(); //инициализация
  lcd.backlight(); //подсветка (с некоторыми экранами не обязательно)
  lcd.print(L"Привет, мир!"); //выводим русский текст
  lcd.setCursor(0, 1);
  lcd.print(L"Привет, мир!"); //выводим русский текст
  lcd.setCursor(0, 2);
  lcd.print(L"Привет, мир!"); //выводим русский текст
  lcd.setCursor(0, 3);
  lcd.print(L"Привет, мир!"); //выводим русский текст
  delay(1000);
  lcd.backlight(); //подсветка (с некоторыми экранами не обязательно)
  delay(1000);
}

void loop()
{
  //тут пусто
}
