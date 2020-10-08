/* Atividade III
AEDS 1
Aluno: Guilherme Mendes de Oliveira */

#include <stdio.h>
#include <math.h>

int x, y, z, max, min, dentro, fora, div, menu;

int main () {

    scanf (" %d %d %d", &x, &y, &z);

/* Maior numero */

    if ( x > y && x > z)
        max = x;
    else if (x < y && y > z)
        max = y;
    else if (x < z && y < z)
        max = z;
    else if (x == y && x == z )
        max = x;

/* Menor numero */

    if ( x < y && x < z)
        min = x;
    else if (x > y && y < z)
        min = y;
    else if (x > y && y > z)
        min = z;
    else if (x == y && x == z)
        min = x;

/* Dentro e fora */

    if (x == y == z)

        {dentro = 1;
        fora = 0;}

    else if ((y < x) && (x < z))
        {dentro = 1;
        fora = 0;}

    else
        {dentro = 0;
        fora = 1;}


/* Divisibilidade */

     if ((x == 0) || (y == 0) || (z == 0))
        { div = 0; }

     else if ((x % y == 0) && (x % z == 0) || ( x==y==z))
           { div = 1;}

     else
           { div = 0;}

    scanf ("%d", &menu);

	switch (menu) {

	case 1:
	printf("%d", max);
	break;

	case 2:
	printf("%d", min);
	break;

	case 3:
    printf("%d", dentro);
    break;

	case 4:
	printf("%d", fora);
	break;

	case 5:
	printf("%d", div);
	break;

	default:
	printf("Opção inválida");
  }

return 0;

}
