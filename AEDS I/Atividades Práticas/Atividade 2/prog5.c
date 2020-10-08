/* Atividade II
AEDES I
ALUNO: GUILHERME MENDES DE OLIVEIRA*/

#include <stdio.h>
#include<math.h>

int main(){

double h;
double pes;
double polegadas;
double cm;
cm = 100;
pes = 30.48;
polegadas = 2.54;

    printf("Digite a altura em metros:\n");
    scanf("%lf", &h);
    printf("Em polegadas %lf\n", cm*h*polegadas);
    printf("Em pes %lf\n", cm*h*pes );

    return 0;

}
