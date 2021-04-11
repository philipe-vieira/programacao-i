#include <stdio.h>

int main() {
  int matriz[3][3], matriz2[3][3];

  for(int i = 0; i < 3; i++){
    printf("Digite a linha %d da matriz: \n", i);
    scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      matriz2[i][j] = matriz[i][j] *2;
    }
  }

  printf("IMPRIMINDO A MATRIZ 2 \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf(" %d", matriz2[i][j]);
    }
    printf("\n");
  }

  return 0;
}