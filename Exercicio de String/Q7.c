#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char data[11], *aux;
  int dia, mes, ano;

  printf("Digite a data: ");
	scanf("%s", data);

  //verificar se barras estao no lugar certo
  if(data[2] != 47 && data[5] != 47){
    printf("Formato de data inválida!\n");
    return 0;
  }

  //verificar se caractere é numerico
  for(int i=0; i < 11; i++){
    if(i != 2 && i != 5){
      // se a posição do array for vazia, para
      if(data[i] == '\0' || data[i] == '.'){
        break;
      }
      if(data[i] < 48 || data[i] > 57 ){
        printf("Formato de data não suporta o caractere %c\n", data[i]);
        printf("Data inválida! %s\n", data);
        return 0;
      }
    }
  }

  aux = strtok(data, "/");
  dia = atoi(aux);
  aux = strtok(NULL, "/");
  mes = atoi(aux);
  aux = strtok(NULL, "/");
  ano = atoi(aux);

  printf("Dia: %d\n", dia);
  printf("Mes: %d\n", mes);
  printf("Ano: %d\n", ano);
  
  return 0;
}