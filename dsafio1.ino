// MR. PEREIRA LIMA



#include <LiquidCrystal_I2C.h>
#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741
#define pinLedA 11
#define pinLedB 10


LiquidCrystal_I2C lcd(0x27,20,4);





void setup()
{

  
lcd.init();
pinMode(pinLedA,OUTPUT);
pinMode(pinLedB,OUTPUT) ; 
lcd.backlight();
lcd.setCursor(2,0);
lcd.print("LED A OFF");
lcd.setCursor(2,1);
lcd.print("LED B OFF");

  
  
  
  
  
  
 }

void loop()
{
 //variaveis locais 
static bool posicao = 0;  
static bool estadoLedA = 0;
static bool estadoLedB = 0;
  
  
//TRATAMENTO DOS BOTOES  
int valorLeitura = analogRead(A0);
static int valorAnteriorLeitura = 1023;
  
  
//Botao 1 pressionado  
if (valorAnteriorLeitura == 1023 && valorLeitura == valorBotao1)
  {
    posicao = 0;
  }
  
  
 //Botao 2 pressionado
else if (valorAnteriorLeitura == 1023 &&
         valorLeitura >= valorBotao1 * 0.9&&
         valorLeitura <= valorBotao1 * 1.1);
  
    { 
    posicao = 1;
    }
  
  //BOTAO 3 PRESSIONADO
  
 if (valorAnteriorLeitura == 1023 &&
     valorLeitura >= valorBotao2 * 0.9&&
     valorLeitura <= valorBotao2 * 1.1)
   
 {
 posicao = 2;
 }
   
   
  {
  if(!posicao) estadoLedA = !estadoLedA;
  else estadoLedB = !estadoLedB;
  }
  
  
  valorAnteriorLeitura = valorLeitura;
  //FIM TRATAMENTO DOS BOTOES  
    
    
    
    
    
   //******TRATAMENTO DO DISPLAY******** 
    
    if(posicao == 0)
  {
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(0,1);
    lcd.print(" ");
  }
  
  else 
  { 
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.setCursor(0,0);
    lcd.print(" ");
  
  }
  
  
  
  //******MOSTRAR ESTADO DOS LEDS******
  
  if(estadoLedA)
  {
  lcd.setCursor(8,0);
  lcd.print("OFF");
  }
  
  else {
  lcd.setCursor(8,0);
  lcd.print("OFF");
  }
  
  if(estadoLedB)
  {
  lcd.setCursor(8,1);
  lcd.print("OFF");
  }
  
  else {
  lcd.setCursor(8,1);
  lcd.print("OFF");
  }
  
  //*****TRTAMENTO LED********

digitalWrite(pinLedA,estadoLedA);
digitalWrite(pinLedB,estadoLedB);













}