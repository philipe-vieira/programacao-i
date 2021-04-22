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
/*
// Struct para o Itinerario/Viagem
typedef struct{
	Passagem passagem[30];
} Itinerario; 
*/
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
	printf("5. Listar passageiros cadastrados\n");
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

int verificar_disponibilidade_assento(
	int hora, 
	int assento,
	Passagem arrayPassagens[6][40])
{
	for(int i=0; i < 40; i++){
		//se o assento escolhido no hor�rio digitado n�o estiver dispon�vel
		//funcao retorna ZERO
		if(arrayPassagens[hora][i].assento==assento)
			return 0;
	}
	return 1;
}

void comprar_passagem(Passagem arrayPassagens[6][40], int qnt_passComp[], Passageiro arrayPassageiros[], int qnt_passageirosCad)
{
	int hora, assento, disponibilidade=1;
  printf("\tVoc� acaba de solicitar a compra de passagem.\n"
	"Por favor selecine o hor�rio desejado, "
	"em seguida listaremos os assentos disponiveis para o itiner�rio\n");
  /* provavelmente teremos que fazer um banco de dados com os horarios disponiveis?
	segunda a domingo, desses 7 dias, colocaremos 10 horarios por dias disponiveis?
	oq voc�s acham?  
	*/
	
	//Listando horarios de viagem dispon�veis
	//printf("Hor�rios de viagem dispon�veis");
	printf("00h - 04h - 08h - 12h - 16h - 20h");
	// Lendo o horario da viagem
	printf("\nDigite a hora da Viagem(Somente numeros)-> ");
	scanf("%d", &hora);
	//Convertendo a Hora para a posicao do array
	hora = hora/4;
	//Listando os assentos dispon�veis
	printf("Assentos disponiveis:\n");
	printf("--------------------\n");
	for(int i = 0; i < 4; i++ ){
		for (int j=i; j < 40; j=j+4){
			// Verifica cada assento daquele horario, se est� vazio
			// Se sim imprime o numero do assento
			if(verificar_disponibilidade_assento(hora, (j+1), arrayPassagens)){
				printf("%.2d ", j+1);
			}else { 
				// Senao imprime --
				printf("-- ");
			}
		}
		// Se i=1 imprime uma quebra de linha a mais para o corredor
		if(i == 1)
			printf("\n");
		printf("\n");
	}
	printf("--------------------\n");
	
	// Lendo o assento desejado
	printf("\nDigite o numero do assento -> ");
	scanf("%d", &assento);
	
	//verifica a disponibilidade do assento escolhido
	disponibilidade = verificar_disponibilidade_assento(hora, assento, arrayPassagens);
	
	// Se o assento estiver disponivel 
	if(disponibilidade){
		int cpf, indice = -1;
		
		// L� o cpf do passageiro a adquirir o assento
		printf("CPF-> ");
		scanf("%d", &cpf);
		//busca passageiro pelo cpf
		indice = buscarPassageiro(cpf, arrayPassageiros, qnt_passageirosCad);
		// Verifica se o passageiro n�o foi encontrado
		if(indice < 0){
			printf("Passageiro n�o cadastrado.\n");
			return;
		}
		
		// atribui os valores(passageiro e assento) a matriz passagem no hor�rio escolhido
		arrayPassagens[hora][assento-1].passageiro= arrayPassageiros[indice];
		arrayPassagens[hora][assento-1].assento= assento;
		// incrementa a quantidade de passagens compradas +1.
		qnt_passComp[hora]++;
		printf("\n\nPassagem adquirida com sucesso.\n");
		
	}else{
		printf("Assento indispon�vel.\n");
		return;
	}
}

void reembolso(
	Passageiro array_de_passageiros[100],
	int qnt_passageiros_cadastrados, 
	Passagem array_passagens[6][40], 
	int qnt_passagens_compradas[6])
{
  printf("Voc� acaba de solicitar o reembolso de passagem.\n por favor leia as regras.\n");
  
	int hora, assento;
	
	printf("\tHorarios Programados\n00h - 04h - 08h - 12h - 16h - 20h");
	// Lendo o horario da viagem
	printf("\nDigite a hora da Viagem(Somente numeros)-> ");
	scanf("%d", &hora);
	//Convertendo a Hora para a posicao do array
	hora = hora/4;
	//Listando os assentos dispon�veis
	printf("Assentos disponiveis:\n");
	printf("--------------------\n");
	for(int i = 0; i < 4; i++ ){
		for (int j=i; j < 40; j=j+4){
			// Verifica cada assento daquele horario, se est� OCUPADO
			// Se sim imprime o numero do assento
			if(!verificar_disponibilidade_assento(hora, (j+1), array_passagens)){
				printf("%.2d ", j+1);
			}else { 
				// Senao imprime --
				printf("-- ");
			}
		}
		// Se i=1 imprime uma quebra de linha a mais para o corredor
		if(i == 1)
			printf("\n");
		printf("\n");
	}
	printf("--------------------\n");
	
	// Lendo o assento desejado
	printf("\nDigite o numero do assento -> ");
	scanf("%d", &assento);
	
	//verifica a disponibilidade do assento escolhido
	int disponibilidade = verificar_disponibilidade_assento(hora, assento, array_passagens);
	
	// Se o assento estiver OCUPADO
	if(!disponibilidade){
		int cpf, indice = -1;
		Passageiro passageiro_vazio;
		
		// L� o cpf do passageiro a adquirir o assento
		printf("CPF-> ");
		scanf("%d", &cpf);
		//busca passageiro pelo cpf
		indice = buscarPassageiro(cpf, array_de_passageiros, qnt_passageiros_cadastrados);
		// Verifica se o passageiro n�o foi encontrado
		if(indice < 0){
			printf("Passageiro n�o cadastrado.\n");
			return;
		}
		
		if(array_passagens[hora][assento-1].passageiro.cpf != cpf){
			printf("Passageiro informado n�o � o proprietario deste ticket.\n");
			return;
		}
		
		// atribui os valores de um pasageiro vazio para aquela ocorrencia
		array_passagens[hora][assento-1].passageiro = passageiro_vazio;
		array_passagens[hora][assento-1].assento= 0;
		// decrementa a quantidade de passagens compradas -1.
		qnt_passagens_compradas[hora]--;
		printf("\n\nPassagem devolvida com sucesso.\n");
	}else{
		printf("Este assento ainda n�o foi adquirido.\n");
		return;
	}
}

void sair()
{
    printf("Voc� soliciou a op��o sair. agradecemos a utiliza��o do nosso sistema.\n");
}

void listar_passageiros(Passageiro array_de_passageiros[100], int qnt_de_passageiros_cadastrados){
	for(int i = 0; i < qnt_de_passageiros_cadastrados; i++){
		printf("CPF-%.11d | Nome: %s \n", array_de_passageiros[i].cpf, array_de_passageiros[i].nome);
	}
}

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

// Fun��o para alterar passagem 

// Fun��o para devolver passagem - OK

// Fun��o para listar os passageiros - 

// Fun��o para listar os assentos comprados

// Fun��o para listar a qnt de assentos e o valor a pagar
*/


