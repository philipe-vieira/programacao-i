#include <stdio.h>

int main(){
  float nota1, nota2, media;

  printf("Digite a nota da prova 1: ");
  scanf("%f", &nota1);
  printf("Digite a nota da prova 2: ");
  scanf("%f", &nota2);

  media = (nota1+nota2)/2;

  if ( media >= 7)
    printf("O aluno foi aprovado com média %f", media);
  else
    printf("O aluno está de exame final com média %f \n", media);
  return 0;
}