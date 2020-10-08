/* Atividade IV - Guilherme Mendes de Oliveira */

#include <stdio.h>
#include<math.h>

int main () {


int n;
int r;
int a;
int x;
int y;
int fat1 = 1;
int fat2 = 1;
int arranjo;

    scanf("%d %d", &n, &r);
        a = n-r;

    if (n <= 0){
        printf ("n invalido!");}

    else if (r <= 0){
        printf ("r invalido!");}

    else if (r>n){
        printf ("r nao pode ser maior que n!");}

    else {

        for (x=1; x<n; n -- ){
        fat1 = fat1*n;}

        for (y = 1; y<a ; a --){
        fat2 = fat2 * a;}

    arranjo = (fat1/fat2);
    printf ("%d", arranjo);}


    return 0;
}
