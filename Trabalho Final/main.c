#include <stdio.h>
#include <locale.h>

// Struct para o passageiro
typedef struct{
	int cpf;
	char nome[30];
}Passageiro;
// Struct para a passagem
typedef struct{
	int assento;
	Passageiro passageiro;
} Passagem;
// Struct para o Itinerario/Viagem
typedef struct{
	Passagem passagem[30];
} Itinerario; 

// fun��o que retorna o �ndice do passageiro no vetor, se encontrado.
int buscarPassageiro(int cpf, Passageiro arrayPassageiros[], int qnt_passageirosCad){
	int i;
	for(i=0; i<qnt_passageirosCad; i++){
		if(arrayPassageiros[i].cpf==cpf)
			return i;
	}
	return -1;
}

// Fun��o para imprimir menu - OK
void imprimir_menu(){
	printf("\t Escolha a op��o desejada\n\n");
	printf("1. Cadastro de Passageiro\n");
	printf("2. Alterar cadastro do Passageiro\n");
	printf("3. Comprar Passagens\n");
	printf("4. Solicitar Reembolso\n");
	printf("0. Sair\n");
}

// Fun��o para cadastrar o passageiro - OK
void cadastro_passageiro(Passageiro *passageiro)
{
  printf("Bem-vindo ao sistema TheBus!\nDigite as informa��es desejadas para a efetua��o do cadastro.\n");
  
  // Lendo o CPF do passageiro
  printf("CPF -> ");
  scanf("%i", &passageiro->cpf);

	// Lendo o nome do passageiro
  printf("Nome -> ");
  scanf("%s", passageiro->nome);
}

// Funcao para alterar o cadastro do passageiro - OK
// Obs.: Os parametros nao precisam ser ponteiros pois n�o serao alterados aqui, mas sim na funcao cadastro_passageiro()
void alterar_passageiro (Passageiro array_de_passageiros[100], int qnt_de_passageiro)
{
	// Sessao p/ declara��o de variaveis
	int cpf, posicao_no_array=-1;
	
	// Lendo o cpf a ser alterado
	printf("Digite o cpf do passageiro a ser alterado -> ");
  scanf("%i", &cpf);
  
  // Procurando a posicao do array que aquele cpf se encontra
  // Obs.: i < qnt_de_passageiro -> para n�o procurar nas posicoes ainda vazias
  for(int i=0; i < qnt_de_passageiro; i++){
    if(array_de_passageiros[i].cpf == cpf)
      posicao_no_array = i;
  }
  
  // Se a posi��o do array ainda � o valor iniciado,
  // Ent�o o cpf do passageiro nao foi encontrado
  if (posicao_no_array == -1){
  	printf("O CPF do passageiro n�o foi encontrado\n");
  	// RETURN para para a fun��o alterar_passageiro
    return;
	}
	
	// Se o cpf foi encontrado no array, executa o cadastro novamente
	cadastro_passageiro(&array_de_passageiros[posicao_no_array]);	
}

void comprar_passagem(Passagem arrayPassagens[6][30], int qnt_passComp[], Passageiro arrayPassageiros[], int qnt_passageirosCad)
{
	int hora, assento, cpf, indice, disponibilidade=1;
  printf("Voc� acaba de solicitar a compra de passagem.\n"
	"Por favor selecine o hor�rio e o assento desejado, "
	"em seguida listaremos os horarios disponiveis para o itiner�rio\n");
  /* provavelmente teremos que fazer um banco de dados com os horarios disponiveis?
	segunda a domingo, desses 7 dias, colocaremos 10 horarios por dias disponiveis?
	oq voc�s acham?  
	*/
	
	for(int i = 0; i < 4; i++ ){
		for (int j=i; j < 40; j=j+4){
			printf("%2d ", j+1);
		}
		if(i == 1)
			printf("\n");
		printf("\n");
	}
	
	printf("\nHora-> ");//l� a hora da viagem
	scanf("%d", &hora);
	printf("Assento-> ");
	scanf("%d", &assento);
	
	//verifica a disponibilidade do assento, n�o tenho certeza se est� funcionando.
	for(int i=0; i<qnt_passComp[hora]; i++){
		//se o assento escolhido no hor�rio digitado n�o estiver dispon�vel
		//disponibilidade recebe zero
		if(arrayPassagens[hora][qnt_passComp[hora]].assento==assento)
			disponibilidade=0;
	}
	
	if(disponibilidade){
		printf("CPF-> ");
		scanf("%d", &cpf);
		indice= buscarPassageiro(cpf, arrayPassageiros, qnt_passageirosCad);//busca passageiro pelo cpf
		if(indice!=-1){
			// atribui os valores(passageiro e assento) a matriz passagem no hor�rio escolhido
			arrayPassagens[hora][qnt_passComp[hora]].passageiro= arrayPassageiros[indice];
			arrayPassagens[hora][qnt_passComp[hora]].assento= assento;
			qnt_passComp[hora]++;// incrementa a quantidade de passagens.
		}else{
			printf("Passageiro n�o cadastrado.\n");
		}
	}else{
		printf("Assento indispon�vel.\n");
	}
}

void reembolso()
{
    printf("Voc� acaba de solicitar o reembolso de passagem.\n por favor leia as regras.\n");
}

void sair()
{
    printf("Voc� soliciou a op��o sair. agradecemos a utiliza��o do nosso sistema.\n");
}


int main(){
	setlocale(LC_ALL, "portuguese_brazil");
	
	// Se��o de declara��o de variaveis globais
	int continuar=1;
	int qnt_de_passageiros_cadastrados = 0;
	Passageiro array_de_passageiros[100];
	
	// quantidade de passagens compradas por hor�rio
	int qnt_passagensCompradas[6];
	// zerar quantidade de passagens compradas, nos 6 h�rarios disp�niveis
	for(int i=0; i<6; i++){
		qnt_passagensCompradas[i]=0;
	}
	
	Passagem arrayPassagens[6][30];
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
				comprar_passagem(arrayPassagens, qnt_passagensCompradas, array_de_passageiros, qnt_de_passageiros_cadastrados);
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

// Fun��o para cadastrar o passageiro - OK

// Fun��o para alterar o cadastro do passageiro - OK

// Fun��o para adquirir passagem

// Fun��o para alterar passagem

// Fun��o para devolver passagem

// Fun��o para listar os passageiros

// Fun��o para listar os assentos 

// Fun��o para listar a qnt de assentos e o valor a pagar
*/


