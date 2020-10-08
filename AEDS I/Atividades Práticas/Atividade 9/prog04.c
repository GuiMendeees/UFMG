#include <stdio.h>
#include <stdlib.h>




void ler_matriz (FILE *fp, float m[3][3]){
    int i,j;
    int cont =1;

        for (i=0;i<3;i++){
            for(j=0;j<3;j++){
                fread(&m[i][j], sizeof(float),1,fp);
               // printf("Linha %d Coluna %d\n", i,j);
            }

        }
}


int main (){

FILE *fp;
char nome[100];
float m[3][3];
int i,j;
float somacol=0;

    printf ("Digite o nome do arquivo e .bin (arquivo.bin)\n");
	scanf("%s", nome);

    fp = fopen(nome, "rb");
        if (fp == NULL){
            printf ("Erro na abertura do arquivo!\n");
            return 1;
        }

    ler_matriz (fp, m);

    for (j=0;j<3;j++){
        for (i=0;i<3;i++){
            somacol +=(float)m[i][j];
        }
     printf("Somatorio Coluna %.2f\n", somacol);
     somacol =0;
    }

fclose(fp);
return 0;
}
