#include <stdio.h>

int main(){
  int n, i, divisores=0;

  printf("Digite o numero desejado... ");
  scanf("%i", &n);

  printf("TABUADA DA ADIÇÃO\n");
  for(i=0; i<=10; i++){
    printf("%i + %i = %i;\n", n, i, n+i);
  }
  printf("TABUADA DA SUBTRAÇÃO\n");
  for(i=0; i<=10; i++){
    printf("%i - %i = %i;\n", n, i, n-i);
  }
  printf("TABUADA DA MULTIPLICAÇÃO\n");
  for(i=0; i<=10; i++){
    printf("%i * %i = %i;\n", n, i, n*i);
  }
  printf("TABUADA DA DIVISÃO\n");
  for(i=0; i<=10; i++){
    printf("%i / %i = %i;\n", n*i, n, i);
  }
  
  return 0;
}