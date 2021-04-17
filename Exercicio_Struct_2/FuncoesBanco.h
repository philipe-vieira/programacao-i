typedef struct cliente{
	int cpf;
	char nome[31];
} Cliente;

typedef struct conta{
	int numero;
	Cliente cliente;
	float saldo;
} Conta;

void menu();

Cliente cadCliente();

Conta* cadConta(Conta* conta, Cliente cli[100], int qCli);

void impCliente(Cliente cli[100], int quant);

void impConta(Conta** conta, int quant);

void depositar(Conta** conta, int quant);
