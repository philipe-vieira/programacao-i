#include <stdio.h>

int main(){
  int valor, pagamento;

  printf("valor: ");
  scanf("%i", &valor);
  printf("Forma de pafamento: ");
  scanf("%i", &pagamento);

  switch(pagamento){
    case 1:
      printf("Pagamento a vista de %f", valor - (valor * 0.3));
    break;
    case 2:
      printf("Pagamento cartao de credito de %f", valor - (valor * 0.2));
    break;
    case 3:
      printf("Pagamento em 2x de %f", valor - (valor * 0.1));
    break;
    case 4:
      printf("Pagamento em 3x de %d", valor);
    break;
  }
  return 0;
}