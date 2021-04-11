#include <stdio.h>

int main(){
  int mat;

  printf("Digite a matricula do aluno ");
  scanf("%d", &mat);
  
  switch(mat){
    case 42066:
      printf("Você digitou a matricula da aluna Ana\n");
      break;
    
    case 42417:
      printf("Você digitou a matricula da aluna Camila\n");
      break;

    case 44609:
      printf("Você digitou a matricula do aluno Leo\n");
      break;

    case 44635:
      printf("Você digitou a matricula do aluno Joao\n");
      break;

    default:
      printf("Matrícula não identificada\n");
      break;
  }
  return 0;
}