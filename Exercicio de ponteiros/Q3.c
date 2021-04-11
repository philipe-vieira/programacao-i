#include <stdio.h>

int negativos(float *vet, int N){
  int qnt_negativos=0;

  for(int i=0; i<N; i++){
    if(vet[i] < 0.0)
      qnt_negativos++;
  }

  return qnt_negativos;
}

int main(){
  int tam = 3;
  float vet[tam];

  for(int i=0; i<tam; i++){
    printf("Digite o numero %i ", i);
    scanf("%f", &vet[i]);
  }

  printf("Quantidade de negativos é %i\n", negativos(vet, tam));

  return 0;
}