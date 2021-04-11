#include <stdio.h>

/* Isto é um comentário */

int main(){
  int anos, meses, dias;
  printf("Digite a qnt de anos: \n");
  scanf("%d", &anos);
  printf("Digite a qnt de meses: \n");
  scanf("%d", &meses);
  dias = (anos * 365) + (meses * 30);

  printf("A idade em dias é: %d \n", dias);
  return 0;
}