#include <stdio.h>

int main(){
  int n, a = 0, b = 0;

  scanf("%d", &n);

  while( n > 0){
    if ((n % 2) == 0){
      a = a + 1;
    } else {
      b = b + 1;
    }
    n = n / 2;
  }
  printf("%d %d\n", a, b);
  return 0;
}