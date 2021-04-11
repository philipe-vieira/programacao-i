#include <stdio.h>

int main(){
  int num1, num2, num3, aux;

  printf("Digite os 3 numeros... ");
  scanf("%i %i %i", &num1, &num2, &num3);

  if (num2 < num1){
    aux = num1;
    num1 = num2;
    num2 = aux;
  }
  if(num3 < num1){
    aux = num1;
    num1 = num3;
    num3 = aux;
  }
  if(num3 < num2){
    aux = num2;
    num2 = num3;
    num3 = aux;
  }

  printf("A ordem crescente é %i < %i < %i \n", num1, num2, num3);
  return 0;
}