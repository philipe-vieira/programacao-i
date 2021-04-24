// Struct para o passageiro
typedef struct{
	int cpf;
	char nome[30];
} Passageiro;
// Struct para a passagem
typedef struct{
	int assento;
	Passageiro passageiro;
} Passagem;


// função que retorna o índice do passageiro no vetor, se encontrado.
int buscarPassageiro(int cpf, Passageiro arrayPassageiros[], int qnt_passageirosCad);

// Função para imprimir menu - OK
void imprimir_menu();

// Função para cadastrar o passageiro - OK
void cadastro_passageiro(Passageiro *passageiro);

// Funcao para alterar o cadastro do passageiro - OK
// Obs.: Os parametros nao precisam ser ponteiros pois não serao alterados aqui, mas sim na funcao cadastro_passageiro()
void alterar_passageiro (Passageiro array_de_passageiros[100], int qnt_de_passageiro);

int verificar_disponibilidade_assento(
	int hora, 
	int assento,
	Passagem arrayPassagens[6][40]);

void comprar_passagem(Passagem arrayPassagens[6][40], int qnt_passComp[], Passageiro arrayPassageiros[], int qnt_passageirosCad);

void reembolso(
	Passageiro array_de_passageiros[100],
	int qnt_passageiros_cadastrados, 
	Passagem array_passagens[6][40], 
	int qnt_passagens_compradas[6]);
	
void sair();

void listar_passageiros(Passageiro array_de_passageiros[100], int qnt_de_passageiros_cadastrados);

void listar_assentos_ocupados(Passagem arrayPassagens[6][40]);
