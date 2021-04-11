#include <stdio.h>

int main(){
  int a, b;

  scanf("%d", &a);
  scanf("%d", &b);

  while ( a > 0 && b > 0){
    if (a > b){
      a = a - b;
    } else {
      b = b - a;
    }
  }

  printf("%d\n", a+b);
  return 0;
}