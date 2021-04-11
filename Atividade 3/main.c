/* Questão 1 */
#include <stdio.h>


int main(){

    int number;
    char tr_number[10][6] = {
            "um", "dois", "tres",
            "quatro", "cinco", "seis",
            "sete", "oito", "nove", "dez"
    };

    scanf("%i", &number);
    if (number > 0 && number <= 10) {
        printf("%s" , tr_number[number - 1]);
    }
    else {
        printf("Numero invalido");
    }

    return 0;
}

/* Questão 2 */
#include <stdio.h>


int main(){

    int number_1, number_2;
    scanf("%i %i", &number_1, &number_2);

    if (number_1 % number_2 == 0) {
        printf("X e divisivel por Y!");
    } else {
        printf("X nao e divisivel por Y!");
    }

    return 0;
}

/* Questão 3 */
#include <stdio.h>


int main(){

    int number;
    scanf("%i", &number);

    switch (number)
    {
        case 1:
            printf("Incluido");
            break;

        case 2:
            printf("Deletado");
            break;

        case 3:
            printf("Logoff");
            break;

        default:
            printf("Opcao invalida");
    }

    return 0;
}

/* Questao 4 */
#include <stdio.h>


int main(){

    int mes;
    char calendario[12][10] = {
            "janeiro", "fevereiro", "marco",
            "abril", "maio", "junho", "julho",
             "agosto", "setembro", "outubro",
             "novembro", "dezembro"
    };

    scanf("%i", &mes);
    if (mes >= 1 && mes <= 12) {
        printf("%s" , calendario[mes - 1]);
    }
    else {
        printf("Mes Invalido");
    }

    return 0;
}

/* Questao 5 */
#include <stdio.h>


int main(){

    float number_1, number_2;
    int var_operator;

    scanf("%f %f", &number_1, &number_2);

    float results[4] = {
            (number_1 + number_2),
            (number_1 - number_2),
            (number_1 * number_2),
            (number_1 / number_2)
    };

    printf("digite: \n"
           "1 - para ( + ) somar \n"
           "2 - para ( - ) subtrair \n"
           "3 - para ( * ) multiplicar \n"
           "4 - para ( / ) dividir \n"
    );
    scanf("%i", &var_operator);

    printf("%.2f", results[var_operator - 1]);

    return 0;
}

/* Questao 6 */
#include <stdio.h>


int main(){

    int number, count;
    scanf("%i", &number);

    for (count = 1; count <= number; count++){
        if ((number % count) == 0) {
            printf("%i ", count);
        }
    }

    return 0;
}

/* Questao 8 */
#include <stdio.h>


int main() {

    int number, fatorial, count;
    scanf("%i", &number);

    fatorial = 1;

    for (count=1; count < number; count++) {
        fatorial += fatorial * count;
    }

    printf("%i", fatorial);

    return 0;
}

/* Questao 9 */
#include <stdio.h>


int main(){

    float count;

    for (count = 0; count <= 10; count++) {

        float line[] = {(count + 4), (count - 4), (count * 4), ((count * 4) / 4)};
        printf("|  %.0f + 4 = %.0f  ", count, line[0]);
        printf("|   %.0f - 4 = %.0f  ", count, line[1]);
        printf("|   %.0f * 4 = %.0f  ", count, line[2]);
        printf("|   %.0f / 4 = %.0f  \n", count * 4, line[3]);
    }

    return 0;
}

/* Questao 10 */
#include <stdio.h>


int main(){

    while (1){
        int number;
        scanf("%i", &number);

        char options[4][10] = {"Cadastrar", "Alterar", "Excluir", "Sair"};

        if (number >= 1 && number <= 3) {
        printf("Opcao %s escolhida \n", options[number - 1]);
        } else if (number == 4){
            printf("Opcao %s escolhida", options[number - 1]);
            return 0;

        } else (printf("Opcao invalida \n"));
    }
}

/* Questao 11 */
#include <stdio.h>


int main(){

    int quantidade_alunos = 3;

    while (quantidade_alunos) {
        float nota_1, nota_2, media_ponderada;
        scanf("%f %f", &nota_1, &nota_2);

        media_ponderada = (nota_1 + (nota_2 * 2)) / 3;
        printf("%f \n", media_ponderada);

        quantidade_alunos--;
    }

    return 0;
}

/* Questao 12 */
#include <stdio.h>
#include <string.h>


int main(){

    char restam_alunos[] = "sim";

    while (!strcmp(restam_alunos, "sim")) {
        float nota_1, nota_2, media_ponderada;
        scanf("%f %f", &nota_1, &nota_2);

        media_ponderada = (nota_1 + (nota_2 * 2)) / 3;
        printf("%f \n", media_ponderada);

        printf("Restam alunos a serem avaliados? (sim our nao) \n");
        scanf("%s", &restam_alunos);
    }

    return 0;
}

/* Questao 13 */
#include <stdio.h>


int main(){

}
