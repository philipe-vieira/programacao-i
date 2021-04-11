#include <stdio.h>

int main(){
    int num, i;
    printf("Digite umm numero");
    scanf("%i", &num);

    for (i = 1; i <= num; i++){
        if ((num % i) == 0) {
            printf("%i ", i);
        }
    }

    printf("\n")

    return 0;
}