#include <stdio.h>
#include <stdlib.h>

int* maior(int tam, int val[tam]){
  int maior =0, count =0;
  int* retorno = malloc(2);

  for(int i=0; i<tam; i++){
    if(val[i] > maior){
      maior = val[i];
    }
  }
  for(int i=0; i<tam; i++){
    if(val[i] == maior)
      count++;
  }
  retorno[0] = maior;
  retorno[1] = count;

  return retorno;
}

int main(){
  int tam = 10;
  int valores[tam];

  for(int i=0; i<tam; i++){
    printf("Digite o número de posição %i", i);
    scanf("%i", &valores[i]);
  }

  printf("Maior Elemento -> %i \n"
          "Qnt de vezes -> %i",
          maior(tam, valores)[0],
          maior(tam, valores)[1]);

  return 0;
}