#include <stdio.h>

int main(){
  int num1, num2;

  printf("Digite 2 numeros: ");
  scanf("%i %i", &num1, &num2);

  if (num1 % num2 == 0) {
    printf("'X' é divisível por 'Y'!\n");
  } else {
    printf("'X' não é divisível por 'Y'!\n");
  }

  return 0;
}
