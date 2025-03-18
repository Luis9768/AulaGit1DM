// C++ code
//*****VARIAVEIS*******
unsigned int numeroA=1;
unsigned int numeroB= 0;
unsigned int resultado = 0;

void setup()
  {
 
  Serial.begin(9600);
  
  
  for(int x =0; x<26; x++)
  {
    resultado = numeroA+numeroB;
    Serial.println(resultado);
    numeroA = numeroB;
    numeroB = resultado;
  }


}

void loop()
{
  
  
}