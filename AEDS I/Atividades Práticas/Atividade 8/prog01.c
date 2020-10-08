
// Guilherme Mendes de Oliveira - AEDS I

#include <stdlib.h>
#include <stdio.h>



int main(){

int n;
int i,j;
	
	printf("Digite um valor:");
	scanf ("%d", &n);
	
float **Matriz; // Ponteiro de Ponteiro

	Matriz = (float**)malloc(n * sizeof(float*)); // Malloc no Vetor de Ponteiro


		for(i = 0; i < n; i++){
			Matriz[i] = (float*)malloc(n * sizeof(float)); // Alocando a linha que será um ponteiro pois ela representa um vetor Matriz [i]
// Laço for para preencher a Matriz
				for(j = 0; j < n; j++){
					Matriz[i][j] = 0;
				}
			}

	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", Matriz[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < n; i++){
		free(Matriz[i]);
	}

free(Matriz);

	return 0;
}