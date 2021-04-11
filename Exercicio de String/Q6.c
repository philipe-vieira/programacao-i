#include <stdio.h>

int main(){
	char nome[10][15];
  int idade[10], jovem = 0, velho = 0;
  

  for(int i = 0; i < 10; i++){
    printf("Digite a idade: ");
	  scanf("%d", &idade[i]);
    if(idade[i] < 0){
      break;
    }
    printf("Digite o primeiro nome: ");
	  scanf("%s", nome[i]);
  }

    printf("test");
  for(int i = 0; i < 10; i++){
    if(idade[i] < 0){
      break;
    }
    if(idade[i] > 0 && idade[i] < idade[jovem]){
      jovem = i;
    }
    if(idade[i] > 0 && idade[i] > idade[velho]){
      velho = i;
    }
  }

  printf("Mais jovem é %s com %d anos\n", nome[jovem], idade[jovem]);
  printf("Mais velho é %s com %d anos\n", nome[velho], idade[velho]);
	
	return 0;
}