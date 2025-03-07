// C++ code
//

#define pinLedVermelho 10
#define pinLedVerde 13

unsigned long tempoms;
unsigned long tempoInicial = 0;
unsigned long tempoPisca = 0;
bool estadoLed = 2;

void setup()
  
{
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  Serial.begin (9600);
 
  
} 
void loop()
{
 tempoms = millis ();
 
  
  if(tempoms - tempoInicial >= tempoPisca)
  {
  estadoLed = !estadoLed;
  tempoInicial = tempoms;
  }
 digitalWrite(pinLedVermelho,estadoLed); 
  
}