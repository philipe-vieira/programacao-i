#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cliente{
	int cpf;
	char nome[31];
} Cliente;

typedef struct conta{
	int numero;
	Cliente cliente;
	float saldo;
} Conta;


void menu(){
	system("CLS");
	printf("1 - Cadastrar Cliente\n");
	printf("2 - Cadastrar Conta\n");
	printf("3 - Efetuar Depósito\n");
	printf("4 - Efetuar Transferência\n");
	printf("5 - Imprimir Clientes\n");
	printf("6 - Imprimir Contas\n");
	printf("7 - Sair\n");
	printf("Digite uma opção: ");
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
	printf("Digite o número da conta: ");
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

void impConta(Conta conta[100], int quant){
	int i;
	
	for (i = 0; i < quant; i++){
		printf("Número: %d\n", conta[i].numero);
		printf("Nome: %s\n", conta[i].cliente.nome);
		printf("Saldo: %f\n", conta[i].saldo);
	}
}

void depositar(Conta conta[100], int quant){
	int i, numero;
	float valor;
	printf("Digite o número da conta de depósito: ");
	scanf("%d", &numero);
	for (i = 0; i < quant; i++){
		if (numero == conta[i].numero){
			printf("Digite o valor do depósito: ");
			scanf("%f", &valor);
			conta[i].saldo = conta[i].saldo + valor;
		}
	}
}


int main() {
	int op, qCli = 0, qConta = 0;
	Cliente cli[100];
	Conta conta[100];
	Conta* c;
	setlocale(LC_ALL, "Portuguese");
	
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				cli[qCli] = cadCliente();
				qCli = qCli + 1;
				system("PAUSE");
				break;
			case 2:
				c = (Conta*) malloc (sizeof(Conta));
				cadConta(c, cli, qCli);
				qConta = qConta + 1;
				system("PAUSE");
				break;
			case 3:
				depositar(conta, qConta);
				system("PAUSE");
				break;
			case 4:
				system("PAUSE");
				break;
			case 5:
				impCliente(cli, qCli);
				system("PAUSE");
				break;
			case 6:
				impConta(conta, qConta);
				system("PAUSE");
				break;
			case 7:
				system("PAUSE");
				break;
			default:
				printf("Opção inválida\n");
				system("PAUSE");
		}
	}while (op != 7);
	return 0;
}
