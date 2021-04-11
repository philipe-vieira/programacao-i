#include <stdio.h>

int main(){
  int n, count=0, impar=1;

  printf("Digite a quantidade de numeros primos desejados... ");
  scanf("%i", &n);

  do{
    if(impar%2 != 0){
      printf("%i\n", impar);
      count++;
    }
    impar++;
  }while(count < n);
  
  return 0;
}