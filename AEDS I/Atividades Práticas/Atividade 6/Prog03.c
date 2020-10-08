#include <stdio.h>


int obter_conceito (int n1, int n2, int n3, int n4, char *conceito);
{

	if ((n1 < 0 || n1 >100) || (n2 < 0 || n2 >100) || (n3 < 0 || n3 >100) || (n4 < 0 || n4 >100))
		printf("Nota invalida!\n!");
	//	return 0;

	else {

		if (((n1+n2+n3+n4)/4) > 90 && ((n1+n2+n3+n4)/4) < 100)
			conceito = 'A';

		else if (((n1+n2+n3+n4)/4) > 80 && ((n1+n2+n3+n4)/4) < 90)
			conceito = 'B';

		else if (((n1+n2+n3+n4)/4) > 70 && ((n1+n2+n3+n4)/4) < 80)
			conceito = 'C';

		else if (((n1+n2+n3+n4)/4) > 50 && ((n1+n2+n3+n4)/4) < 70)
			conceito = 'D';

		else if (((n1+n2+n3+n4)/4) > 40 && ((n1+n2+n3+n4)/4) < 50)
			conceito = 'E';

		else (((n1+n2+n3+n4)/4) > 0 && ((n1+n2+n3+n4)/4) < 40)
			conceito = 'F'

	}


}



int main (){

int n1,n2,n3,n4;
char *conceito;

	scanf ("%d %d %d %d", &n1, &n2 ,&n3 ,&n4);
	obter_conceito (n1,n2,n3,n4);
	printf("%s\n", conceito);

return 0;


}