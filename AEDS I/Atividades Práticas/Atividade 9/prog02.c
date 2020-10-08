#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ler_arquivo (FILE *fp, int v[], int n){

    int i;

        if (fp == NULL){
            perror("Erro na abertura do Arquivo!\n");
            exit(0);
        }

    for (i=0; i<n;i++){
        fscanf(fp, "%d",&v[i]);
    }

}



int main(){

char nome_arq[100];
int numeros[10];
FILE *fp;
int i;
float soma=0;
float smedia=0;
float media;
float desvpad;


    printf("Digite o nome do arquivo com o final .txt\n");
    scanf("%s", nome_arq);


    fp = (fopen(nome_arq, "r"));

    ler_arquivo(fp,numeros,10);

  //  for (i=0; i<10;i++){
  //      printf("%d\n", numeros[i]);
   // }

    for (i=0; i<10; i++){
		smedia = smedia+((float)numeros[i]);
		media = (smedia/10);
		}


    for (i=0; i<10; i++){
		soma +=  pow ((numeros[i]-media),2);
		desvpad = sqrt(((float)soma/9));
		}

    printf ("Desvio Padrao igual a %.2f\n", desvpad);

return 0;

}
