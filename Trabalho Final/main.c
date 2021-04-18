#include <stdio.h>
#include <locale.h>

// Struct para o cliente
typedef struct{
	int cpf;
	char nome[30];
}Cliente;
// Struct para a passagem
typedef struct{
	int assento;
	Cliente passageiro;
}Passagem;

// Fun��o para imprimir menu - OK
void imprimir_menu(){
	printf("\t Escolha a op��o desejada\n\n");
	printf("1. Cadastro de Passageiro\n");
	printf("2. Alterar cadastro do Passageiro\n");
	printf("3. Comprar Passagens\n");
	printf("4. Solicitar Reembolso\n");
	printf("0. Sair\n");
}

// Fun��o para cadastrar o cliente - OK
void cadastro_cliente(Cliente *cliente)
{
  printf("Bem-vindo ao sistema TheBus!\nDigite as informa��es desejadas para a efetua��o do cadastro.\n");
  
  // Lendo o CPF do cliente
  printf("CPF -> ");
  scanf("%i", &cliente->cpf);

	// Lendo o nome do cliente
  printf("Nome -> ");
  scanf("%s", cliente->nome);
}

// Funcao para alterar o cadastro do cliente - OK
// Obs.: Os parametros nao precisam ser ponteiros pois n�o serao alterados aqui, mas sim na funcao cadastro_cliente()
void alterar_cliente (Cliente array_de_clientes[100], int qnt_de_clientes)
{
	// Sessao p/ declara��o de variaveis
	int cpf, posicao_no_array=-1;
	
	// Lendo o cpf a ser alterado
	printf("Digite o cpf do cliente a ser alterado -> ");
  scanf("%i", &cpf);
  
  // Procurando a posicao do array que aquele cpf se encontra
  // Obs.: i < qnt_de_clientes -> para n�o procurar nas posicoes ainda vazias
  for(int i=0; i < qnt_de_clientes; i++){
    if(array_de_clientes[i].cpf == cpf)
      posicao_no_array = i;
  }
  
  // Se a posi��o do array ainda � o valor iniciado,
  // Ent�o o cpf do cliente nao foi encontrado
  if (posicao_no_array == -1){
  	printf("O CPF do cliente n�o foi encontrado\n");
  	// RETURN para para a fun��o alterar_cliente
    return;
	}
	
	// Se o cpf foi encontrado no array, executa o cadastro novamente
	cadastro_cliente(&array_de_clientes[posicao_no_array]);	
}

/* Acredito que essa fun��o n�o ser� necess�ria. By Philipe
void minhaconta()
{
    printf("Bem-vindo ao cadastro do cliente.\n");
}
*/

void comprar_passagem()
{
    printf("Voc� acaba de solicitar a compra de passagem.\n"
		" Por favor selecine a data e o assento desejado, "
		"em seguida listaremos os horarios disponiveis para o itiner�rio");
    /* provavelmente teremos que fazer um banco de dados com os horarios disponiveis?
	segunda a domingo, desses 7 dias, colocaremos 10 horarios por dias disponiveis?
	oq voc�s acham?  
	*/
}

void reembolso()
{
    printf("Voc� acaba de solicitar o reembolso de passagem.\n por favor leia as regras.\n");
}

void sair()
{
    printf("Voc� soliciou a op��o sair. agradecemos a utiliza��o do nosso sistema.\n");
}


int main()
{
	setlocale(LC_ALL, "portuguese_brazil");
	
	// Se��o de declara��o de variaveis globais
	int continuar=1;
	int qnt_de_clientes_cadastrados = 0;
	Cliente array_de_clientes[100];
	
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
				// 1. Chama a fun��o que cadastra um cliente
				// 2. Passa, por parametro uma posi��o do array de clientes
				// 3. A posi��o do array corresponde a quantidade de clientes cadastrado anteriormente
				// Ex.: Se h� 5 clientes cadastrados, o 6� ser� cadastrado na posi��o 5 do array. Pois o array come�a com a posi��o 0				
				cadastro_cliente(&array_de_clientes[qnt_de_clientes_cadastrados]);
				// Incrementa mais um cliente cadastrado
				qnt_de_clientes_cadastrados++;
			break;
			
			case 2:
				// Chama a funcao para alterar o cadastro do passageiro
				alterar_cliente (array_de_clientes, qnt_de_clientes_cadastrados);
			break;
			
			case 3:
				comprar_passagem();
			break;
			
			case 4:
				reembolso();
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
	
}


/*
BACKLOG DE FU��ES A IMPLEMENTAR
// Fun��o para imprimir menu - OK

// Fun��o para cadastrar o cliente - OK

// Fun��o para alterar o cadastro do cliente - OK

// Fun��o para adquirir passagem

// Fun��o para alterar passagem

// Fun��o para devolver passagem

// Fun��o para listar os passageiros

// Fun��o para listar os assentos 

// Fun��o para listar a qnt de assentos e o valor a pagar
*/


