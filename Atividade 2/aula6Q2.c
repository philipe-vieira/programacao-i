#include <stdio.h>

int main(){
  char caracter;

  printf("Digite um caracter... ");
  scanf("%c", &caracter);

  switch(caracter){
    case 'a':
      printf("O caractere '%c' é uma vogal.\n", caracter);
      break;
    case 'e':
      printf("O caractere '%c' é uma vogal.\n", caracter);
      break;
    case 'i':
      printf("O caractere '%c' é uma vogal.\n", caracter);
      break;
    case 'o':
      printf("O caractere '%c' é uma vogal.\n", caracter);
      break;
    case 'u':
      printf("O caractere '%c' é uma vogal.\n", caracter);
      break;
    default:
      printf("O caractere '%c' não é uma vogal.\n", caracter);
      break;
  }
}