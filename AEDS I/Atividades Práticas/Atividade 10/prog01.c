#include <stdio.h>
#include <stdlib.h>



float somatorio (int n){
	float soma = 0;
	float i = 1;

	if (n==i)
		return ((float)n/(1+(float)n));

	soma = ((float)n/(1+(float)n)) + somatorio (n-1);

	return soma;

}


int main (){

	int n;
	float soma;
	

	scanf ("%d", &n);


	soma = somatorio (n);

	printf("%.2f\n", soma);

return 0;

}