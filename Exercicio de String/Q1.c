#include <stdio.h>

int main(){
	char string[15], carac;
	
	printf("Digite a string: ");
	gets(string);
	printf("Digite o caractere: ");
	scanf("%c", &carac);
	
	if(string[0] == carac){
		printf("String: %s", string);
	}
	
	
	return 0;
}