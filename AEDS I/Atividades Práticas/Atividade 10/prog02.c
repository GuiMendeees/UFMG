#include <stdio.h>
#include <stdlib.h>



int menor(int v[], int n){

int aux;

	if (n==1)
		return v[0];
	
	else {
		aux = menor (v, n-1);

		if (v[n-1]<aux)
			return v[n-1];

		return aux;
	}

}


int main(){

	int n,i;
	int *v;
	int num;


		scanf("%d", &n);
	
	
	v = malloc(n * sizeof (int));
	int p = n-1;
	    

		for (i=0; i<n-1; i++){
			scanf("%d", &v[i]);
			
		}

		num = menor (v, p);

		printf("%d\n",num);


return 0;
}