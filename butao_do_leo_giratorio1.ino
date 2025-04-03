#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define S1 19
#define S2 23



void setup()
{
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    lcd.init();
    lcd.backlight();
}

void loop()
{
    static int estadoAnterior = 0;

    
    int estadoAtual = (digitalRead(S1) << 1 | digitalRead(S2));


    if (estadoAtual != estadoAnterior)
  {
    lcd.setCursor(0, 0);
    lcd.print("Estado: ");
    lcd.print(estadoAtual);
    lcd.print("   "); 

    // Verifica sentido horário ( 3 2 0 1 )
    if ((estadoAnterior == 3 && estadoAtual == 2) ||
        (estadoAnterior == 2 && estadoAtual == 0) ||
        (estadoAnterior == 0 && estadoAtual == 1) ||
        (estadoAnterior == 1 && estadoAtual == 3))
    {
      lcd.setCursor(0, 1);
      lcd.print("Sentido HORARIO     ");
    }

    // Verifica sentido anti-horário ( 3 1 0 2 )
    else if ((estadoAnterior == 3 && estadoAtual == 1) ||
             (estadoAnterior == 1 && estadoAtual == 0) ||
             (estadoAnterior == 0 && estadoAtual == 2) ||
             (estadoAnterior == 2 && estadoAtual == 3))
    {
      lcd.setCursor(0, 1);
      lcd.print("Sentido ANTI-HORARIO");
    }

    estadoAnterior = estadoAtual; 
  }
}
