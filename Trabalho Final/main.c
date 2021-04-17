#include <stdio.h>
#include <locale.h>

// Struct para o cliente
typedef{
	int cpf;
	char nome[30];
}Cliente
// Struct para a passagem
typedef {
	int assento;
	Cliente passageiro;
}Passagem;


//inseri função para imprimir menu. danielbricio

void cadastropassageiro()
{
    printf("Bem-vindo ao sistema TheBus!\nDigite as informações desejadas para a efetuação do cadastro.\n");
}

void minhaconta()
{
    printf("Bem-vindo ao cadastro do cliente.\n");
}

void buypassagem()
{
    printf("Você acaba de solicitar a compra de passagem.\n por favor selecine a data e o assento desejado, em seguida listaremos os horarios disponiveis para o itinerário");
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
	
    int continuar=1;

    	printf("\tBem-vindo ao sistema TheBus\n");
    	printf("\t Escolha a opção desejada\n\n");
        
        printf("1. Cadastro de Passageiro\n");
        printf("2. Minha conta\n");
        printf("3. Comprar Passagens\n");
        printf("4. Solicitar Reembolso\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        

        switch(continuar)
        {
            case 1:
                cadastropassageiro();
                break;

            case 2:
                minhaconta();
                break;

            case 3:
                buypassagem();
                break;
                
			case 4:
                reembolso();
                break;
			
            case 0:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
}


/*
// Função para imprimir menu

// Função para cadastrar o cliente

// Função para alterar o cadastro do cliente

// Função para adquirir passagem

// Função para alterar passagem

// Função para devolver passagem

// Função para listar os passageiros

// Função para listar os assentos 

// Função para listar a qnt de assentos e o valor a pagar
*/

