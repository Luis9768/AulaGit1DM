#include <Arduino.h>
#include <BluetoothSerial.h>
#define pinLed 2
 
BluetoothSerial SerialBT;

// * ESP MASTER
void setup()
{
  Serial.begin(9600);
  pinMode(pinLed,OUTPUT);

  if (!SerialBT.begin("ESP32_Master", true))
  {
    Serial.println("Erro ao iniciar a conexão Bluetooth no modo Master");
  }

  if (SerialBT.connect("ESP32_Slave"))
  {
    Serial.println("Conectado com sucesso ao ESP32_Slave");
  }
  else
  {
    Serial.println("Falha ao conectar ao ESP32_Slave");
  }
}

void loop()
{
  static bool estadoled = false;
  static bool piscaLed = false;
  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  static int tempo = 300;

  if (Serial.available())
  {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    SerialBT.println(comando);
  }

  if (SerialBT.available())
  {
    String resposta = SerialBT.readStringUntil('\n');
    resposta.trim();
    Serial.printf("Comando recebido: %s\n\r", resposta);

    if (resposta.equals("liga"))
    {
      estadoled = true;
      piscaLed = false;
    }
    else if (resposta.equals("desliga"))
    {
      estadoled = false;
      piscaLed = false;
    }
    else if (resposta.equals("pisca"))
    {
      piscaLed = true;
    }
    else
    {
      Serial.println("Comando inválido");
    }
  }
if (piscaLed)
  {
    if (tempoAtual - tempoInicial > tempo)
    {
      estadoled = !estadoled;
      tempoInicial = tempoAtual;
    }
  }

  digitalWrite(pinLed, estadoled);}
