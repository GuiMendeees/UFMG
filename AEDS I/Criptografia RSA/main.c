// Criptografia RSA - Guilherme Mendes de Oliveira - AEDS I
// Chave Publica Criptografa
// Chave Privada Descriptografa

//Obter dois Numeros primos do Usuario e verificar se eh primo mesmo (2 Chaves Privadas) (11,17)
//Calcular N (pxq) -> Primeira Chave Publica (11*13)
//Calcular Totiente -> (p-1)*(q-1) (10*12)
//Definir E : Valor entre 1 e Totiente que não tem um divisor comun com q(N)  -> Segunda Chave Publica (13)
//Calcular D(inverso multiplicativo) -> d*e = 1 mod (q(N)) Um numero que multiplicado por e vai apresentar resto 1 ao ser dividido por totiente (qN) de N  -> Terceira Chave Privada

//Transformar a String em Numeros atraves da Tabela ASCI
//Encriptar a mensagem com base nas chaves publicas
//Descriptografar a mensagem com base nas chaves privadas

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funcoes.h"


int main () {

long int  primo1, primo2, ValidaPrimo, n, totiente, e, d;

// Recebe o 1º primo e verifica se é primo
	printf ("Digite Um Numero Primo:\n");
	scanf ("%ld", &primo1);

	ValidaPrimo = VerificaPrimos (primo1);
	if (ValidaPrimo == 0){
		printf("1º Numero Informado não é Primo\n");
		return 0;
}

// Recebe o 2º primo e verifica se é primo
	printf ("Digite Um Numero Primo:\n");
	scanf ("%ld", &primo2);

	ValidaPrimo = VerificaPrimos (primo2);
	if (ValidaPrimo == 0){
		printf("2º Numero Informado não é Primo\n");
		return 0;
}

// Calcula o N (1ª Chave Pública/Privada)
	n = CalculaN (primo1,primo2);
	//printf("%lu\n",n);

// Calcula o Q (Totiente de N)
	totiente = CalculaQ (primo1,primo2);
	//printf("%lu\n",totiente);

// Calcula o E (2ª Chave Pública)
	e = CalculaE(totiente, primo1, primo2);
	//printf("%lu\n",e);

// Calcula o D (2ª Chave Privada)

	d = CalculaD(e, totiente);
	//printf("%lu\n",d);

	printf("Chave Pública %ld, %ld\n",n,e);
	printf("Chave Privada %ld, %ld\n",n,d);


char MsgTexto[101]; //Vetor que recebe até 100 caracteres
int MsgValor[101]; // Vetor que armazena os caracteres em forma numerica
int MsgCrip[101]; // Vetor com o valor da mensagem criptografada
int i;
long double c;

//Recebe a mensagem e armazena os caracteres no Vetor MsgTexto
    printf("Digite a mensagem a ser encriptada:\n");
   // scanf("%s", MsgTexto); Lê apenas palavra
   scanf(" %[^\n]s", MsgTexto); // Lê a String com espaços - Válido para frases

//Transforma a String em valor numérico e Armazena no Vetor MsgValor
    for(i = 0;i < strlen(MsgTexto); i++){
        MsgValor[i] = MsgTexto[i];}

// Criptografa a mensagem usando as chaves e mostra caracter por caracter criptografado
    printf("Mensagem Criptografada:\n");
    for (i=0; i < strlen(MsgTexto); i++){
        c = Criptografia(e,n,MsgValor[i]);
        MsgCrip[i] = c;
        printf("%Lf\n",c);
}

// Descriptografa a mensagem e armazena no vetor MsgTexto
    printf("Mensagem Descriptografada:\n");
    for (i=0; i < strlen(MsgTexto); i++){
        c = Criptografia(d,n,MsgCrip[i]); // pEGAR O VALOR CRPTOGRAFADO E EXECUTAR A FUNÇÃO
       printf ("%Lf\n", c); //Depurar o valor Asci das letras
       MsgTexto[i] = c;
        
}

	printf("\n"); // Quebra de Texto
// Mostra a mensagem descriptografada
	printf("A mensagem digitada foi: %s", MsgTexto);

return 0;

}
