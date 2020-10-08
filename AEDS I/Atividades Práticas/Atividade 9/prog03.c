#include <stdio.h>
#include <stdlib.h>



void gravar_matriz (FILE *fp, float m[3][3]){
    int i,j;

    for (i=0;i<3;i++){
        for (j=0; j<3;j++){
    fwrite(&m[i][j], sizeof(float),1,fp);

        }

    }
     printf("Arquivo criado com sucesso!\n");
}

int main (){

FILE *fp;
float m[3][3];
int i,j;


    fp = fopen("matriz.bin", "wb");
        if (fp == NULL){
            printf ("Erro na abertura do arquivo!\n");
            return 1;
        }

    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("Digite um valor:\n");
            scanf("%f", &m[i][j]);
        }

    }

    gravar_matriz (fp, m);

return 0;

}
