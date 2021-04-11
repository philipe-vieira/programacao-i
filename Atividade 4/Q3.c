#include <stdio.h>

int main (){
  int voto, eleitores= 0, cand1 = 0, cand2 = 0, cand3 = 0, white = 0, nulos = 0;

  do{
    printf("Insira seu voto -> ");
    scanf("%i", &voto);
    eleitores++;

    switch(voto){
      case -1:
        eleitores--;
      break;
      case 1:
        cand1++;
      break;
      case 2:
        cand2++;
      break;
      case 3:
        cand3++;
      break;
      case 0:
        white++;
      break;
      case 4:
        nulos++;
      break;
      default:
        nulos++;
        printf("Voto inválido!\n");
      break;
    }
  } while (voto >= 0);

  if(cand1 > cand2 && cand1 > cand3){
    printf("O candidato 1 venceu a eleição.\n");
  } else if (cand2 > cand1 && cand2 > cand3){
    printf("O candidato 2 venceu a eleição.\n");
  } else if (cand3 > cand1 && cand3 > cand2){
    printf("O candidato 3 venceu a eleição.\n");
  } else if (cand1 == cand2 && cand1 > cand3){
    printf("Empate técnico entre os candidatos 1 e 2\n");
  } else if (cand1 == cand3 && cand1 > cand2){
    printf("Empate técnico entre os candidatos 1 e 3\n");
  } else if (cand2 == cand3 && cand2 > cand1){
    printf("Empate técnico entre os candidatos 2 e 3\n");
  }

  printf("Numero de votos brancos %i e nulos %i\n", white, nulos);
  printf("Quantidade de eleitores %i\n", eleitores);
  return 0;
}