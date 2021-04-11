#include <stdio.h>

int main(){
	char string[15];
	int i;
	
	printf("Digite a string: ");
	gets(string);
	
	for(i=0; i<15; i++){
		if(string[i] == '0'){
			string[i] = '1';
		}
	}
	
	printf("String: %s", string);
	
	return 0;
}