#include <stdio.h>

int main(){
  int A[2][3], B[2][3], S[2][3], D[2][3];

  for (int i = 0; i< 2; i ++){
    for (int j = 0; j< 3; j ++){
      printf("Digite a matriz A da posição %dx%d", i, j);
      scanf("%d", &A[i][j]);
      printf("Digite a matriz B da posição %dx%d", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i< 2; i ++){
    for (int j = 0; j< 3; j ++){
      S[i][j] = A[i][j] + B[i][j];
      D[i][j] = A[i][j] - B[i][j];
    }
  }

  printf("--- MATRIZ S ---\n");
  for (int i = 0; i< 2; i ++){
    for (int j = 0; j< 3; j ++){
      printf("  %2d", S[i][j]);
    }
    printf("\n");
  }

  printf("--- MATRIZ D ---\n");
  for (int i = 0; i< 2; i ++){
    for (int j = 0; j< 3; j ++){
      printf("  %2d", D[i][j]);
    }
    printf("\n");
  }

  return 0;
}