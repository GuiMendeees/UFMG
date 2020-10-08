/* Atividade III
AEDS 1
Aluno: Guilherme Mendes de Oliveira */

#include <stdio.h>
#include <math.h>

int main () {

int valor1;
int valor2;
int par = 1;
int impar = 0;
int positivo = 1;
int neutro = 0;
int negativo = -1;
int soma;
int diferenca;

	scanf ("%d", &valor1);
	scanf ("%d", &valor2);

	soma = valor1 + valor2;
	diferenca = valor1 - valor2;

		if (soma%2 == 0 && diferenca > 0)
		printf ("%d , %d", par, positivo);

        else if (diferenca == 0)
		printf ("%d , %d", par, neutro);

		else if (diferenca < 0)
		printf ("%d , %d", par, negativo);

        else if (soma%2 == 1 && diferenca > 0)
		printf ("%d , %d", impar, positivo);

		else if (diferenca == 0)
		printf ("%d , %d", impar, neutro);

		else if (diferenca < 0)
		printf ("%d , %d", impar, negativo);

return 0;

}
