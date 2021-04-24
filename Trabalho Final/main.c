#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Funcoes.h"

int main(){
	setlocale(LC_ALL, "portuguese_brazil");
	
	// Seção de declaração de variaveis globais
	int continuar=1;
	int qnt_de_passageiros_cadastrados = 0;
	Passageiro array_de_passageiros[100];
	
	// quantidade de passagens compradas por horário
	// zerar quantidade de passagens compradas, nos 6 hórarios disponiveis
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
	
	// loop de escolhas do usuário
	do{
		int escolha_do_usuario = -1;
		// Imprimindo Menu...
		imprimir_menu();
		// Ler ecolha do menu...
		scanf("%d", &escolha_do_usuario);
		
		switch(escolha_do_usuario)
		{
			case 1:
				// 1. Chama a função que cadastra um passageiro
				// 2. Passa, por parametro uma posição do array de passageiros
				// 3. A posição do array corresponde a quantidade de passageiros cadastrado anteriormente
				// Ex.: Se há 5 passageiros cadastrados, o 6° será cadastrado na posição 5 do array. Pois o array começa com a posição 0				
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
				// Retorna 0 para para a execução da função MAIN...
				return 0;
			break;
			
			default:
				printf("Digite uma opcao valida\n");
			break;
		}
		
		// Pausar a execução do script
		system("PAUSE");
		
		// Comandos para limpar a tela no Linux e no Windows...
		system("clear");
    system("cls");
	} while (continuar == 1);
	
	return 0;
}


/*
BACKLOG DE FUÇÕES A IMPLEMENTAR
// Função para imprimir menu - OK
// Função para cadastrar o passageiro - OK
// Função para alterar o cadastro do passageiro - OK
// Função para adquirir passagem - OK
// Função para devolver passagem - OK
// Função para listar os passageiros - OK
// Função para listar os assentos comprados - OK
*/


