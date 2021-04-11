#include <stdio.h>
#define TAM 10

int main() {
  int X[10], Y[10], pos = 0;

  for(int i = 0; i < 10; i++){
    scanf("%d", &X[i]);
  }

  for(int i = 9; i >=0; i--){
    Y[pos] = X[i];
    pos++;
  }

  printf("VETOR Y\n");
  for(int i = 0; i < 10; i++){
    printf(" %d", Y[i]);
  }

  return 0;
}