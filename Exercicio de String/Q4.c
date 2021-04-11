#include <stdio.h>

int main(){
	char string[15];
	
	printf("Digite a string: ");
	scanf("%s", string);

	for(int i = 0; i < 15; i++){
    if(string[i] >= 65 && string[i] <= 90){
      string[i] = string[i] + 32;
    }
  }

  printf("String: %s\n", string);
	
	return 0;
}