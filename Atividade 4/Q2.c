#include <stdio.h>

int main(){
  int i, f, n, aux;

  printf("Digite o inteiro I: ");
  scanf("%d", &i);
  printf("Digite o inteiro F: ");
  scanf("%d", &f);

  if(i > f){
    aux = i;
    i = f;
    f = aux;
  }

  for(n = i; n <= f; n++){
    if( n % 2 != 0){
      printf(" - %d", n);
    }
  }

  printf("\n");
  return 0;
}