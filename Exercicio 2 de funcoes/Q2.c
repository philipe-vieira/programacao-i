#include <stdio.h>

void uppcase(char string[3][30]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 30; j++){
      //Se caractere for letra minuscula
      if(string[i][j] > 96 && string[i][j] < 123){
        string[i][j] = string[i][j] - 32;
      }
    }
  }

  for(int i=0; i<3; i++){
    printf("%s\n", string[i]);
  }
}


int main(){
  char string[3][30];
	
  for(int i=0; i<3; i++){
    printf("Digite a string de posição %i: ", i);
    scanf("%s", string[i]);
  }

  uppcase(string);

	
  return 0;
}