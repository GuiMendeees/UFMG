#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct iris {
	float Cs //comprimento_sepala;
	float Ls //largura_sepala;
	float Cp //comprimento_petala;
	float Lp //largura_petala;
	char Str[51];

} Iris;

void ArmazenaIris(Iris ir[], int n){
	
	int i;

	for (i=0;i<n;i++){
		scanf ("%f",&ir[i].Cs);
		scanf ("%f",&ir[i].Ls);
		scanf ("%f",&ir[i].Cp);
		scanf ("%f",&ir[i].Lp);
		scanf ("%s",ir[i].str);

	}

}




int main (){
	
int n;

int i;
float cs,ls,cp,lp;
char str

	scanf ("%d", &n); // Quantidade de Eventos

Iris ir[n];

}