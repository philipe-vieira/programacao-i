#include <stdio.h>

int main(){
  int n = 5;
  int a = 0;

  for (int b = 1; b <= n; b++){
    for (int c = b; c <= n; c++){
      a = a +1;
    }
  }

  printf("%d", a);
  return 0;
}