/* Atividade III
AEDS 1
Aluno: Guilherme Mendes de Oliveira */

#include <stdio.h>
#include <math.h>


int ano;
int sim = 1;
int nao = 0;

int main () {

    scanf ("%d", &ano);

    if ((ano%4 == 0) && (ano%100 != 0) || (ano%400 == 0))
         printf ("%d", sim);

            else
            printf ("%d", nao);

return 0;


}
