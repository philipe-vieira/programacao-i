#include <stdio.h>

int main(){
  int num;
  char array_num[10][6] = {"um", "dois", "tres", "quatro", "cinco", "seis","sete", "oito", "nove", "dez"};

  printf("Digite o numero desejado: ");
  scanf("%i", &num);

  if (num > 0 && num <= 10) {
    printf("%s\n" , array_num[num - 1]);
  }
  else {
    printf("Numero invalido\n");
  }

  return 0;
}