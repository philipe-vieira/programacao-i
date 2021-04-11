#include <stdio.h>

double media(double n1, double n2, double n3, char tipo){
  if(tipo == 'A'){
    return((n1+n2+n3)/3);
  } else if (tipo == 'P'){
    return(((n1*5)+(n2*2)+(n3*3))/10);
  } else {
    printf("Tipo de média não identificado");
    return 0;
  }

}

int main (){
  double nota1, nota2, nota3;
  char tipo;

  printf("Digite a nota 1 -> ");
  scanf("%lf", &nota1);
  printf("Digite a nota 2 -> ");
  scanf("%lf", &nota2);
  printf("Digite a nota 3 -> ");
  scanf("%lf", &nota3);
  printf("Digite o tipo de média (A - aritimetica; P - ponderada) -> ");
  scanf(" %c", &tipo);

  printf("média %.2f", media(nota1, nota2, nota3, tipo));
  
  return 0;
}