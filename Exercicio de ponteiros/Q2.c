#include <stdio.h>

void calc_soma(int *a, int b){
  *a = *a+b;
}

int main(){
  int a, b;
  a=3;
  b=7;

  calc_soma(&a, b);

  printf("%i\n", a);

  return 0;
}