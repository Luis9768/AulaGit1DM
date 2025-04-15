#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);

  if (!SerialBT.begin("SlaveLUIS", false))
  {
    Serial.println("Erro ao inciar bluetooth como Slave");
  }
}

void loop()
{
  if (Serial.available())
  {
    String enviarComando = Serial.readStringUntil('\n');
    enviarComando.trim();
    SerialBT.println(enviarComando);
  }
  if (SerialBT.available())
  {
    String Recebercomando = SerialBT.readStringUntil('\n');
    Recebercomando.trim();
    Serial.printf("Comando Recebido: %s\n\r", Recebercomando);

    if (Recebercomando.equals("liga"))
    {
    }
    else
    {
      Serial.println("Comando não Reconhecido");
    }
  }
}
