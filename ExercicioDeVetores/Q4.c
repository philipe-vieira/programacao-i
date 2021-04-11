#include <stdio.h>

int main() {
  int A[10], x;

  printf("Entre com os valores do vetor: ");
  scanf("%d %d %d %d %d %d %d %d %d %d", 
    &A[0], &A[1], &A[2], &A[3], &A[4], 
    &A[5], &A[6], &A[7], &A[8], &A[9]);

  printf("Entre com o valor de X: ");
  scanf("%d", &x);

  printf("indices iguais a X: \n");
  for(int i = 0; i < 10; i++){
    if(A[i] == x){
      printf(" %d", i);
    }
  }
  
  return 0;
}