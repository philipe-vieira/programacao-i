#include <stdio.h>
#include "funcoes.h"

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
	printf("6. Listar assentos adquiridos\n");
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
  printf("\tVoc� solicitou a op��o 'Comprar Passagens'.\n"
 		 "\t-------------------------------------------\n\n"
	"\tPor favor, selecione o hor�rio do embarque. \n\n");
	
	//Listando horarios de viagem dispon�veis
	printf("\t          Horarios Dispon�veis:\n\n"
	"\t     ---------------------------------\n"
	"\t     00h - 04h - 08h - 12h - 16h - 20h\n"
	"\t     ---------------------------------\n\n");
	// Lendo o horario da viagem
	printf("\n   Digite o hor�rio do embarque(Somente numeros)->");
	scanf("%d", &hora);
	//Convertendo a Hora para a posicao do array
	hora = hora/4;
	//Listando os assentos dispon�veis
	printf("\nAssentos disponiveis:\n");
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
  printf("   Voc� selecionou a op��o 'Solicitar Reembolso'\n\n");
  
	int hora, assento;
	
	printf("\t      Horarios Dispon�veis:\n"
	"\t---------------------------------\n"
	"\t00h - 04h - 08h - 12h - 16h - 20h\n"
	"\t---------------------------------");
	// Lendo o horario da viagem
	printf("\n   Digite o hor�rio do embarque(Somente numeros)->");
	scanf("%d", &hora);
	//Convertendo a Hora para a posicao do array
	hora = hora/4;
	//Listando os assentos dispon�veis
	printf("\nAssentos disponiveis:\n");
	printf("\n-----------------------------\n");
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
	printf("-----------------------------\n");
	
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


 void listar_assentos_ocupados(Passagem arrayPassagens[6][40]) 
{	
		for (int z=0; z< 6; z++)
		{
			printf("Itiner�rio de %.2d horas\n", z*4);
			for(int g = 0; g < 40 ; g++)
			{
				
				if (verificar_disponibilidade_assento(z, g+1, arrayPassagens) == 0)
				{
					printf("Assento: %i - CPF %i, NOME: %s \n", 
						arrayPassagens[z][g].assento, 
						arrayPassagens[z][g].passageiro.cpf, 
						arrayPassagens[z][g].passageiro.nome);
				}
			}	
		}
	
}


