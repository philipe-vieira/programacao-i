#include <stdio.h>

int main() {
  int matriz[3][3],  divisores = 0;

  for(int i = 0; i < 3; i++){
    printf("Digite a linha %d da matriz: \n", i);
    scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int i=1; i<matriz[i][j]; i++){
        if(matriz[i][j]%i == 0){
          divisores++;
        }
      }
      
      if(divisores < 2){
        printf("O numero '%i' é primo\n", matriz[i][j]);
      } 
    }
    divisores = 0;
  }

  return 0;
}
