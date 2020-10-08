/* Atividade IV - Guilherme Mendes de Oliveira - AEDs 1 */

#include <stdio.h>
#include <math.h>


int main () {

int a1, r, n;

    /* Digite o primeiro termo, a razao e a quantidade de numeros */

    scanf(" %d %d %d", &a1, &r, &n);

    while (n!=0) {
        printf ("%d\n", a1);
        a1 += r;
        n --;
}

    return 0;


}
