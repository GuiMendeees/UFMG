/* Atividade III
AEDS 1
Aluno: Guilherme Mendes de Oliveira */

#include <stdio.h>
#include <math.h>



int main () {

float a;
float b;
float c;
float media;
float pot;
float raiz;
int menu;
float soma;
int d;
int e = 2;
int x;
int y;
int l1;
int l2;
int l3;
int triang;

/*  printf ("Selecione	a	op��o	desejada:\n");
    printf ("1) Calcula	o	valor	absoluto	da	m�dia	entre	3 numeros\n");
    printf ("2) Calcula	o	triplo	da	exponencial do primeiro n�mero\n");
    printf ("3) Calcula a	Raiz quadrada de um	n�mero, caso seja par ou eleva o n�mero ao quadrado	caso seja	impar\n");
    printf ("4) Calcula o resultado de a elevado a b se a soma de a e b	 for par ou	a elevado b, caso contr�rio\n");
    printf ("5) Verifica	se	tr�s	n�meros	correspondem	aos	lados	de	um	tri�ngulo ret�ngulo, retorna 1 se sim e 0 se nao\n"); */

    scanf ("%d", &menu);


    switch (menu) {

	case 1:

    scanf ( "%f %f %f", &a, &b, &c);
    soma = (a+b+c); (d = 3); media = (soma/d);
    printf("%f", media);

	break;

	case 2:

	scanf ("%f", &a);
    printf("%f", (3*exp(a)));

	break;

	case 3:

    scanf ("%d", &d);

    if (d%2 == 0)
        raiz = sqrt(d);

    else
        raiz = pow(d,2);
        printf("%f", raiz);

    break;

	case 4:

	scanf ("%d %d", &x, &y);

	if ((x+y)%2 == 0)
	    pot = pow(x,y);

	else
        pot = pow(y,x);
        printf ("%f", pot);
    break;

	case 5:

    scanf ("%d %d %d", &a, &b, &c);


    if ((l1 < l2 + l3) && (l1 > l2 - l3) )
        triang = 1 ;

    else if ((pow(l1,2)== (pow (l2,2)+ pow(l3,2)) || (pow (l2,2) == pow(l1,2)+pow(l3,2)) || (pow(l3,2) == pow(l1,2)+ pow(l2,2))))
        triang = 1 ;

    else
        triang = 0;

    printf("%d", triang);

	break;

	default:
	printf("Op��o inv�lida");
  }


return 0;

}
