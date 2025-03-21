/*
Faça um programa que acenda e apague 3 leds,
de forma progressiva, enquanto um botão estiver pressionado.
*/

#define botao 7
int led[5] = {13, 12, 11};
int i = 0;
bool ligado = 0, botaoPressionado = false;
  
void setup(){
  pinMode(botao, INPUT_PULLUP);
  for (int i = 0; i < 3; i++){
    pinMode(led[i], OUTPUT);//FOR DENTRO DO SETUP E PINMODE DENTRO
    //DO FOR FAZER ELE LIGAR SEQUENCIALMENTE
  }
}

void loop(){
  bool estadoBotao = digitalRead(botao);
  
  if (estadoBotao && !botaoPressionado) {
    botaoPressionado = true;
    ligado = false;
  }
  
  if (!estadoBotao) {
    botaoPressionado = false;
  	ligado = true;
  }
  
  for (int i = 0; i < 3; i++) {
      digitalWrite(led[i], ligado);
      delay(250);
  }
}