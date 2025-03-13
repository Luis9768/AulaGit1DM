//MRS. PEREIRA LIMA
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int Resultado = 0;

void setup()
{
  lcd.init();// inicia o programa
  lcd.backlight();//liga a luz de fundo
  lcd.setCursor(0,0);
  
  
}

void loop()
{ Resultado = analogRead(A0); 
 if (Resultado == 0){
 lcd.setCursor(0,0);
 lcd.print("Botao 1 on       ");
 
 }
 
   
  if (Resultado >= 130.5 && Resultado <= 159.5 ){
 lcd.setCursor(0,0);
 lcd.print("Botao 2 on       ");
 
 }
 
 
 if (Resultado >= 296.1 && Resultado <= 361.9){
 lcd.setCursor(0,0);
 lcd.print("Botao 3 on       ");
 }
 
  if (Resultado >= 454.5 && Resultado <= 555.5){
 lcd.setCursor(0,0);
    lcd.print("Botao 4 on       ");}
   
 if(Resultado == 1023){
  lcd.setCursor(0,0);
  lcd.print("    Botao 5 on   ");   
 }
 
  
  
  
  
  
 
  
}