#include <stdio.h>

void intervalo(int n1, int n2){
  for (int i=n1+1; i<n2; i++)
    printf("%d | ", i);

  for (int i=n1-1; i>n2; i--)
    printf("%d | ", i);
}

int main(){
  int n1, n2;

  printf("Digite o numero: ");
	scanf("%i", &n1);
  printf("Digite o numero: ");
	scanf("%i", &n2);

  intervalo(n1, n2);

  return 0;
}