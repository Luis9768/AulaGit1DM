int resultado = 0; 


void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; 11 > i; i++)//FAZ O FOR NORMALMENTE
  {
  resultado = 5 * i;//PEGA O RESULTADO METE UM = E A CONTA
  Serial.print("5 x ");//SINTAXE DE LEITURA NÃO FAZ PARTE DA CONTA
  Serial.print(i);// LETRA REPRESENTANTE DO FOR
  Serial.print(" = "); //SINTAXE DE LEITURA
  Serial.println(resultado);// E PEGA O RESULTADO TRANSFORMADO POR CONTA DA CONTA NA LINHA 8
  }
}

void loop()
{
  
}