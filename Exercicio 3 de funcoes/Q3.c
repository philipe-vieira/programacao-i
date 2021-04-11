#include <stdio.h>

int* inverte(int tam, int vet[tam]){
  int vet2[tam];

  for(int i=0; i <tam; i++){
    vet2[tam - i - 1] = vet[i];
  }

  vet = vet2;

  return vet;
}

int main(){
  int tam = 10;
  int vet[tam];

  for(int i=0; i<tam; i++){
    printf("Digite o numero de posição %d -> ", i);
    scanf("%i", &vet[i]);
  }

  for(int i=0; i<tam; i++){
    printf("%i | ", inverte(tam, vet)[i]);
  }

  return 0;
}