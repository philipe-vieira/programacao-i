#include <stdio.h>

int main() {
  int matriz[4][4], x;

  for(int i = 0; i < 4; i++){
    printf("Digite a linha %d da matriz: \n", i);
    scanf("%d %d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3]);
  }

  printf("IMPRIMINDO A DIAGONAL\n");
  for(int i = 0; i < 4; i++){
    printf(" %d", matriz[i][i]);
  }
  return 0;
}