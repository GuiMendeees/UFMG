#include <stdio.h>

typedef enum {jan =1,fev,mar,abr,mai,jun,jul,ago,set,out,nov,dez} mes;

typedef struct data{
	
	int dia;
	int Mes;
	int ano;
} Data;

typedef struct evento{
	char local[101];
	char nome[101];
	Data data_evento;

}Evento;

void Cadastrar_Evento (Evento agenda[], int n);
void Imprimir_Evento (Evento agenda [], Data d, int n);


int main (){
	
int n;
int i;
	
	scanf ("%d", &n);

Evento agenda[n];
Data d;
	
	Cadastrar_Evento (agenda, n);

	scanf (" %d %d %d", &d.dia, &d.Mes, &d.ano);

	Imprimir_Evento (agenda, d, n);



}

void Cadastrar_Evento (Evento agenda[], int n){
	int i;

	for (i=0; i<n; i++){
		scanf ("%s", agenda[i].nome);
		scanf ("%s", agenda[i].local);
		scanf ("%d", &agenda[i].data_evento.dia);
		scanf ("%d", &agenda[i].data_evento.Mes);
		scanf ("%d", &agenda[i].data_evento.ano);

	}

}


void Imprimir_Evento (Evento agenda [], Data d, int n){
	int i;
	int aux =0;

		for (i=0; i<n; i++){
			if ((d.dia == agenda[i].data_evento.dia) && (d.Mes == agenda[i].data_evento.Mes) && (d.ano == agenda[i].data_evento.ano)){
				printf ("%s %s\n", agenda[i].nome, agenda[i].local);
				aux ++;}
		}
	
	if (aux ==0){
		printf("Nenhum evento encontrado!");
	}	

}
