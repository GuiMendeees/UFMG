/* Atividade II
AEDS I
Aluno: Guilherme Mendes de Oliveira */

#include <stdio.h>
#include <math.h>

int main () {

int valor; /* Input do Usuário*/
int a; /* Primeira divisão*/
int b; /* Achar o resto1*/
int c; /*Segunda divisão*/
int d;
int e;
int f;
int g;
int h;
int i;
int j;
int k;
int l;
int m;

    printf("Digite a quantia:");
    scanf("%d", &valor);
    a = (valor/100);
    b = (valor %100);
    c = (b/50);
    d = (b%50);
    e = (d/20);
    f = (d%20);
    g = (f/10);
    h = (f%10);
    i = (h/5);
    j = (h%5);
    k = (j/2);
    l = (j%2);
    m = (l/1);
		printf("%d", a+c+e+g+i+k+m);

return 0;

}
