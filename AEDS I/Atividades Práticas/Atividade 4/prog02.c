/* Atividade IV - Guilherme Mendes de Oliveira - AEDS1 */

#include <stdio.h>
#include <math.h>

int main (){

int a; /* Entrada do usuáario*/
int b; /* Entrada do usuario*/
int r ; /* Imprimir raiz exata*/
int raiz1; /* Da a raiz em Inteiro */
float raiz2; /* Raiz em Float */


    scanf ("%d %d", &a, &b);

        for (a;a<=b; a ++){

            raiz1= sqrt(a);
            raiz2 = sqrt(a);

            if (raiz1 == raiz2)
                printf ("%d\n", a);
                }


    return 0;


}
