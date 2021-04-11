#include <stdio.h>

int main(){
  int idade, 
      maior= 0, 
      menor = 99999,
      masc = 0,
      femin = 0;
  char sexo, saida;

  do{
    printf("---Cadastro de aluno---\n");
    printf("idade: ");
    scanf("%d", &idade);
    printf("sexo: ");
    scanf("%s", &sexo);

    if(idade > maior){
      maior = idade;
      printf("maior = %d", maior);
    }

    if(idade < menor){
      menor = idade;
      printf("menor = %d", menor);
    }

    if(sexo == 'M' || sexo == 'm'){
      masc++;
    }
    
    if(sexo == 'F' || sexo == 'f'){
      femin++;
    }
    printf("Deseja continuar? S / N ");
    scanf("%s", &saida);
  } while (saida == 'S' || saida == 's');


  printf("Maior idade entre os alunos: %d \n"
         "Menor idade entre os alunos: %d \n"
         "Quantidade de alunos do sexo masculino %d \n"
         "Quantidade de alunos do sexo feminino %d \n", 
         maior, menor, masc, femin);


  return 0;
}