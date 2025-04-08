#include <Arduino.h>

struct Pessoa
{
  char nome[20];
  int idade;
  float altura;
  bool calvice;  
};

Pessoa aluno;
Pessoa professor;

void setup() 
{
  Serial.begin(9600);

  strcpy(aluno.nome, "Luis");
  aluno.idade = 18;
  aluno.altura = 1.70;
  aluno.calvice = false;

  strcpy(professor.nome,"Odirlei");
  professor.idade = 47;
  professor.altura= 1.80;
  professor.calvice= true;

  Serial.printf("Meu nome é : %s\n\r", aluno.nome);
  Serial.printf("E tenho %d anos\n\r", aluno.idade);
  Serial.printf("tenho %.2f metros de altura\n\r", aluno.altura);
  Serial.printf("E %s calvo\n\r",aluno.calvice? "sou":"nao sou");

  Serial.printf("Meu nome é : %s\n\r", professor.nome);
  Serial.printf("E tenho %d anos\n\r", professor.idade);
  Serial.printf("tenho %.2f metros de altura\n\r", professor.altura);
  Serial.printf("E %s calvo",professor.calvice? "sou":"nao sou");

}

void loop() 
{
  
}