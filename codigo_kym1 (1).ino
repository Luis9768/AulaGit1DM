#include <Arduino.h>

#include "LiquidCrystal_I2C.h"


// ********INSTANCIA OBJETOS*******


LiquidCrystal_I2C lcd(0x27,20,4);



void setup() {
  Serial.begin(9600);//baudRate
  lcd.init();
  lcd.backlight();
  lcd.print("Linda de bunita");
  lcd.setCursor(0,1);
  lcd.print("gostosa de cherosa");
  lcd.setCursor(0,2);
  lcd.print("Vc e maravilhosa");
  lcd.setCursor(0,3);
  lcd.print("♥♥♥♥♥♥♥");
}

void loop() {
  static int contagem = 0;
  Serial.println(contagem++);
  delay(300);
}

