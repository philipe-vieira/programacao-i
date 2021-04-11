#include <stdio.h>

int main(){
    int i;

    for (i = 0; i <= 10; i++) {
      printf("|  %02d + 4 = %02d  |   %02d - 4 = %02d  |   %02d * 4 = %02d  |   %02d / 4 = %02d  \n",
        i, i + 4,
        i + 4, i,
        i, i * 4,
        i * 4, i 
      );
    }

    return 0;
}