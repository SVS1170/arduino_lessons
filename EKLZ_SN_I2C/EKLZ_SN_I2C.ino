#include <Wire.h>
#include <LiquidCrystalRus_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystalRus_I2C lcd(0x3f, 20, 4);

byte zapros[]={2, 2, 7, 1, 4};
byte buf[27];

void setup()
{
Serial.begin(9600);
Wire.begin();
lcd.begin(); //инициализация
lcd.backlight(); //подсветка (с некоторыми экранами не обязательно)
  

}

void loop()
{

int i=0;
buf[17]= 0;
buf[18]= 0;
buf[19]= 0;
buf[20]= 0;
buf[21]= 0;


Wire.beginTransmission(0x02);
Wire.write(zapros, 5);
Wire.endTransmission();
Wire.requestFrom(0x02,22);

while (Wire.available()){
buf[i]=Wire.read();
i++;
}


//Serial.print(buf[17], HEX);
//Serial.print(buf[18], HEX);
//Serial.print(buf[19], HEX);
//Serial.print(buf[20], HEX);
//Serial.print(buf[21], HEX);
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(L"ПРОВЕРКА ЗКЛЗ"); //выводим русский текст
  lcd.setCursor(0, 1);
  lcd.print(L"АДРЕС : 0х02"); //выводим русский текст
  lcd.setCursor(0, 2);
  lcd.print(L"ИНТЕРФЕЙС: "); //выводим русский текст
  lcd.print("I2C");
  lcd.setCursor(0, 3);
  lcd.print(L"ЗН    : "); //выводим русский текст
  lcd.setCursor(8, 3);
  lcd.print("            ");
  lcd.setCursor(8, 3);
  lcd.print(buf[17], HEX);
  lcd.print(buf[18], HEX);
  lcd.print(buf[19], HEX);
  lcd.print(buf[20], HEX);
  lcd.print(buf[21], HEX);
  delay(1000);
  
} 
