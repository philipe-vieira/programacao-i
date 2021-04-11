#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int matricula;
  char nome[31];
  float nota;
} Aluno;

void imprimir_menu(){
  printf("1-Cadastrar alunos\n");
  printf("2-Alterar Dados do aluno\n");
  printf("3-Imprimir Aprovados\n");
  printf("4-Imprimir Reprovados\n");
  printf("5-Sair\n");
}
void cadastrar_alunos(Aluno *aluno){
  printf("Qual a matricula do aluno? ");
  scanf("%i", &aluno->matricula);

  printf("Qual o nome do aluno? ");
  scanf("%s", aluno->nome);
  
  printf("Qual a nota do aluno? ");
  scanf("%f", &aluno->nota);
}
int buscar_alunos(Aluno array_alunos[10], int matricula, int qnt){
  for(int i=0; i< qnt; i++){
    if(array_alunos[i].matricula == matricula)
      return i;
  }
  return qnt+1;
}
void alterar_alunos(Aluno array_alunos[10], int qnt){
  int matricula, indice;
  printf("Digite a matricula do aluno que quer alterar -> ");
  scanf("%i", &matricula);

  indice = buscar_alunos(array_alunos, matricula, qnt);

  if(indice == (qnt+1)){
    printf("Matricula não encontrada\n");
    return;
  }

  cadastrar_alunos(&array_alunos[indice]);
}
void imprimir_aprovados(Aluno array_alunos[10], int qnt){
  printf("LISTA DE ALUNOS APROVADOS\n");
  for(int i=0; i < qnt; i++){
    if(array_alunos[i].nota >= 7.0){
      printf("MATRICULA -> %i\n", array_alunos[i].matricula);
      printf("NOME      -> %s\n", array_alunos[i].nome);
      printf("NOTA      -> %f\n", array_alunos[i].nota);
      printf("------------------------------------\n\n");
    }
  }
}
void imprimir_reprovados(Aluno array_alunos[10], int qnt){
  printf("LISTA DE ALUNOS REPROVADOS\n");
  for(int i=0; i < qnt; i++){
    if(array_alunos[i].nota < 7.0){
      printf("MATRICULA -> %i\n", array_alunos[i].matricula);
      printf("NOME      -> %s\n", array_alunos[i].nome);
      printf("NOTA      -> %f\n", array_alunos[i].nota);
      printf("------------------------------------\n\n");
    }
  }
}

int main(){
  int sair = 0, qnt_alunos =0;
  Aluno array_alunos[10];

  do{
    int op;
    imprimir_menu();
    scanf("%i", &op);

    switch(op){
      case 1:
        if(qnt_alunos==10){
          printf("Quantidade máxima de alunos excedida\n");
          break;
        }
        cadastrar_alunos(&array_alunos[qnt_alunos]);
        qnt_alunos++;
      break;
      case 2:
        alterar_alunos(array_alunos, qnt_alunos);
      break;
      case 3:
        imprimir_aprovados(array_alunos, qnt_alunos);
      break;
      case 4:
        imprimir_reprovados(array_alunos, qnt_alunos);
      break;
      case 5:
        return 0;
      break;
      default:
      break;
    }

    printf("Deseja sair? 1-SIM/0-NAO -> ");
    scanf("%i", &sair);
    system("clear");
    system("cls");
  } while(sair == 0);

  return 0;
}