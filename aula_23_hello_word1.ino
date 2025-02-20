//Luis MIguel

/*Autor Luis Miguel:


Nome do programa: Pisca-pisca semaforo 1
Descrição: Este é meu primeiro codigo em arduíno. Pisca o pino 13 
Data: 19/02/2025 
*/

#define pinLED 8
#define tempoPisca 5000
void setup() //Inicia o Arduíno
{
 pinMode(pinLED,OUTPUT);// Define o pino 8 como saída
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(2,OUTPUT);
}

void loop() // após o setup o programa fica em loop
{
   
  digitalWrite(13,HIGH);// aciona o pino 13(amarelo)
  delay(3000);//aguarda 1000ms (1s)
  digitalWrite(13,LOW);// desaciona o pino 13
  delay(3000); // aguarda 1000ms (1s)
  
  digitalWrite(12,HIGH); // aciona o pino 12 (vermelho)
  delay(2000); //aguarda 3000ms (1s)
  digitalWrite(12,LOW);// desaciona o pino 12
  delay(2000);// aguarda 3000ms (1s)

  digitalWrite(11,HIGH);// aciona o pino 8
  delay(2000);// aguarda 5000ms (1s)
  digitalWrite(11,LOW); // desaciona o pino 8
  delay(2000); // aguarda 5000ms (1s)
  
  digitalWrite(10,HIGH);// aciona o pino 13(amarelo)
  delay(3000);//aguarda 1000ms (1s)
  digitalWrite(10,LOW);// desaciona o pino 13
  delay(3000); // aguarda 1000ms (1s)
  
  digitalWrite(9,HIGH); // aciona o pino 12 (vermelho)
  delay(2000); //aguarda 3000ms (1s)
  digitalWrite(9,LOW);// desaciona o pino 12
  delay(2000);// aguarda 3000ms (1s)
 
  digitalWrite(pinLED,HIGH);// aciona o pino 8
  delay(tempoPisca);// aguarda 5000ms (1s)
  digitalWrite(pinLED,LOW); // desaciona o pino 8
  delay(tempoPisca); // aguarda 5000ms (1s) 
  
  digitalWrite(7,HIGH);// aciona o pino 13(amarelo)
  delay(3000);//aguarda 1000ms (1s)
  digitalWrite(7,LOW);// desaciona o pino 13
  delay(3000); // aguarda 1000ms (1s)
  
    
  digitalWrite(6,HIGH); // aciona o pino 12 (vermelho)
  delay(2000); //aguarda 3000ms (1s)
  digitalWrite(6,LOW);// desaciona o pino 12
  delay(2000);// aguarda 3000ms (1s)
   
  digitalWrite(5,HIGH);// aciona o pino 13(amarelo)
  delay(3000);//aguarda 1000ms (1s)
  digitalWrite(5,LOW);// desaciona o pino 13
  delay(3000); // aguarda 1000ms (1s)
  
  digitalWrite(4,HIGH); // aciona o pino 12 (vermelho)
  delay(2000); //aguarda 3000ms (1s)
  digitalWrite(4,LOW);// desaciona o pino 12
  delay(2000);// aguarda 3000ms (1s)
  
  digitalWrite(3,HIGH);// aciona o pino 13(amarelo)
  delay(3000);//aguarda 1000ms (1s)
  digitalWrite(3,LOW);// desaciona o pino 13
  delay(3000); // aguarda 1000ms (1s)
  
  digitalWrite(2,HIGH); // aciona o pino 12 (vermelho)
  delay(2000); //aguarda 3000ms (1s)
  digitalWrite(2,LOW);// desaciona o pino 12
  delay(2000);// aguarda 3000ms (1s)
  
  
}