#include <stdio.h>

int main(){
  int var_int;
  float var_float;
  char var_char;
  int *pont_int;
  float *pont_float;
  char *pont_char;

  var_int = 10;
  var_float = 10.5;
  var_char = 'a';

  pont_int = &var_int;
  pont_float = &var_float;
  pont_char = &var_char;

  printf("Variavel int %i\n", var_int);
  printf("Variavel float %f\n", var_float);
  printf("Variavel char %c\n\n\n", var_char);

  *pont_int = 20;
  *pont_float = 20.77;
  *pont_char = 'b';

  printf("Variavel int %i\n", var_int);
  printf("Variavel float %f\n", var_float);
  printf("Variavel char %c\n\n\n", var_char);

  return 0;
}