#include <stdio.h>

int main() {
  float notas[100];
  int mat[100], aux, indice = -1, total;
  do {
    indice++;
    printf("Entre com a matricula (ou negativo para sair): ");
    scanf("%d", &mat[indice]);
    if(mat[indice] > 0){
      printf("Entre com a nota: ");
      scanf("%f", &notas[indice]);
    }
  } while ( mat[indice] > 0 );

  return 0;

}