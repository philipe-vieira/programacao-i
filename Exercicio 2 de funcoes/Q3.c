#include <stdio.h>

int* leia_vetor_10(int vetor[10]){
  for(int i =0; i < 10; i++){
    printf("Digite o inteiro de posição %i: ", i);
    scanf("%i", &vetor[i]);
  }

  return vetor;
}

int* multiplica(int vetor[10], int inteiro){
  for(int i =0; i < 10; i++){
    vetor[i] = vetor[i] * inteiro;
  }

  return vetor;
}

void escreve_vetor(int vetor[10]){
  for(int i =0; i < 10; i++){
    printf("%i\n", vetor[i]);
  }
}

int main(){
  int multiplicador, vetor[10];

  printf("Por quanto deseja multiplicar? ");
  scanf("%i", &multiplicador);

  escreve_vetor(multiplica(leia_vetor_10(vetor), multiplicador));

  return 0;
}