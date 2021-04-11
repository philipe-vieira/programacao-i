#include <stdio.h>

/* Isto é um comentário */

int main(){
  float preco = 35.0;
  float peso, valorapag;
  printf("Digite o peso do prato: ");
  scanf("%f", &peso);
  
  valorapag = peso * preco;

  printf("O valor a pagar é: %f \n", valorapag);
  return 0;
}