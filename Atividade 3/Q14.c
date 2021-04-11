#include <stdio.h>

int main(){
  int paisA = 5000000, paisB = 7000000, tempo = 0;

  do{
    tempo ++;
    paisA += paisA * 0.03;
    paisB += paisB * 0.02;
    printf("%i %i %i\n", paisA, paisB, tempo);
  }while(paisA <= paisB);

  printf("Leva %i anos para ultrapassar\n", tempo);

  return 0;
}