// C++ code
//autor : LUIS MIGUEL
void setup()
{
  Serial.begin(9600);
  
  /*int diaDaSemana = 2;
  
  switch(diaDaSemana){
  case 1:
    //Faça alguma coisa
    Serial.println("Domingo");
  break;
    case 2:
    //Faça alguma coisa
    Serial.println("Segunda");
  break;
    case 3:
    //Faça alguma coisa
    Serial.println("Terça");
  break;
    case 4:
    //Faça alguma coisa
    Serial.println("Quarta");
  break;
    case 5:
    //Faça alguma coisa
    Serial.println("Quinta");
  break;
    case 6:
    //Faça alguma coisa
    Serial.println("Sexta");
  break;
    case 7:
    //Faça alguma coisa
    Serial.println("Sabado");
  break;
   default :
    // opçao invalida
    break ;
  
  } 
  switch(diaDaSemana){
 case 5:
    case 6:
    case 7:
     Serial.println("");
    break;*/
  int numeroCor = 1;
    
    
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  
  switch (numeroCor){
  case 1:
  Serial.println("azul");
  digitalWrite(13,HIGH);
  
  
    break;
       
    case 2:
    Serial.println("verde");
    digitalWrite(10,HIGH);
    
   
  break;
      case 3:
    Serial.println("branco");
    digitalWrite(9,HIGH);
    
     
  break;
    case 4:
    Serial.println("vermelho");
    digitalWrite(12,HIGH);
    
      
    
  break;
    case 5:
    
    Serial.println("amarelo");
    digitalWrite(11,HIGH);
    
    
    
  break;
      default:("opcao invalida");
                   
                   
    break;               
                   

  
  
  
  
  
  
  
  
  }
  
  
  
  
  
  }
  
  
  
  
  
  
  
  
  

void loop()
{
  
}