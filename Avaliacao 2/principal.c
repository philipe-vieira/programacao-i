#include <stdio.h>
#include "funcoes.h"

int main(){
  char alunos[10][21];
  float notas[10];

  LeiaNomes(alunos);
  LeiaNotas(notas);
  EscreveAprovados(alunos, notas);
  EscreveMaior(alunos, notas);
  
  return 0;
}