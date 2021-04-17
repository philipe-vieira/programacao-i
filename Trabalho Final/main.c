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


//inseri fun��o para imprimir menu. danielbricio

void cadastropassageiro()
{
    printf("Bem-vindo ao sistema TheBus!\nDigite as informa��es desejadas para a efetua��o do cadastro.\n");
}

void minhaconta()
{
    printf("Bem-vindo ao cadastro do cliente.\n");
}

void buypassagem()
{
    printf("Voc� acaba de solicitar a compra de passagem.\n por favor selecine a data e o assento desejado, em seguida listaremos os horarios disponiveis para o itiner�rio");
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
	
    int continuar=1;

    	printf("\tBem-vindo ao sistema TheBus\n");
    	printf("\t Escolha a op��o desejada\n\n");
        
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
// Fun��o para imprimir menu

// Fun��o para cadastrar o cliente

// Fun��o para alterar o cadastro do cliente

// Fun��o para adquirir passagem

// Fun��o para alterar passagem

// Fun��o para devolver passagem

// Fun��o para listar os passageiros

// Fun��o para listar os assentos 

// Fun��o para listar a qnt de assentos e o valor a pagar
*/

