#include <Arduino.h>
#define canalA 23
#define canalB 19

const int8_t tabelaTransicao[4][4] = {
/*+1 horario
   0 parado
 - 1 antihorario
 */


     /*0  1  2  3*/
/*0*/{ 0, 1, -1,0},
/*1*/{-1, 0, 0, 1},
/*2*/{ 1, 0, 0,-1},
/*3*/{ 0, -1,1, 0}
};


void setup()
{
  pinMode(canalA, INPUT);
  pinMode(canalB, INPUT);
  Serial.begin(9600);
}



void loop()
{
bool leituraCanalA = digitalRead(canalA);
bool leituraCanalB = digitalRead(canalB);
int estadoAtualEncoder = ((leituraCanalA<<1) | leituraCanalB);
static int estadoAnteriorEncoder = 3;

static int posicao = 0;
posicao = posicao + tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];
Serial.println(posicao);





estadoAnteriorEncoder = estadoAtualEncoder;
}