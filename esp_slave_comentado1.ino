#include <Arduino.h>
#include <BluetoothSerial.h>// inclui o blutu pra usar meu rei

BluetoothSerial SerialBT;//cria o objeto aqui 

void setup()
{
  Serial.begin(9600);//inicia a serial

  if (!SerialBT.begin("SlaveLUIS", false))//incia o blutu, e da um nome pra ele, blutu é tipo bool ou conecta ou não conecta
  {
    Serial.println("Erro ao inciar bluetooth como Slave");// se o slave não conectar aparece isso
  }
}

void loop()
{
  if (Serial.available())//leitura pra ver se o blutu ta disponivel
  {
    String enviarComando = Serial.readStringUntil('\n');// leitura do enter para os comandos irem depois de vc escrever
    enviarComando.trim();//tira os espaços do começo e do final
    SerialBT.println(enviarComando);// manda os comandos para o amigo com o ESP
  }
  if (SerialBT.available())//leitura pra ver se o blutu ta disponivel
    {
    String Recebercomando = SerialBT.readStringUntil('\n');
    Recebercomando.trim();
    Serial.printf("Comando Recebido: %s\n\r", Recebercomando);// aparece na serial que eu recebi o comando

    if (Recebercomando.equals("liga"))//liga o led
    {
    }
    else
    {
      Serial.println("Comando não Reconhecido");//digita essa porra direito pq ta errado
    }
  }
}