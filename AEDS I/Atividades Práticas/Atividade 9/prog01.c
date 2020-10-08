#include <stdio.h>



void gravar_vetor (FILE *fp, int V[], int n){

	int i;

	for (i = 0; i < n; i++){

	fprintf(fp, "%d\n", V[i]);

}


}

void gravar_media (FILE *fp, int V[], int n){
	int i;
	float soma = 0;
	float media = 0;

	for (i = 0; i < n; i++){
		soma += (float)V[i];
	}

	media = (soma/10);

	fprintf(fp, "%f\n", media);

}



int main (){

char nome[100];
int numeros[10];
int i;

	printf ("Digite o nome do arquivo e .txt (arquivo.txt)\n");
	scanf("%s", nome);

	for (i=0; i<10; i++){
	printf("Digite 10 numeros inteiros\n");
	scanf("%d",&numeros[i]);
	}


	FILE *fp = fopen (nome, "w");

	if (fopen(nome, "w") == NULL)
	perror("Erro na abertura do arquivo!\n");

	gravar_vetor (fp,numeros,10);
	gravar_media(fp,numeros,10);

	printf("Arquivo criado com sucesso!\n");

	fclose(fp);

return 0;

}
