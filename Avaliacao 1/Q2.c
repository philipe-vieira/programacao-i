#include <stdio.h>

int main(){
  int valor, pagamento, sair;

  do{
    printf("valor: ");
    scanf("%i", &valor);
    printf("Forma de pafamento: ");
    scanf("%i", &pagamento);

    switch(pagamento){
      case 1:
        printf("Pagamento a vista de %f\n", valor - (valor * 0.3));
      break;
      case 2:
        printf("Pagamento cartao de credito de %f\n", valor - (valor * 0.2));
      break;
      case 3:
        printf("Pagamento em 2x de %f\n", valor - (valor * 0.1));
      break;
      case 4:
        printf("Pagamento em 3x de %d\n", valor);
      break;
    }

    printf("Deseja fazer outro cálculo? 1 - Sim / 2 - Nao ");
    scanf("%i", &sair);
  } while (sair == 1);

  return 0;
}