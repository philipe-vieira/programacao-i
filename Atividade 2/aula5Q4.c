#include <stdio.h>
#include <math.h>

int main(){
  int a, b, c, delta;
  float raiz1, raiz2;

  printf("Digite os 3 numeros da raiz... ");
  scanf("%i %i %i", &a, &b, &c);

  delta = (b*b)-(4*a*c);
  raiz1 = (-b + sqrt(delta))/(2*a);
  raiz2 = (-b - sqrt(delta))/(2*a);
 

  if (delta < 0){
    printf("Não existe raízes no conjunto dos reais. \n");
  }  else  if (delta > 0){
    printf("As raízes são = %f e %0.2f\n", raiz1, raiz2);
  } else if (delta == 0){
    printf("A função tem apenas a raiz %0.2f\n", raiz2);
  }
  return 0;
}