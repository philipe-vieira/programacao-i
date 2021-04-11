#include <stdio.h>

int main(){
  int resta, valida = 0, cont = 1;
  do{
    float nota_1, nota_2, media_ponderada;

    do{
      printf("Digite as notas do aluno(a) %i: ", cont);
      scanf("%f %f", &nota_1, &nota_2);

      if ((nota_1 >= 0 && nota_1 <= 10) && (nota_2 >= 0 && nota_2 <= 10)){
        valida = 1;
      } else {
        printf("Nota inválida! Digite novamente a nota.\n");
      }
    } while (valida != 1);
    

    media_ponderada = (nota_1 + (nota_2 * 2)) / 3;
    printf("Média pomderada do aluno%f \n\n", media_ponderada);

    printf("Ainda restam alunos a calcular? 1-SIM; 2-NÃO;");
    scanf("%i", &resta);
    cont++;
  } while(resta == 1);

  return 0;
}