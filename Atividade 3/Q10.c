#include <stdio.h>

int main(){
  int num;

  do{
    printf("Digite \n1-Cadastrar; \n2-Alterar; \n3-Excluir; \n4-Sair;\n\n->");
    scanf("%i", &num);

    switch (num)  {
      case 1:
        printf("Opção Cadastrar\n");
        break;

      case 2:
        printf("Opção Alterar\n");
        break;

      case 3:
        printf("Opção Excluir\n");
        break;
      case 4:
        printf("Opção Sair\n");
        break;

      default:
        printf("Opção invalida\n");
    }

    printf("\n\n\n ---------------------");
  }while(num != 4);

  return 0;
}
