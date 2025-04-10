#include <Arduino.h>
#include"BluetoothSerial.h"

#define pinLedA 2
#define pinLedB 18
#define pinLedC 19
#define pinLedD 23




BluetoothSerial SerialBT;

String palavra = "";

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPLuis");
  SerialBT.println("Digite algo na serial:");
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);
  pinMode(pinLedD, OUTPUT);
  
}

void loop()

{
  
  while (SerialBT.available())
  {
    char caracter = SerialBT.read();

    if (caracter == '\n')
    {
      SerialBT.println(palavra);
      if (palavra.equals("liga ledA"))
      {
        digitalWrite(pinLedA, HIGH);
      }
      else if (palavra.equals("Desliga LedA"))
      {
        digitalWrite(pinLedA, LOW);
      }

if (palavra.equals("liga ledB"))
      {
        digitalWrite(pinLedB, HIGH);
      }
      else if (palavra.equals("Desliga LedB"))
      {
        digitalWrite(pinLedC, LOW);
      }
      if (palavra.equals("liga ledC"))
      {
        digitalWrite(pinLedC, HIGH);
      }
      else if (palavra.equals("Desliga LedC"))
      {
        digitalWrite(pinLedC, LOW);
      }
      if (palavra.equals("liga ledD"))
      {
        digitalWrite(pinLedD, HIGH);
      }
      else if (palavra.equals("Desliga LedD"))
      {
        digitalWrite(pinLedD, LOW);
      }

      else
      {
        SerialBT.println("comando nao reconhecido");
      }
      palavra = "";
    }
    else if (caracter != '\r')
    {
      palavra += caracter;
    }

    /* if (caracter == 'L')
     {
       digitalWrite(pinLed, HIGH);
       Serial.println("Led ligado");
     }

     else if (caracter == 'D')
     {
       digitalWrite(pinLed, LOW);
       Serial.println("Led desligado");
     }
     else
     {
       Serial.println("Digite apenas L ou D");
       Serial.printf("Voce digitou %c\n\r", caracter);
     }
   }*/
  }
}