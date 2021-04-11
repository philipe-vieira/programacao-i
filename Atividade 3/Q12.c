#include <stdio.h>

int main(){
  int resta, cont = 1;
  do{
    float nota_1, nota_2, media_ponderada;
    printf("Digite as notas do aluno(a) %i: ", cont);
    scanf("%f %f", &nota_1, &nota_2);

    media_ponderada = (nota_1 + (nota_2 * 2)) / 3;
    printf("Média pomderada do aluno%f \n\n", media_ponderada);

    printf("Ainda restam alunos a calcular? 1-SIM; 2-NÃO;");
    scanf("%i", &resta);
    cont++;
  } while(resta == 1);

  return 0;
}