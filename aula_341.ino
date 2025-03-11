#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
bool estadoLed = 1;
unsigned long TempoInicial = 0;
#define pinBotao 8 
#define pinLad 13


void setup() {
pinMode(pinBotao,OUTPUT);// saida de energia
pinMode(pinBotao, INPUT);//saida de energia
pinMode(pinLad,OUTPUT);//saida energia para o led
lcd.init();//inicia o comando
lcd.backlight();//acende a paradinha verde
lcd.setCursor(0,0);//posicao das palavras na tela verde


}

void loop() {
  static bool estadoAnteriorBotao = 1;//Aqui fudeu que começa comparação e recebimento tendi porra nenhuma
  bool estadoAtualBotao = digitalRead(pinBotao);//variavel do estado do botão
  if (estadoAtualBotao && !estadoAnteriorBotao){//comparação para saber o estado atual e anterior do botão
  lcd.clear();
    estadoLed = !estadoLed;// variavel para saber o estado do led usar nos ifs
    if (estadoLed == 0) lcd.print("Led desligado");
    if (estadoLed == 1) lcd.print("Led ligado");// foi criado 3 ifs dentro das chaves para fazer o comando liga e desliga e o estado led clear serve para apagar a escrita anterior
  }
    estadoAnteriorBotao = estadoAtualBotao;
  digitalWrite(pinLad,estadoLed);

}
