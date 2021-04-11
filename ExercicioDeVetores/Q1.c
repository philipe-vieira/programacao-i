#include <stdio.h>
#define TAM 10

int main() {
  char palavras[TAM][TAM];

  printf("Entre com a frase: \n");

  for (int i = 0; i < 10; i++){
    scanf("%s", palavras[i]);
  }

  for (int i = TAM - 1; i >= 0; i--){
    for (int j = TAM - 1; j >= 0; j--){
      printf("%c", palavras[i][j]);
    }
    printf("\n");
  }

  return 0;
}