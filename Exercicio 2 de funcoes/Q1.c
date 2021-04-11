#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qnt_caractere(char string[], char caractere){
  int qnt=0;

  for(int i = 0; i < 15; i++){
    if(string[i] == '\0')
      break;
    if(string[i] == caractere)
      qnt++;
  }

  return(qnt);
}


int main(){
  char string[15], carac;
	
	printf("Digite a string: ");
	scanf("%s", string);
  printf("Digite o caractere: ");
	scanf(" %c", &carac);
  
  printf("%i\n", qnt_caractere(string, carac));
	
  return 0;
}