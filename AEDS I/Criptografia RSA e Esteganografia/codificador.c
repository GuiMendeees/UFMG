#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funcoes.h"


// Criptografia RSA - Guilherme Mendes de Oliveira - AEDS I

int main (){

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

	//printf("Chave Pública %ld, %ld\n",n,e);
	//printf("Chave Privada %ld, %ld\n",n,d);


char MsgTexto[101]; //Vetor que recebe até 100 caracteres
int MsgValor[101]; // Vetor que armazena os caracteres em forma numerica
int MsgCrip[101]; // Vetor com o valor da mensagem criptografada
int cont=0; // Conta o tamanho do vetor da mensagem criptografada
int i,j;
long double c;

//Recebe a mensagem e armazena os caracteres no Vetor MsgTexto
    printf("Digite a mensagem a ser encriptada:\n");
   // scanf("%s", MsgTexto); Lê apenas palavra
   scanf(" %[^\n]s", MsgTexto); // Lê a String com espaços - Válido para frases

//Transforma a String em valor numérico e Armazena no Vetor MsgValor
    for(i = 0;i < strlen(MsgTexto); i++){
        MsgValor[i] = MsgTexto[i];}

// Criptografa a mensagem usando as chaves e mostra caracter por caracter criptografado
    printf("Mensagem Criptografada!\n");
	   for (i=0; i < strlen(MsgTexto); i++){
        c = Criptografia(e,n,MsgValor[i]);
        MsgCrip[i] = c;
      //  printf("%Lf\n",c);
        cont++;
}


FILE *imgentrada;
FILE *imgsaida;
FILE *bit; // Ponteiro para o arquivo txt bin da função - Imagem

int altura=0, largura=0, maximo=0; //Maximo- Quantidade do valor do pixel MAXimo RGB = 255
char tipo[100], descricao[100] ;
char nome[100];
	
	printf("Digite o nome do arquivo (nomedoarquivo.ppm)\n");
	scanf("%s", nome);

	imgentrada = fopen (nome,"r");
        if(imgentrada == NULL){
            printf("Erro ao abrir a imagem!\n");
            return 0;
        }

        fscanf(imgentrada, "%s", tipo);//P3,P4.P5
            if(strcmp(tipo, "P3") != 0){

                printf("Arquivo n é PPM\n");//checa se esta em P3
                fclose(imgentrada);

		return 0;
	}
      //  fscanf(imgentrada, "%s", descricao);//Comentario imagem SE HOUVER
		fscanf(imgentrada, "%d %d\n %d\n", &altura, &largura, &maximo);//le o head da imagem
		//printf("%d %d", altura,largura);


// Alocando os dados da imagem
int *ImgVetor = (int*) malloc(sizeof(int) *(altura*largura*3) );
int aloca = (altura*largura*3);
// printf("%d", aloca);

		//Preenche o vetor com os dados da imagem
   		 for(i=0; i < aloca;i++){
            fscanf(imgentrada,"%d ",&ImgVetor[i]);
    }


// Reserva um vetor para receber o valor binario da mensagem
//Cont é o numero de caracteres da mensagem
int auxiliar[cont];

//Matriz para armazenar o valor binario do caracter (cada linha com 8 espaços)
   int **MsgCripBin = (int **) malloc(sizeof(int *) *cont);

    for(i = 0; i < cont; i++){
			MsgCripBin[i] = (int *) malloc(sizeof(int) * 8);
    }


    for(i=0;i<cont;i++){
        auxiliar[i]=MsgCrip[i];
        j=7;
        while(j > -1 )	{
            MsgCripBin[i][j] = auxiliar[i] % 2; // Armazena os restos em ordem inversa 
            //primeiro resto vai pra ultima casa
            j--;
            if(j == 0)
                MsgCripBin[i][j] = auxiliar[i]/2;
            auxiliar[i]= auxiliar[i]/ 2;

        }
    }   

//Comparar binarios e mudar o bit menos significativo
    int aux=0;
    for(i=0;i<cont;i++){
        for(j=0;j<8;j++){

        	//Se o mod do valor do RGB for 1 o valor binario dela termina em 1 se for 0 termina em zero 
        	//por isso da pra comparar o valor sem ter que passar pra binario
        	
            if(MsgCripBin[i][j]==0 && ImgVetor[aux]%2==1){
             ImgVetor[aux]--;
            }
            if(MsgCripBin[i][j]==1 && ImgVetor[aux]%2==0){
               ImgVetor[aux]++;
            }
            aux++;
        }
        aux++;
    }

imgsaida = fopen("imgcodificada.ppm", "w");

	fprintf(imgsaida, "P3\n");
	fprintf(imgsaida, "%d %d\n255\n", largura, altura);
	int contCol = 0; // Colocar as colunas R G B corretamente
	for(i=0;i<aloca;i++){
        fprintf(imgsaida, "%d ", ImgVetor[i]); // Aqui ja ta gravando o valor alterado lá em cima na comparação
        contCol++;
		if(contCol == 3){
			fprintf(imgsaida, "\n");
			contCol = 0;
		}
    }


    free(*MsgCripBin); //Desaloca a memoria do ponteiro de linha
     
     for(i = 0; i < cont; i++){ // Desaloca da memoria linha por linha da matriz
		free(MsgCripBin[i]); 
    }

//Arquivo para gravar o par de chaves
 FILE *chaves = fopen("private.txt", "w");
 	fprintf(chaves, "%li\n",n);
 	fprintf(chaves, "%li\n",d);

 	//Fechando todos os arquivos
 	fclose(chaves);
    fclose(imgentrada);
    fclose(imgsaida);

return 0;

}
