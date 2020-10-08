/* Atividade IV - Guilherme Mendes de Oliveira - AEDS I */

/* Input do usuario - While para controlar o numero negativo*/
/* for para contar divisores */
/* If mais de dois divisores primo ++ */
/* printf primos */

#include <stdio.h>

int main (){

int n; /* Input do user */
int cont; /* conta divisores */
int primo = 0; /* Conta Primos */
int i; /* Variavel que testa os divisores */


    while (n >= 0) {

        scanf ("%d", &n);
        cont = 0;

        for (i=1; i<=n; i++){

            if ((n % i) == 0) /* Se for divisor*/

            cont ++; /* +1 Divisor*/

        }

        if (cont == 2) /* Se so houver 2 divisores */
            primo ++;}

        printf("Foram identificados %d numeros primos",primo);

    return 0;

}
