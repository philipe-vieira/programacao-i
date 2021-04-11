#include <stdio.h>

char* LeiaNomes(char alunos[10][21]){
  for(int i=0; i<10; i++){
    printf("Digite o nome do aluno %d -> ", i+1);
    scanf("%s", alunos[i]);
  }
  
  return *alunos;
}

float* LeiaNotas(float notas[10]){
  for(int i=0; i<10; i++){
    printf("Digite a nota do aluno %d -> ", i+1);
    scanf("%f", &notas[i]);
  }

  return(notas);
}

void EscreveAprovados(char alunos[10][21], float notas[10]){
  for(int i=0; i<10; i++){
    if(notas[i] >= 7.0)
      printf("Aluno %s aprovado com nota %f\n", alunos[i], notas[i]);
  }
}

void EscreveMaior(char alunos[10][21], float notas[10]){
  int indiceMaior = -1;

  for(int i=0; i<10; i++){
    if(notas[i] >= notas[indiceMaior])
      indiceMaior = i;
  }

  printf("Aluno %s teve nota %f e esta foi a maior nota\n", 
    alunos[indiceMaior], 
    notas[indiceMaior]);
}