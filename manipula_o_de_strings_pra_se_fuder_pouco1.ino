#include <Arduino.h>

char nome[20];
char nome2[20];

void setup() 
{
  Serial.begin(9600);
  strcpy(nome,"LUIS"); //atribui um string a uma cadeia de caracteres 
  Serial.println(nome);

  strcat(nome2,"Miguel");//conecta strings a um vetor
  Serial.println(nome2);

  int tamanho = strlen(nome);//informa o tamanho do dado
  Serial.println(tamanho);

  //compara 2 strings e retorna 0 se forem iguais 
if(strcmp("LUIS Miguel",nome)==0) Serial.println("Sao iguais");
else Serial.println("Sao diferentes");

if(strncmp(nome2, nome,6)==0)//compara se os primeiros caracteres sao iguais
Serial.println("os 6 primeiros sao iguais");
else Serial.println("O comeco nao eh igual");

char buffer[50];
int temperatura = 25;
sprintf(buffer, "Temperatura: %d°C",temperatura);//adiciona a um vetor um texto como um printf
Serial.println(buffer);


}

void loop()
 {
  
}


