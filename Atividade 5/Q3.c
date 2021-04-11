 #include <stdio.h>

int main(){
  int vetor[6], qnt_pares= 0, qnt_impares= 0;

  for(int i = 0; i < 6; i++){
    printf("Digite o numero de posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  for(int i = 0; i < 6; i++){
    if(vetor[i]%2 == 0){
      qnt_pares++;
      pares[i] = vetor[i];
    } else{
      qnt_impares++;
      impares[i] = vetor[i];
    }
  }

  printf("Quantidade de numeros pares= %d \n", qnt_pares);
  for(int i = 0; i < 6; i++){
    if(vetor[i]%2 == 0){
      printf(" %d", vetor[i]);
    }
  }

  printf("\n\nQuantidade de numeros impares= %d \n", qnt_impares);
  for(int i = 0; i < 6; i++){
    if(vetor[i]%2 == 1){
      printf(" %d", vetor[i]);
    }
  }

  return 0;
}