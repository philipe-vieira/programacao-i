#include <stdio.h>

int main(){
  int num1, num2, num3, maior;

  printf("Digite os 3 numeros... ");
  scanf("%i %i %i", &num1, &num2, &num3);

  if(num1 > num2){
    maior = num1;
  } else {
    maior = num2;
  }
  if(num3 > maior){
    maior = num3;
  } 

  printf("O maior número é %i \n", maior);
  return 0;
}