#include <Arduino.h>

struct Cores
{
  char nome[20];
  int R;
  int G;
  int B;
};

Cores Azul;
Cores Laranja;
Cores Marrom;




void setup() 
{
Serial.begin(9600);

strcpy(Azul.nome,"Cor Azul");
Azul.R = 117;
Azul.G = 183;
Azul.B = 244;

strcpy(Laranja.nome,"Cor Laranja");
Laranja.R = 244;
Laranja.G = 75;
Laranja.B = 29;

strcpy(Marrom.nome,"Cor Marrom");
Marrom.R = 146;
Marrom.G = 81;
Marrom.B = 39;
  

  Serial.printf("  %s\n\r", Azul.nome);
  Serial.printf("R = %d\n\r", Azul.R);
  Serial.printf("G = %d\n\r", Azul.G);
  Serial.printf("B = %d\n\r", Azul.B);

  Serial.printf("  %s\n\r", Laranja.nome);
  Serial.printf("R = %d\n\r", Laranja.R);
  Serial.printf("G = %d\n\r", Laranja.G);
  Serial.printf("B = %d\n\r", Laranja.B);

Serial.printf("  %s\n\r", Marrom.nome);
  Serial.printf("R = %d\n\r", Marrom.R);
  Serial.printf("G = %d\n\r", Marrom.G);
  Serial.printf("B = %d\n\r", Marrom.B);

}

void loop() 
{
  
}

