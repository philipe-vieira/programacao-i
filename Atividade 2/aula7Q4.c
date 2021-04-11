#include <stdio.h>

int main(){
  int n, c, i, divisores=0;

  printf("Digite o numero desejado... ");
  scanf("%i", &n);

  for(c=2; c<=n; c++){
    for(i=1; i<c; i++){
      if(c%i == 0){
        divisores++;
      }
    }
    
    if(divisores < 2){
      printf("O numero '%i' é primo\n", c);
    } 

    divisores = 0;
  }
  
  return 0;
}