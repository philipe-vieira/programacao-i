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

// Função para imprimir menu - OK
void imprimir_menu(){
	printf("\t Escolha a opção desejada\n\n");
	printf("1. Cadastro de Passageiro\n");
	printf("2. Alterar cadastro do Passageiro\n");
	printf("3. Comprar Passagens\n");
	printf("4. Solicitar Reembolso\n");
	printf("0. Sair\n");
}

// Função para cadastrar o cliente - OK
void cadastro_cliente(Cliente *cliente)
{
  printf("Bem-vindo ao sistema TheBus!\nDigite as informações desejadas para a efetuação do cadastro.\n");
  
  // Lendo o CPF do cliente
  printf("CPF -> ");
  scanf("%i", &cliente->cpf);

	// Lendo o nome do cliente
  printf("Nome -> ");
  scanf("%s", cliente->nome);
}

// Funcao para alterar o cadastro do cliente - OK
// Obs.: Os parametros nao precisam ser ponteiros pois não serao alterados aqui, mas sim na funcao cadastro_cliente()
void alterar_cliente (Cliente array_de_clientes[100], int qnt_de_clientes)
{
	// Sessao p/ declaração de variaveis
	int cpf, posicao_no_array=-1;
	
	// Lendo o cpf a ser alterado
	printf("Digite o cpf do cliente a ser alterado -> ");
  scanf("%i", &cpf);
  
  // Procurando a posicao do array que aquele cpf se encontra
  // Obs.: i < qnt_de_clientes -> para não procurar nas posicoes ainda vazias
  for(int i=0; i < qnt_de_clientes; i++){
    if(array_de_clientes[i].cpf == cpf)
      posicao_no_array = i;
  }
  
  // Se a posição do array ainda é o valor iniciado,
  // Então o cpf do cliente nao foi encontrado
  if (posicao_no_array == -1){
  	printf("O CPF do cliente não foi encontrado\n");
  	// RETURN para para a função alterar_cliente
    return;
	}
	
	// Se o cpf foi encontrado no array, executa o cadastro novamente
	cadastro_cliente(&array_de_clientes[posicao_no_array]);	
}

/* Acredito que essa função não será necessária. By Philipe
void minhaconta()
{
    printf("Bem-vindo ao cadastro do cliente.\n");
}
*/

void comprar_passagem()
{
    printf("Você acaba de solicitar a compra de passagem.\n"
		" Por favor selecine a data e o assento desejado, "
		"em seguida listaremos os horarios disponiveis para o itinerário");
    /* provavelmente teremos que fazer um banco de dados com os horarios disponiveis?
	segunda a domingo, desses 7 dias, colocaremos 10 horarios por dias disponiveis?
	oq vocês acham?  
	*/
}

void reembolso()
{
    printf("Você acaba de solicitar o reembolso de passagem.\n por favor leia as regras.\n");
}

void sair()
{
    printf("Você soliciou a opção sair. agradecemos a utilização do nosso sistema.\n");
}


int main()
{
	setlocale(LC_ALL, "portuguese_brazil");
	
	// Seção de declaração de variaveis globais
	int continuar=1;
	int qnt_de_clientes_cadastrados = 0;
	Cliente array_de_clientes[100];
	
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
				// 1. Chama a função que cadastra um cliente
				// 2. Passa, por parametro uma posição do array de clientes
				// 3. A posição do array corresponde a quantidade de clientes cadastrado anteriormente
				// Ex.: Se há 5 clientes cadastrados, o 6° será cadastrado na posição 5 do array. Pois o array começa com a posição 0				
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
	
}


/*
BACKLOG DE FUÇÕES A IMPLEMENTAR
// Função para imprimir menu - OK

// Função para cadastrar o cliente - OK

// Função para alterar o cadastro do cliente - OK

// Função para adquirir passagem

// Função para alterar passagem

// Função para devolver passagem

// Função para listar os passageiros

// Função para listar os assentos 

// Função para listar a qnt de assentos e o valor a pagar
*/


