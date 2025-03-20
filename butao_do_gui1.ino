// C++ code
//Faça um programa que acenda e apague 3 leds,
//de forma progressiva, enquanto um botão estiver pressionado.
#define pinBotao 8
int pinLeds[3]= {10,11,12};
bool estadoBotao = 0;
bool estadoLed = 0;
  
  
void setup()
{
  Serial.begin(9600);
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinLeds[0], OUTPUT);
  pinMode(pinLeds[1], OUTPUT);
  pinMode(pinLeds[2], OUTPUT);
}

void loop()
{
  for (int x = 0; x <3; x++){
  digitalWrite(pinLeds[x], estadoBotao);
 
  }
  static bool estadoAnteriorBotao = 0;
  estadoBotao = digitalRead(pinBotao);
  if(estadoBotao == 1 && estadoAnteriorBotao == 0){
  	estadoBotao == false;
  }
  if(estadoBotao ==1)Serial.println("Botao ligado");
  estadoAnteriorBotao = estadoBotao;
  digitalWrite(pinLeds[3],estadoBotao);
   
   if (estadoBotao == 0)Serial.println("Botao off");
  estadoAnteriorBotao =estadoBotao;
 digitalWrite(pinLeds[3],LOW);
  delay(3000);
  
  
  
  
}