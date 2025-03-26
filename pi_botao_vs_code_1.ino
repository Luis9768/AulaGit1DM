#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
bool estadoLedA = 1;
bool estadoLedB = 1;
#define pinBotaoA 11
#define pinBotaoB 3
#define pinLedA 13
#define pinLedB 5



void setup(){
  pinMode(pinBotaoA,INPUT);
  pinMode(pinBotaoB,INPUT);
  pinMode(pinLedA,OUTPUT);
  pinMode(pinLedB,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
    
}

void loop(){
static bool estadoanteriordoBotaoA = 1;
static bool estadoanteriordoBotaoB = 0;  
bool estadoatualBotaoA = digitalRead(pinBotaoA);
bool estadoatualBotaoB = digitalRead(pinBotaoB);
if (estadoatualBotaoA && !estadoanteriordoBotaoA){
  lcd.clear();
  estadoLedA = !estadoLedA;
  if (estadoatualBotaoB && !estadoanteriordoBotaoB){
  lcd.clear();
  estadoLedB = !estadoLedB;
if (estadoLedA == 0) lcd.print("Led A OFF");
if (estadoLedB == 1) lcd.print("Led B ON ");
  estadoanteriordoBotaoA = estadoatualBotaoA;
  digitalWrite(pinLedA,estadoLedA);
  
  }}
  }
