#include <stdio.h>

int main(){
  int matriz[3][3], SL[3]={0,0,0}, SC[3]={0,0,0};

  for (int i = 0; i< 3; i ++){
    for (int j = 0; j< 3; j ++){
      printf("Digite o numero da posição %dx%d", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i =0; i < 3; i++){
    for (int j = 0; j< 3; j ++){
      SL[i] = SL[i] + matriz[i][j];
      SC[i] = SC[i] + matriz[j][i];
    }
  }

  for(int i = 0; i < 3; i++){
    printf("SL de pos %d= %d\n", i, SL[i]);
    printf("Sc de pos %d= %d\n", i, SC[i]);
  }

  return 0;
}