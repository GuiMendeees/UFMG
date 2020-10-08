/* 
Ler uma matriz 3x3
Fazer a transposta (Mb [i][j] = Ma[j][i])
B = A*A transposta */

#include <stdio.h>
#include <math.h>

int main (){

int Ma [3][3], Mat[3][3], Mb[3][3];
int i, j,k;
int valor = 0;


 for (i=0; i<3; i++){
    	
        for (j=0; j<3; j++)
            scanf ("%d", &Ma[i][j]);
      }

 for (i=0; i<3; i++){
    	
        for (j=0; j<3; j++)
        	Mat[i][j] = Ma[j][i];
      }

/*	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
		printf("%d\t", Ma[i][j]);
}
printf("\n");}  -----------------------> Matriz A Ok*/
	
/*	printf("\n \n"); Espaço entre entrada e visualização da depuracao 

	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
		printf("%d\t", Mat[i][j]);
}
printf("\n");} ------------------------> Matriz A transposta ok*/


		for(i=0; i<3; i++){

			for(j=0; j<3; j++){

				for(k=0; k<3; k++){
				valor += (Ma[i][k] * Mat[k][j]);
				//printf("O valor da Posição A%d%d é %d\n\n",i,k, Ma[i][k]);
				//printf("O valor da Posição At %d%d é %d\n",k,i, Mat[k][j]);
}
				Mb[i][j] = valor;
				valor = 0;
		}
	}
        	       	
   // printf("\n \n"); //Espaço entre entrada e visualização da depuracao 

	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
		printf("%d\t", Mb[i][j]);
}
printf("\n");} 

return 0;

}