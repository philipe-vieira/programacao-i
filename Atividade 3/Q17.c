#include <stdio.h>

int main(){
  int num1, num2, produto = 0, i;
  printf("Digite dois numeros: ");
  scanf("%i %i", &num1, &num2);

  for(i = 0; i < num2; i++){
    produto += num1;
  }

  printf("O produto dos dois numeros é: %i \n", produto);

  return 0;
}