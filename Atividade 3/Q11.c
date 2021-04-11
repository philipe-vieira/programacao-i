#include <stdio.h>

int main(){
  int i;
  for(i = 0; i < 3; i++){
    float nota_1, nota_2, media_ponderada;
    printf("Digite as notas do aluno(a) %i: ", i+1);
    scanf("%f %f", &nota_1, &nota_2);

    media_ponderada = (nota_1 + (nota_2 * 2)) / 3;
    printf("Média pomderada do aluno%f \n\n", media_ponderada);
  }

  return 0;
}