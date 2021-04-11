#include <stdio.h>
#include "Q1funcoes.h"

int main(){
  char string[15];
  int n;

  printf("Digite a string: ");
	scanf("%s", string);
  printf("Digite o numero: ");
	scanf("%i", &n);

  repete(string, n);
  return 0;
}