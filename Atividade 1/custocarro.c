#include <stdio.h>

/* Isto é um comentário */

int main(){
  float custofabrica, custoconsumidor;
  printf("Digite o custo de fábrica: ");
  scanf("%f", &custofabrica);

  custoconsumidor = custofabrica+(custofabrica*0.73);

  printf("O custo ao consumidor final é %f \n", custoconsumidor);
  return 0;
}