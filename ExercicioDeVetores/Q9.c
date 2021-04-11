#include <stdio.h>

int main() {
  int A[3][3], B[3][3];

  for(int i = 0; i < 3; i++){
    printf("Digite a linha %d da MATRIZ: \n", i);
    scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      B[i][j] = A[j][i];
    }
  }

  printf("IMPRIMINDO A MATRIZ B \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf(" %d", B[i][j]);
    }
    printf("\n");
  }

  return 0;
}