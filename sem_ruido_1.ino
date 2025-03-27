#include <Arduino.h>

#define pinButton 5

void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  bool estadoAtualBotao = digitalRead(pinButton);
  static bool estadoAnteriorBotao = 1;
  static bool ultimaAcao = 1;
  
  static unsigned long tempoUltimaAlteracao = 0;
  unsigned long tempoAtual = millis();
  const unsigned long tempoFiltro = 50;

  static int contagem = 0;
 
  //! INICIA O TRATAMENTO DE RUIDO DO BOTÃO

  // * Detecta mudança no estado do botão
  if(estadoAtualBotao != estadoAnteriorBotao)
  {
    tempoUltimaAlteracao = tempoAtual; // * Atualiza o tempo da última mudança
  }

  // * Verifica se o novo estado se manteve estável por tempo suficiente
  if ((tempoAtual - tempoUltimaAlteracao) > tempoFiltro)
  {
    // * Verifica se ainda não processamos essa nova ação
    if(estadoAtualBotao != ultimaAcao) 
    {
      ultimaAcao = estadoAtualBotao;  // * Atualiza o estado já processado para evitar ações repetidas enquanto o botão estiver no mesmo estado
      
      // * Se o botão foi pressionado (nível lógico LOW)
      if(!estadoAtualBotao)
      {
        contagem++;
        Serial.println(contagem);
      }
      // * Se o botão foi solto (nível lógico HIGH), nenhuma ação por enquanto
    }
  }
  // * Atualiza o estado anterior para a próxima iteração
  estadoAnteriorBotao = estadoAtualBotao;
 //! FINAL DO TRATAMENTO DO BOTÃO
}