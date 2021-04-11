#include <stdio.h>

int main(){
  int qnt_num, i, menor = 999999;
  printf("digite a quantidade de numeros desejada: ");
  scanf("%i", &qnt_num);

  int numeros[qnt_num];

  for(i = 0; i <qnt_num; i++){
    printf("digite o %i° numero: ", i+1);
    scanf("%i", &numeros[i]);
  }

  for(i = 0; i <qnt_num; i++){
    if(numeros[i] < menor){
      menor = numeros[i];
    }
  }

  printf("O menor numero é o %i\n", menor);
  return 0;
}