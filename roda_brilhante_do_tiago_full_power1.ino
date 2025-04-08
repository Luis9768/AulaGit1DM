#include <Arduino.h>
#include <Bounce2.h>

// Definições de pinos
#define PINO_ENCODER_A 5     // Canal A (CLK) do encoder rotativo
#define PINO_ENCODER_B 18    // Canal B (DT) do encoder rotativo
#define PINO_BOTAO 4         // Botão embutido no encoder

// Objeto da biblioteca Bounce para tratar debounce do botão
Bounce botaoEncoder = Bounce();

// Protótipo da função que detecta rotação do encoder
int detectarRotacaoEncoder(void);

// Tabela de transição de estados do encoder rotativo
// Cada entrada representa a direção do movimento com base no estado anterior e atual
const int8_t tabelaTransicao[4][4] = {
  {0, 1, -1, 0},  // de estado 0
  {-1, 0, 0, 1},  // de estado 1
  {1, 0, 0, -1},  // de estado 2
  {0, -1, 1, 0}   // de estado 3
};

void setup() {
  pinMode(PINO_ENCODER_A, INPUT);
  pinMode(PINO_ENCODER_B, INPUT);
  botaoEncoder.attach(PINO_BOTAO, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Detecta a direção da rotação: -1 anti-horário, +1 horário, 0 parado
  int direcaoRotacao = detectarRotacaoEncoder();

  // Atualiza o estado do botão com debounce
  botaoEncoder.update();

  // Variável para alternar entre modos: menu de seleção ou ajuste
  static bool modoMenuAtivo = true; // true = menu, false = ajuste

  // Variável que indica a posição atual do cursor no menu (0 a 3)
  static int indiceItemMenu = 0;

  // Intensidades individuais dos LEDs (0 a 100)
  static int intensidadeLed[4] = {0, 0, 0, 0};

  // Alterna entre o modo de menu e o modo de ajuste ao pressionar o botão
  if (botaoEncoder.fell()) {
    modoMenuAtivo = !modoMenuAtivo;
  }

  // --------------------------
  // MODO MENU ATIVO (Seleciona o LED)
  // --------------------------
  if (modoMenuAtivo) {
    if (direcaoRotacao != 0) {
      indiceItemMenu += direcaoRotacao;

      // Faz o índice circular entre 0 e 3
      if (indiceItemMenu > 3) indiceItemMenu = 0;
      else if (indiceItemMenu < 0) indiceItemMenu = 3;

      Serial.print("Item selecionado: LED ");
      Serial.println(indiceItemMenu + 1);
    }
  }

  // --------------------------
  // MODO AJUSTE ATIVO (Modifica intensidade do LED selecionado)
  // --------------------------
  else if (direcaoRotacao != 0) {
    intensidadeLed[indiceItemMenu] += direcaoRotacao * 10;

    // Limita a intensidade entre 0 e 100
    if (intensidadeLed[indiceItemMenu] > 100) intensidadeLed[indiceItemMenu] = 100;
    else if (intensidadeLed[indiceItemMenu] < 0) intensidadeLed[indiceItemMenu] = 0;

    Serial.print("Intensidade do LED ");
    Serial.print(indiceItemMenu + 1);
    Serial.print(": ");
    Serial.println(intensidadeLed[indiceItemMenu]);
  }

  // Aqui você pode futuramente aplicar essas intensidades com analogWrite() ou PWM.
}


int detectarRotacaoEncoder() {
  // Lê o estado atual dos canais do encoder
  bool estadoA = digitalRead(PINO_ENCODER_A);
  bool estadoB = digitalRead(PINO_ENCODER_B);

  // Junta os dois bits (A e B) em uma única variável (valores de 0 a 3)
  int estadoAtual = (estadoA << 1) | estadoB;

  static int estadoAnterior = 3;  // 3 = repouso
  static int acumulador = 0;      // Acumula os passos do movimento
  int resultado = 0;              // Retorna 1, -1 ou 0

  // Detecta mudança de estado (movimento)
  if (estadoAtual != estadoAnterior) {
    // Atualiza o acumulador com base na tabela de transição
    acumulador += tabelaTransicao[estadoAnterior][estadoAtual];

    // Se o estado atual for 3 (repouso), verifica se houve rotação completa
    if (estadoAtual == 3) {
      if (acumulador == 4) {
        resultado = 1; // sentido horário
      } else if (acumulador == -4) {
        resultado = -1; // sentido anti-horário
      }

      acumulador = 0; // zera para próxima leitura
    }

    // Atualiza o estado anterior
    estadoAnterior = estadoAtual;
  }

  return resultado;
}

codigo.jpg
Imagem

GitHub - thomasfredericks/Bounce2: Debouncing library for Arduino and Wiring
https://github.com/thomasfredericks/Bounce2
1 comentário para a turma

PABLO HENRIQUE PEDROZA DA SILVAOntem
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
 
 LiquidCrystal_I2C lcd(0x27,20,4);
 
 byte quadradoVazio[] = {
   B11111,
   B10001,
   B10001,
   B10001,
   B10001,
   B10001,
   B10001,
   B11111
 };
 
 #define canalA 18 //clk
 #define canalB 23 //dt
 #define botao 15 //botao 
 #define led1 2
 #define led2 4
 #define led3 12
 #define led4 14
 
 void menuPrincipal (void);
 void menuLed1 (void);
 void menuLed2 (void);  
 void menuLed3 (void);
 void menuLed4 (void);
 void girandoH (void);
 void girandoAH (void);
 
 void setup()
 {
   estadoAnteriorCLK = digitalRead(canalA);
 }
 
 void loop()
 {
 
   //variaveis e booleanas
 
 //variaveis
 int contadorMenu = 0;
 int contadorBotao = 0
 int estadoAtualCLK;
 int estadoAnteriorCLK;
 int estadoA;
 int ultimoestadoA;
 int contadorMenuBotao = 0;
 int brilhoLed1 = 0;
 int brilhoLed2 = 0;
 int brilhoLed3 = 0;
 int brilhoLed4 = 0;

 //booleanas
 bool menu = true;
 bool girandoH = false;
 bool girandoAH = false;
 bool modoAlteracaoLed1 = false;
 bool modoAlteracaoLed2 = false;
 bool modoAlteracaoLed3 = false;
 bool modoAlteracaoLed4 = false;
 bool botaoApertado = false;
 
   //fim das variaveis e booleanas

   //controle botao
   static bool estadoAnteriorBotao = 0;
   bool estadoAtualBotao = digitalRead(botao);
     
   if (estadoAtualBotao == 1 && !estadoAnteriorBotao)
   {
   contadorBotao++;
   }
  delay(50);
  estadoAnteriorBotao = estadoAtualBotao;
   //fim controle botao
 
   //controle encoder
   estadoAtualCLK = digitalRead(canalA);
 
   if (estadoAtualCLK != estadoAnteriorCLK)
   {
     estadoA = digitalRead(canalB);
     if (estadoA != ultimoestadoA)
     {
       if (estadoA == LOW)
       {
         girandoH();
       }
       else
       {
         girandoAH();
       }
     }
     ultimoestadoA = estadoA;
   }

   switch (contadorMenu)
   {
    case (2):
      lcd.setCursor(0, 1);
      lcd.print(">");
      break;
    case (3):
      lcd.setCursor(0, 2);
      lcd.print(">");
      break;
    case (4):
      lcd.setCursor(0, 3);
      lcd.print(">");
      break;
    default:
      lcd.setCursor(0, 0);
      lcd.print(">");
   }

//se o botao for apertado no menu inicial, dependendo do led escolhido, sera o led que sera manipulado

     switch (!botaoApertado)
   {
    case (contadorMenu = 1 && menu):
      void menuLed1;
      !menu;
      break
    case (contadorMenu = 2 && menu):
      void menuLed2;
      !menu;
      break
    case (contadorMenu = 3 && menu):
      void menuLed3;
      !menu;
      break
    case (contadorMenu = 4 && menu):
      void menuLed4;
      !menu;
      break
    default: (menu)
      break;
   }
 
//se o botao for apertado em qualquer um dos modos,

   switch (!botaoApertado)
   {
    case (!menu):
      void menuPrincipal;
      break
    default:
      break;
   }

   if (menu)
   {
     menuPrincipal();
   }
 
//voids

 void girandoH (void)
 {
   switch (girandoH = true;)
   {
   case (modoAlteracaoLed1):
     int BrilhoLed1++;
     break;
   case (modoAlteracaoLed2):
     int BrilhoLed2++;
     break;
   case (modoAlteracaoLed3):
     int BrilhoLed3++;
     break;
   case (modoAlteracaoLed4):
     int BrilhoLed4++;
     break;
   default: (menuPrincipal)
   contadorMenu++;
     if (contadorMenu > 4)
     {
       contadorMenu = 4;
     }
   }
 }
 
 void girandoAH (void)
 {
   switch (girandoAH = true;)
   {
   case (modoAlteracaoLed1):
     intBrilhoLed1--;
     break;
   case (modoAlteracaoLed2):
     intBrilhoLed2--;
     break;
   case (modoAlteracaoLed3):
     intBrilhoLed3--;
     break;
   case (modoAlteracaoLed4):
     intBrilhoLed4--;
     break;
   default: (menuPrincipal)
   contadorMenu++;
     if (contadorMenu < 0)
     {
       contadorMenu = 0;
     }
   }
 }
 
 void menuPrincipal ()
 {
   lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("Led 1");
   lcd.setCursor(1,1);
   lcd.print("Led 2");
   lcd.setCursor(1,2);
   lcd.print("Led 3");
   lcd.setCursor(1,3);
   lcd.print("Led 4");

 }
 
 void menuLed1 (void)
 {
   lcd.clear();
   lcd.setCursor(7,0);
   lcd.print("Led 1");
   lcd.setCursor(5,3);
   lcd.print("Brilho: ");
   lcd.print(brilhoLed1);

 }
 
 void menuLed2 (void)
 {
   lcd.clear();
   lcd.setCursor(7,0);
   lcd.print("Led 2");
   lcd.setCursor(5,3);
   lcd.print("Brilho: ");
   lcd.print(brilhoLed2);
 }
 
 void menuLed3 (void)
 {
   lcd.clear();
   lcd.setCursor(7,0);
   lcd.print("Led 3");
   lcd.setCursor(5,3);
   lcd.print("Brilho: ");
   lcd.print(brilhoLed3);
 }
 
 void menuLed4 (void)
 {
   lcd.clear();
   lcd.setCursor(7,0);
   lcd.print("Led 4");
   lcd.setCursor(5,3);
   lcd.print("Brilho: ");
   lcd.print(brilhoLed4);
 }
 
 }