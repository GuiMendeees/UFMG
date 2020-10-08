/* Usuario insere 10 numeros
calcula a media
calcula o desvio padrao a soma de dtodos os termos (termo - media) ao quadrado */


#include <stdio.h>
#include <math.h>


int main () {

float media;
int i;
int j;
float dp;
float smedia = 0;
float somatorio;
int numeros[11];

	for (i=0; i<10; i++){
		scanf("%d", &numeros[i]);
		smedia = smedia+numeros[i];
		media = smedia/10;
		// printf ("%d\n", numeros[i]); Verificar Input
		}

	for (j=0; j<10; j++){
		somatorio +=  pow (((float)numeros[j]-media),2);
		dp = sqrt(((float)somatorio/9));}

		printf("Media: %.2f\n", media);
		printf ("Desvio Padrao: %.2f\n", dp);
		//printf("% termo - media ao quadrado eh %f", somatorio);


	//printf("%f", media);


return 0;




}
