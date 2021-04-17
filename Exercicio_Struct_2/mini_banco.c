#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
  int cpf;
  char nome[31];
} Cliente;
typedef struct {
	int numero;
	Cliente cliente;
	float saldo;
} Conta;

void imprimir_menu(){
	printf("1 Cadastrar Cliente\n");
  printf("2 Cadastrar Conta\n");
  printf("3 Efetuar Deposito\n");
  printf("4 Efetuar Transferencia\n");
  printf("5 Imprimir Saldo\n");
  printf("6 Sair\n");
}

void cadastrar_cliente(Cliente *cliente){
	printf("CPF -> ");
  scanf("%i", &cliente->cpf);

  printf("Nome -> ");
  scanf("%s", cliente->nome);
}

void cadastrar_conta(Conta *conta, Cliente clientes[100], int qnt_clientes){
	int cpf, encontra_cliente = 0;
	
	while(encontra_cliente == 0){
		printf("CPF do cliente -> ");
	  scanf("%i", &cpf);
	  
	  for(int i = 0; i < qnt_clientes; i++){
	  	if(clientes[i].cpf == cpf){
	  		conta->cliente = clientes[i];
	  		encontra_cliente = 1;
	  		break;
			}
		}
	}

  printf("Numero -> ");
  scanf("%i", &conta->numero);
  
  printf("Saldo -> ");
  scanf("%f", &conta->saldo);
}

void deposito(Conta contas[100], int qnt_contas){
	int numero_conta, encontra_conta = 0;
	float valor_deposito;
	
	do{
		printf("Numero da conta -> ");
		scanf("%i", &numero_conta);
		
		for(int i= 0; i < qnt_contas; i++){
			if(contas[i].numero == numero_conta){
				printf("Valor do deposito R$ ");
				scanf("%f", &valor_deposito);
				contas[i].saldo = contas[i].saldo + valor_deposito;
				
				encontra_conta = 1;
				break;
			}
		}	
	}while(encontra_conta == 0);

}

void transferencia(Conta contas[100], int qnt_contas){
	int numero_conta, encontra_conta = 0;
	float valor_transferencia;
	
	
	printf("Valor da transferencia R$ ");
	scanf("%f", &valor_transferencia);
	
	do{
		printf("Numero da conta Remetente -> ");
		scanf("%i", &numero_conta);
		
		for(int i= 0; i < qnt_contas; i++){
			if(contas[i].numero == numero_conta){
				contas[i].saldo = contas[i].saldo - valor_transferencia;
				
				encontra_conta = 1;
				break;
			}
		}	
	}while(encontra_conta == 0);
	
	encontra_conta = 0;
	
	do{
		printf("Numero da conta Destinatario -> ");
		scanf("%i", &numero_conta);
		
		for(int i= 0; i < qnt_contas; i++){
			if(contas[i].numero == numero_conta){
				contas[i].saldo = contas[i].saldo + valor_transferencia;
				
				encontra_conta = 1;
				break;
			}
		}	
	}while(encontra_conta == 0);
}

void imprimir_saldo(Conta contas[100], int qnt_contas){
	int encontra_conta = 0;
	
	do{
		int numero_conta;
		printf("Numero da conta -> ");
		scanf("%i", &numero_conta);
		
		for(int i= 0; i < qnt_contas; i++){
			if(contas[i].numero == numero_conta){
				printf("Conta %i\nSaldo %f\n", contas[i].numero, contas[i].saldo);
				
				encontra_conta = 1;
				break;
			}
		}	
	}while(encontra_conta == 0);
}

int main(){
	int qnt_clientes = 0, qnt_contas = 0, op;
	Cliente array_clientes[50];
	Conta array_contas[100];

  do{
    imprimir_menu();
    scanf("%i", &op);

    switch(op){
      case 1:
      	if(qnt_clientes==50){
          printf("Quantidade maxima de clientes excedida\n");
          break;
        }
        cadastrar_cliente(&array_clientes[qnt_clientes]);
        qnt_clientes++;
      break;
      case 2:
      	if(qnt_contas==100){
          printf("Quantidade maxima de contas excedida\n");
          break;
        }
        cadastrar_conta(&array_contas[qnt_contas], array_clientes, qnt_clientes);
        qnt_contas++;
      break;
      case 3:
      	deposito(array_contas, qnt_contas);
      break;
      case 4:
      	transferencia(array_contas, qnt_contas);
      break;
      case 5:
      	imprimir_saldo(array_contas, qnt_contas);
      	printf("Digite qualquer numero para sair...");
      	scanf("%i");
      break;
      default:
      break;
    }

    system("clear");
    system("cls");
  } while(op != 6);
	
	return 0;
}
