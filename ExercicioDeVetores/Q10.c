#include <stdio.h>

int main(){
  int matriz[3][3], maior[2] = {0, 0};

  for (int i = 0; i< 3; i ++){
    for (int j = 0; j< 3; j ++){
      printf("Vendas do mes %d do vendedor %d ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i =0; i < 3; i++){
    for (int j = 0; j< 3; j ++){
      if(matriz[i][j] > maior[0]){
        maior[0] = matriz[i][j];
        maior[1] = j;
      }
    }
    printf("no mes %d a maior venda foi do vendedor %d, no valor de %d\n", i, maior[1], maior[0]);
    maior[0] = 0;
    maior[1] = 0;
  }

  return 0;
}