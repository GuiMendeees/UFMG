#include <stdio.h>
#include <stdlib.h>


typedef struct espiral {

    int x;
    int y;

} Espiral;


int main() {

Espiral esp;
esp.x=0;
esp.y=0;
int n=0;

// Numero a ser informado pelo usuário
int numeroDigitado;

//Variavel que ira regular a quantidade de vezes que realizo operacoes em X e em Y
int cont=0;

//Tamanho do lado formado pela espiral quadrada ao ser desenhada
int tamanhoLado = 1;

//Regula o valor a ser incrementado ou decrementado nos eixos
int maisOuMenos = 1;

//Variavel que regula  em qual dos eixos haverá o incremento ou decremento
int varControle = -1;

// O usuário informa o numero que quer saber as coordenadas na espiral quadrada
    printf("Digite o numero da espiral:\n");
    scanf("%d", &numeroDigitado);

    // O laço de repetição incrementa o ponto n vezes (Numero fornecido pelo usuário)
    for (int i=0; i < numeroDigitado; i++) {


    if (tamanhoLado%2 !=0){
       maisOuMenos = 1;
    }

    else{
        maisOuMenos = -1;
    }

     //Primeiro o Y sofre alteração logo a variavel de controle recebe -1 e a partir dai ela é alternada
    if (varControle > 0) {

            esp.x = esp.x - maisOuMenos;
        }
        else {
            esp.y = esp.y + maisOuMenos;
        }

        cont ++;
        //n++;


    if (cont == tamanhoLado){
        cont = 0;
        varControle = varControle *(-1);

        //Quando a variavel de controle termina de atuar no x as proximas alteracoes precisam iniciar em Y
        // Se for positiva o tamanho mantem e ela atua em X no 2 If
        if (varControle <0)
            tamanhoLado ++;
    }


}

    printf("As cordenadas de %d sao: ( %d, %d )\n",numeroDigitado, esp.x, esp.y);
    //printf(" n eh igual a %d", n);


return 0;

}
