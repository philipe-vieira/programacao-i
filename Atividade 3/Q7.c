#include <stdio.h>

int main(){
    int qnt_alunos, i, soma = 0, test;
    printf("Digite o numero de alunos");
    scanf("%i", &qnt_alunos);
    
    int idades[qnt_alunos];
    
    for(i = 0; i < qnt_alunos; i++){
    	printf("\nDigite a idade do aluno: ");	
    	scanf("%i", &idades[i]);
		}
		
		for(i = 0; i < qnt_alunos; i++){
			soma += idades[i];
		}
		
		soma = soma / qnt_alunos;
		
		printf("A média de idades dos alunos é: %i\n", soma);

    return 0;
}