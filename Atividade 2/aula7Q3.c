#include <stdio.h>

int main(){
  int n,i, divisores=0;

  printf("Digite o desejado... ");
  scanf("%i", &n);

  for(i=1; i<n; i++){
    if(n%i == 0){
      divisores++;
    }
  }
  
  if(divisores < 2){
    printf("O numero '%i' é primo\n", n);
  } else {
    printf("este numero não é primo\n");
  }

  return 0;
}