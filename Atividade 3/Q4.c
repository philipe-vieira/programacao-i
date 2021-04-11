#include <stdio.h>

int main(){
  int mes;
  char mes_ano[12][10] = {"janeiro", "fevereiro", "março","abril", "maio", "junho", "julho","agosto", "setembro", "outubro","novembro", "dezembro"};

  printf("Digite o número do mês: ");
  scanf("%i", &mes);

  if (mes >= 1 && mes <= 12) {
    printf("%s\n" , mes_ano[mes - 1]);
  } else {
    printf("Mês Inválido\n");
  }

  return 0;
}
