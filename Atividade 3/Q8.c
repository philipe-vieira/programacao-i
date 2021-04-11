#include <stdio.h>

int main() {
    int num, fatorial = 1, i;
    
    printf("Digite um numero: ");
    scanf("%i", &num);

    for (i=num; i > 1; i--) {
      fatorial = fatorial * i;
    }

    printf("O fatorial deste numero é %i\n", fatorial);

    return 0;
}