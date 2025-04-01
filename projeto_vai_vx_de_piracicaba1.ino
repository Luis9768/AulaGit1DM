#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Configura o LCD para 20 colunas e 4 linhas
#define PinBotao 5                  // Define o pino do botão
#define pinLed 19                   // Define o pino do LED
unsigned long Titulo = 0;           // Usando 'unsigned long' para o índice

// Títulos do XV de Piracicaba usando const char* (sem String)
const char *titulos[] = {
    "TODOS VENEREM O  ENORME   E  IMPORTANTE PARA A SOCIEDADE DE SP ",
    "XV DE PIRACICABA",
    "Campeao Paulista    1919",
    "Campeao Paulista    1923",
    "Campeao Paulista    1944",
    "Campeao Paulista    1957",
    "Campeao Paulista    1981",
    "Campeao Paulista    2011",
    "Campeao Brasileiro  da Serie D de 2011",
    "Campeao Copa        Paulista de 2012",
    "XV DE PIRACICABA > TIMES PAULISTAS E TIMES EUROPEUS"};

void setup()
{
  pinMode(PinBotao, INPUT_PULLUP); // Configura o pino do botão com resistência pull-up
  pinMode(pinLed, OUTPUT);         // Configura o pino do LED como saída
  lcd.init();                      // Inicializa o LCD
  lcd.backlight();                 // Liga o backlight do LCD
  lcd.print(titulos[Titulo]);      // Exibe o primeiro título
  delay(2000);                     // Aguarda 2 segundos para o primeiro título ser visualizado
  lcd.clear();                     // Limpa o display
  Serial.begin(9600);
}

void loop()
{
  bool EstadoBotao = 1;
  static bool estadoAnteriorBotao = 0;

  EstadoBotao = digitalRead(5); // Lê o estado do botão
  // Verifica se o botão foi pressionado (com debounce)
  if (EstadoBotao == 1 && estadoAnteriorBotao == 0)
  {
    Titulo++; // Avança para o próximo título

    if (Titulo >= 10)
    { // Quando todos os títulos forem mostrados, reinicia
      Titulo = 0;
    }

    lcd.clear();                // Limpa o LCD
    lcd.print(titulos[Titulo]); // Exibe o próximo título
    delay(300);                 // Aguarda 300ms para debounce (evitar múltiplos cliques rápidos)
  }
  else
  {
    digitalWrite(pinLed, LOW); // Apaga o LED quando o botão não está pressionado
  }
    digitalWrite(pinLed, HIGH); // Acende o LED

  estadoAnteriorBotao = EstadoBotao; // Atualiza o estado anterior do botão
}
