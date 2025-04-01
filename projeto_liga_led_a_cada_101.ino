#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinLed 19
#define pinBotao 5

int contagem = 0;
bool ledLigado = false; // Variável para controlar o estado do LED
unsigned long tempoLedLigado = 0; // Variável para armazenar o tempo em que o LED foi ligado

void setup() {
  pinMode(pinBotao, INPUT_PULLUP); // Use INPUT_PULLUP para simplificar o circuito
  pinMode(pinLed, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Contagem: 0"); // Inicializa o LCD com a contagem inicial
}

void loop() {
  static bool estadoAnteriorBotao = HIGH; // Começa com HIGH devido ao INPUT_PULLUP
  bool estadoAtualBotao = digitalRead(pinBotao);

  if (estadoAtualBotao == LOW && estadoAnteriorBotao == HIGH) { // Detecta a transição de HIGH para LOW (pressionamento)
    contagem++;
    lcd.clear();
    lcd.print("Contagem: ");
    lcd.print(contagem);

    if (contagem % 10 == 0) { // Verifica se a contagem é múltipla de 10
      digitalWrite(pinLed, HIGH); // Liga o LED
      ledLigado = true;
      tempoLedLigado = millis(); // Armazena o tempo em que o LED foi ligado
    }
    delay(50); // Debounce do botão
  }

  if (ledLigado && millis() - tempoLedLigado >= 1000) { // Verifica se o LED está ligado e se passou 1 segundo
    digitalWrite(pinLed, LOW); // Desliga o LED
    ledLigado = false;
  }

  estadoAnteriorBotao = estadoAtualBotao;
}