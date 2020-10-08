/* Guilherme Mendes de Oliveira - AEDS I */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define BUFFER_TAM 5

int main (){



char *texto;
char *textoaux;
char c;
char buffer[BUFFER_TAM];
int cont;
int tamanhotexto;
int i;
int aux;
	
	//Enquanto nao digitar # e nao atingir o limite do Buffer ele pega o caracter
	while (c =! '#' && aux < BUFFER_TAM){
	
	
		for (cont =0; cont <BUFFER_TAM; cont ++){
			c = getch();
			// Quebra de Linha quando der Enter
			if (c == '\r'){
			c ='\n';
			printf("\n");
			}

		// Digitou # para
		if (c =='#'){
			break;
			}

		//Armazena no vetor buffer
		buffer[cont] = c;
		aux++;

		}
	//Aloca o espaço de acordo com o laço
	texto = (char*) malloc (cont * sizeof (char));
	//O ponteiro criado na Alocação recebe o conteudo do vetor buffer
	texto = buffer;

	}

	// Enquanto o caracter # não aparecer no getch
	while (c != '#'){

		for (cont =0; cont <BUFFER_TAM; cont ++){
			c = getch();

			if (c == '\r'){
				c ='\n';
				printf("\n");
			}

			if (c =='#'){
				break;
			}

		buffer[cont] = c;

		}

	// Armazena o tamanho do texto para ALocar no auxiliar
	tamanhotexto = strlen(texto);

	textoaux = (char*) malloc (BUFFER_TAM*sizeof (char) + tamanhotexto * sizeof (char));

	
		//Copia do vetor alocado para o auxiliar
		for (i = 0; i < tamanhotexto; i++){
		textoaux[i] = texto[i];
		}

		// Recebe a outra entrada armazenada (2ª Alocação e adiante)
		for (i = (tamanhotexto); i <(tamanhotexto+BUFFER_TAM); i++){
		textoaux[i] = buffer[i];
		}

	// Verifica o tamanho do vetor de texto auxiliar
	tamanhotexto = strlen (textoaux);
	// Aloca a quantidade de posições que tem o auxiliar
	texto = (char*) malloc (tamanhotexto * sizeof (char));
	// Recebe o auxiliar
	texto = textoaux;
	}

	printf("%s", texto);
	free (textoaux);
	free (texto);

return 0;

}