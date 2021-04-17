#include <stdio.h>
#include <stdlib.h>
#include "FuncoesBanco.h"

void menu(){
	system("CLS");
	printf("1 - Cadastrar Cliente\n");
	printf("2 - Cadastrar Conta\n");
	printf("3 - Efetuar Dep�sito\n");
	printf("4 - Efetuar Transfer�ncia\n");
	printf("5 - Imprimir Clientes\n");
	printf("6 - Imprimir Contas\n");
	printf("7 - Sair\n");
	printf("Digite uma op��o: ");
}

Cliente cadCliente(){
	Cliente cliente;
	printf("Digite o cpf do cliente: ");
	scanf("%d", &cliente.cpf);
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	gets(cliente.nome);
	return cliente;
}

Conta* cadConta(Conta* conta, Cliente cli[100], int qCli){
	int i, cpf;
	printf("Digite o n�mero da conta: ");
	scanf("%d", &conta->numero);
	printf("Digite o cpf do cliente: ");
	scanf("%d", &cpf);
	for (i = 0; i < qCli; i++){
		if (cpf == cli[i].cpf){
			conta->cliente = cli[i];
			conta->saldo = 0;
		}
	}
	return conta;
}

void impCliente(Cliente cli[100], int quant){
	int i;
	
	for (i = 0; i < quant; i++){
		printf("Cpf: %d\n", cli[i].cpf);
		printf("Nome: %s\n", cli[i].nome);
	}
}

void impConta(Conta** conta, int quant){
	int i;
	
	for (i = 0; i < quant; i++){
		printf("N�mero: %d\n", conta[i]->numero);
		printf("Nome: %s\n", conta[i]->cliente.nome);
		printf("Saldo: %f\n", conta[i]->saldo);
	}
}

void depositar(Conta conta[100], int quant){
	int i, numero;
	float valor;
	printf("Digite o n�mero da conta de dep�sito: ");
	scanf("%d", &numero);
	for (i = 0; i < quant; i++){
		if (numero == conta[i]->numero){
			printf("Digite o valor do dep�sito: ");
			scanf("%f", &valor);
			conta[i]->saldo = conta[i]->saldo + valor;
		}
	}
}

