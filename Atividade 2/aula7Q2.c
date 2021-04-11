#include <stdio.h>

int main(){
  int n, count=0, soma=0;

  printf("Digite o numero desejado... ");
  scanf("%i", &n);

  do{
    soma=soma+count;
    count++;
  }while(count <= n);

  printf("A soma dos numeros de 1 ate %i é de %i\n", n, soma);
  
  return 0;
}