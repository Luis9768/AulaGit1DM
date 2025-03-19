// C++ code
//
int pinLeds[5] = {13,12,11,10,9};



void setup()
{
  pinMode(pinLeds[0], OUTPUT);
  pinMode(pinLeds[1], OUTPUT);
  pinMode(pinLeds[2], OUTPUT);
  pinMode(pinLeds[3], OUTPUT);
  pinMode(pinLeds[4], OUTPUT);
}

void loop()
{
  for (int i = 0; i < 5; i++){
  digitalWrite(pinLeds[i], HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(pinLeds[i], LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  }
  /* Para o for vc vai coloccar o numero no [], no caso das variaveis declaradas que
  que nesse caso seria (pinLeds) [] ai vc coloca o numero na caixinha 
   depois vem a variavel for que vc vai colocar o inicio em zero 
   o limite em cinco pq tem cinco pinLeds para acender e o incremento
   que é o ++ que sempre tem que ter ai vc abre chaves {} e dentro dele como
   é um loop coloca os digitaisWrites assim digtalWrite(pinLeds[i]
   o i no caso seria o nome que vc colocou no int então o pinLeds sera com [i]
   coloca high e low pra acender e desligar e pronto se quiser colocar delay tambem fds
  */
}


//int pinleds [6] = {2,3,6,9,5,5} exemplo