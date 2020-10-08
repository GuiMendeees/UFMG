#include <stdio.h>


int main (){
	

char nomes[5][100];
int idades[5];
int i;
int j,k;
int v,n; // Verificador para posição Mais Velha e Mais Nova


	for (i=0; i<5; i++){
		printf("Nome: ");
		scanf("%s", nomes[i]);
		
		printf("Idade: ");
		scanf("%i", &idades[i]);}
		k = 10000;
		j = 0;


		for (i=0;i<5;i++){
			if (idades[i]<k){
				//n=idades[i]; Armazena a idade do mais novo
				k=idades[i];
				n=i;}

		}

		for (i=0;i<5;i++){
			if (idades[i]>j){
				//v=idades[j]; Armazena a idade do mais velho
				j=idades[i];}
				v=i;}
			}
    
    //printf("%d\n",k); // Idade Novo
	//printf("%d\n",n); //Posição do mais novo
	//printf("%d\n",v); // Posição do mais velho

	printf("Pessoa mais nova: %s\n",nomes[n]);
	printf("Pessoa mais velha: %s\n",nomes[v]);

return 0;

}