/* Palíndromo

Usuário insere a palavra
Ler a palavra até o \0 e armazena-la
Inverter a String
Comparar as palavras
Duas strings o primeiro caracter da segunda tem que ser igual ao da primeira
Se for igual retorna Palindromo, se for falso Nao e palindromo

 */

#include <stdio.h>
#include <string.h>


int main () {

int i;
int tamanho = 0;
int j;
int p =0; /* Contar caracteres iguais*/
int r;
char palavra [21];
char inversa [21];

		scanf("%s", palavra);

		for (i=0; palavra[i]!= '\0'; i++){
			tamanho ++;}
			//printf ("%d", tamanho);
			j = tamanho;
		
		for (i=0, j= (tamanho -1); i < (tamanho/2); i++){
				
				if (inversa[i] == palavra[j])
					p++;{
						
						if (p == (tamanho/2)
						r = 1;
						else
						r =0; }
				j--;
			}

		if (r==1)
			printf("Palindromo");
		else 
			printf("Nao e um palindromo");

    return 0;


}
