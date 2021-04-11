#include <stdio.h>

int main(){
	char string[15], contra[15];
	int indice = 0;
	
	printf("Digite a string: ");
	gets(string);

	for(int j=15; j>=0; j--){
		if(string[j] != '\0' && string[j] != '.'){
				contra[indice] = string[j];
				indice++;
		}
	}
	
	printf("String inversa: %s", contra);
	
	return 0;
}