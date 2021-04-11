#include <stdio.h>

int main(){
  int qnt_num, i, impares = 1, pares = 0;
  printf("digite a quantidade de numeros desejada: ");
  scanf("%i", &qnt_num);

  int numeros[qnt_num];

  for(i = 0; i <qnt_num; i++){
    printf("digite o %i° numero: ", i+1);
    scanf("%i", &numeros[i]);
  }

  for(i = 0; i <qnt_num; i++){
    if(numeros[i]  % 2 == 0){
      pares += numeros[i];
    } else {
      impares = impares * numeros[i];
    }
  }

  printf("Produto dos impares %i // Soma dos pares %i\n", impares, pares);
  return 0;
}