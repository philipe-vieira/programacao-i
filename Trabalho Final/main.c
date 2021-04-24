#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Funcoes.h"

int main(){
	setlocale(LC_ALL, "portuguese_brazil");
	
	// Se��o de declara��o de variaveis globais
	int continuar=1;
	int qnt_de_passageiros_cadastrados = 0;
	Passageiro array_de_passageiros[100];
	
	// quantidade de passagens compradas por hor�rio
	// zerar quantidade de passagens compradas, nos 6 h�rarios disponiveis
	int qnt_passagensCompradas[6]={0,0,0,0,0,0};

	// Matriz de Passagens com 6 horarios de viagens e 40 assentos cada
	Passagem arrayPassagens[6][40];
	for (int z=0; z< 6; z++)
	{
		for(int g = 0; g < 40 ; g++)
		{
			arrayPassagens[z][g].assento = -1;
		}
	}
	// Mensagen de boas vindas
	printf("\tBem-vindo ao sistema TheBus\n");
	
	// loop de escolhas do usu�rio
	do{
		int escolha_do_usuario = -1;
		// Imprimindo Menu...
		imprimir_menu();
		// Ler ecolha do menu...
		scanf("%d", &escolha_do_usuario);
		
		switch(escolha_do_usuario)
		{
			case 1:
				// 1. Chama a fun��o que cadastra um passageiro
				// 2. Passa, por parametro uma posi��o do array de passageiros
				// 3. A posi��o do array corresponde a quantidade de passageiros cadastrado anteriormente
				// Ex.: Se h� 5 passageiros cadastrados, o 6� ser� cadastrado na posi��o 5 do array. Pois o array come�a com a posi��o 0				
				cadastro_passageiro(&array_de_passageiros[qnt_de_passageiros_cadastrados]);
				// Incrementa mais um passageiro cadastrado
				qnt_de_passageiros_cadastrados++;
				printf("\n\nPassageiro cadastrado com sucesso!\n");
			break;
			
			case 2:
				// Chama a funcao para alterar o cadastro do passageiro 
				alterar_passageiro (array_de_passageiros, qnt_de_passageiros_cadastrados);
				printf("\n\nPassageiro alterado com sucesso!\n");
			break;
			
			case 3:
				// Chama a funcao para comprar a passagem
				comprar_passagem(arrayPassagens, qnt_passagensCompradas, array_de_passageiros, qnt_de_passageiros_cadastrados);
			break;
			
			case 4:
				reembolso(array_de_passageiros, qnt_de_passageiros_cadastrados, arrayPassagens, qnt_passagensCompradas);
			break;
			
			case 5:
				listar_passageiros(array_de_passageiros, qnt_de_passageiros_cadastrados);
			break;
			
			case 6:
				listar_assentos_ocupados(arrayPassagens);
			break;
			
			case 0:
				sair();
				// Retorna 0 para para a execu��o da fun��o MAIN...
				return 0;
			break;
			
			default:
				printf("Digite uma opcao valida\n");
			break;
		}
		
		// Pausar a execu��o do script
		system("PAUSE");
		
		// Comandos para limpar a tela no Linux e no Windows...
		system("clear");
    system("cls");
	} while (continuar == 1);
	
	return 0;
}


/*
BACKLOG DE FU��ES A IMPLEMENTAR
// Fun��o para imprimir menu - OK
// Fun��o para cadastrar o passageiro - OK
// Fun��o para alterar o cadastro do passageiro - OK
// Fun��o para adquirir passagem - OK
// Fun��o para devolver passagem - OK
// Fun��o para listar os passageiros - OK
// Fun��o para listar os assentos comprados - OK
*/


