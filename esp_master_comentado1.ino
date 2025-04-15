#include <Arduino.h>
#include <BluetoothSerial.h>
#define pinLed 2
 
BluetoothSerial SerialBT;

// * ESP MASTER
void setup()
{
  Serial.begin(9600);//inicia a serial de sempre
  pinMode(pinLed,OUTPUT);// define o led do esp

  if (!SerialBT.begin("ESPGullit", true))//inicia o meu bluetooth com o nome ESPGuliit
  {
    Serial.println("Erro ao iniciar a conexão Bluetooth no modo Master");// Se não conectar aparece isso
  }

  if (SerialBT.connect("ESPJuarez"))//esse é o nome do ESP que eu tenho que conectar no caso do parceiro com o outro ESP
  {
    Serial.println("Conectado com sucesso ao ESPJuarez");//Se conectar com sucesso aparece isso
  }
  else
  {
    Serial.println("Falha ao conectar ao ESPJuarez");// se não conectar aparece isso
  }
}

void loop()
{
  static bool estadoled = false; //variavel para controlar o led
  static bool piscaLed = false;// variavel para fazer ele piscar
  unsigned long tempoAtual = millis();// tiago nao gosta de delay
  static unsigned long tempoInicial = 0;// tempo inicial
  static int tempo = 300;// tempo com milisegundos

  if (Serial.available())
  {
    String comando = Serial.readStringUntil('\n');//string comando vai ler o \n basicamento o enter
    comando.trim();// pega a mensagem e tira os espaços do começo e do fim "ex:   luis  " fica "ex : luis"
    SerialBT.println(comando);//Vai aparecer as açoes do comando na serial
  }

  if (SerialBT.available())//leirura
  {
    String resposta = SerialBT.readStringUntil('\n');// leitura do \n para executar os comandos
    resposta.trim();// pega a mensagem e tira os espaços do começo e do fim "ex:   luis  " fica "ex : luis"
    Serial.printf("Comando recebido: %s\n\r", resposta);//vai aparecer na serial o comando recebdio e a resposta

    if (resposta.equals("liga"))//faz o led ligar
    {
      estadoled = true;//liga o led
      piscaLed = false;//falso pro pisca nao interferir
    }
    else if (resposta.equals("desliga"))
    {
      estadoled = false;//falso pro estado led que faz o led ligar não interferir
      piscaLed = false;//falso pro pisca não ligar nem interferir
    }
    else if (resposta.equals("pisca"))
    {
      piscaLed = true;//liga o pisca
    }
    else
    {
      Serial.println("Comando inválido");//digita o bagulho certo porra
    }
  }
if (piscaLed)// se o pisca...
  {
    if (tempoAtual - tempoInicial > tempo)// controle das variaveis de tempo
    {
      estadoled = !estadoled;//comparação dos controles dos leds
      tempoInicial = tempoAtual;// reset do tempo
    }
  }

  digitalWrite(pinLed, estadoled);
  }
