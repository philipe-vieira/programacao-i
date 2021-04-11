#include <stdio.h>

int main(){
  float preco, valor, litros;
  printf("Digite o preço da gasolina: ");
  scanf("%f", &preco);
  printf("Digite o valor do abastecimento: ");
  scanf("%f", &valor);

  litros = valor / preco;
  printf("O a quantidade de litros abastecida foi %f \n", litros);
  return 0;
}