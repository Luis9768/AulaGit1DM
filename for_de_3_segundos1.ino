// C++ code
/*Faça um programa que acenda 3 leds, um por um, mantenha-os 
acesos por 3 segundos e em seguida apague-os, um por um.
*/
int pinLed [3] = {13,12,11};
bool estadoLed = 0;
  


void setup()
{
  
   pinMode(pinLed[0], OUTPUT);
   pinMode(pinLed[1], OUTPUT); 
   pinMode(pinLed[2], OUTPUT);

}
  
void loop()
{
  for (int i = 0; i < 3; i++){
    digitalWrite(pinLed[i],estadoLed);
      delay(300);
 
  } 
      delay(3000);

  estadoLed = !estadoLed;
}