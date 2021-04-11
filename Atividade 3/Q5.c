#include <stdio.h>

int main(){
    float num1, num2;
    int operacao;

		printf("Digite 2 numeros: ");
    scanf("%f %f", &num1, &num2);
    
    printf("Opção 1 - somar; 2 - subtrair; 3 - multiplicar; 4 -  dividir: ");
    scanf("%i", &operacao);

		switch(operacao){
			case 1:
				printf("Resultado = %.2f\n", num1 + num2);
			break; 
			case 2:
				printf("Resultado = %.2f\n", num1 - num2);
			break;
			case 3:
				printf("Resultado = %.2f\n", num1 * num2);
			break;
			case 4:
				printf("Resultado = %.2f\n", num1 / num2);
			break;
			default:
				printf("Opção inválida");
			break;
		}

    return 0;
}