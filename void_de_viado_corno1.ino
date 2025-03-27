#include <Arduino.h>
#define  pinLed 18
//Prototipo da função

void ligaLed(uint8_t pin);
void desligaLed(uint8_t pin);


void setup() 
{
 pinMode(pinLed,OUTPUT);
}

void loop() 
{
  ligaLed(pinLed);
  delay(300);
  desligaLed(pinLed);
  delay(300);
}


void ligaLed(uint8_t pin)
{
digitalWrite(pin,HIGH);
}


void desligaLed(uint8_t pin)
{
  digitalWrite(pin,LOW);
}
