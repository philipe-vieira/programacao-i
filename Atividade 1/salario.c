#include <stdio.h>

/* Isto é um comentário */

int main(){
  float salario_inicial, salario_aumentado, salario_descontado;
  printf("Digite o salario do funcionario: ");
  scanf("%f", &salario_inicial);
  
  salario_aumentado = salario_inicial+(salario_inicial*0.15);
  salario_descontado = salario_aumentado-(salario_aumentado*0.08);

  printf("O funcionario tera o salario inicial de %f, ", salario_inicial);
  printf("somado o acrescimo no valor de %f, ",salario_aumentado);
  printf("e com os descontos de impostos no valor de %f \n", salario_descontado);
  return 0;
}