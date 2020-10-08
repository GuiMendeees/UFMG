#include <stdio.h>
#include <stdlib.h>


void imprimirPA(int r, int x, int n){
//N - Quantidade de Numeros
//X - Numero inicial
//R - Razão de incremento

int pa_elemento=x+((n-1)*r);

	if (n==1)
		printf("%d\n",pa_elemento);

	

	imprimirPA (r,x,(n-1));

	
}



int main (){


int r,x,n;

	scanf ("%d %d %d", &r, &x, &n);


	imprimirPA (r,x,n);


return 0;

}