#include <stdio.h>

int main(){
  int num;

  do{
    printf("Digite 1-inclusão; 2-exclusão; 3-sair;");
    scanf("%i", &num);

    switch (num)  {
      case 1:
        printf("Incluído\n");
        break;

      case 2:
        printf("Excluído\n");
        break;

      case 3:
        printf("Saindo\n");
        break;

      default:
        printf("Opção invalida\n");
    }
  }while(num != 3);

  return 0;
}
