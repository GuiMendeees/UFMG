#include "mergesort.hpp"

#include <iostream>

using std::cout;


void merge(Ilha* ilhas, int esquerda, int meio, int direita){

    //Variaveis de Auxilio para percorrer os indices dos Arranjos
    int i, j, k;

    //Recebe o tamanho de cada Partição
    int sizeLeft = meio - esquerda + 1;
    int sizeRight =  direita - meio;

    //Copia cada partição para um Arranjo próprio
    Ilha esquerdaPart[sizeLeft], direitaPart[sizeRight];
    for (i = 0; i < sizeLeft; i++) {
        esquerdaPart[i].custo = ilhas[esquerda + i].custo;
        esquerdaPart[i].pontuacao = ilhas[esquerda + i].pontuacao;
        esquerdaPart[i].custoBeneficio = ilhas[esquerda + i].custoBeneficio;
    }

    for (j = 0; j < sizeRight; j++) {
        direitaPart[j].custo = ilhas[meio + 1+ j].custo;
        direitaPart[j].pontuacao = ilhas[meio + 1+ j].pontuacao;
        direitaPart[j].custoBeneficio = ilhas[meio + 1+ j].custoBeneficio;
    }

    i = 0; 
    j = 0; 
    k = esquerda; 

//Comparando as ilhas de cada partição aquela que tem o melhor custo beneficio terá virá primeiro no arranjo ordenado final(Maior->Menor)
    while (i < sizeLeft && j < sizeRight) {
       
        if (esquerdaPart[i].custoBeneficio >= direitaPart[j].custoBeneficio) {
           
            ilhas[k].custo = esquerdaPart[i].custo;
            ilhas[k].pontuacao = esquerdaPart[i].pontuacao;
            ilhas[k].custoBeneficio = esquerdaPart[i].custoBeneficio;
            i++;
        }
        else {
       
            ilhas[k].custo = direitaPart[j].custo;
            ilhas[k].pontuacao = direitaPart[j].pontuacao;
            ilhas[k].custoBeneficio = direitaPart[j].custoBeneficio;
            j++;
        }
        k++;
    }

    //copia o array da esquerda ordenado para o array mergeado
    while (i < sizeLeft) {
        ilhas[k].custo = esquerdaPart[i].custo;
        ilhas[k].pontuacao = esquerdaPart[i].pontuacao;
        ilhas[k].custoBeneficio = esquerdaPart[i].custoBeneficio;
        i++;
        k++;
    }

    //copia o array da direita ordenado para o array mergeado
    while (j < sizeRight) {
        ilhas[k].custo = direitaPart[j].custo;
        ilhas[k].pontuacao = direitaPart[j].pontuacao;
        ilhas[k].custoBeneficio = direitaPart[j].custoBeneficio;
        j++;
        k++;
    }

}

void ordena(Ilha* ilhas, int esquerda, int direita) {
    //caso os apontadores nao tenham se cruzado ou sejam os mesmos
    if (esquerda < direita) {
        int meio = esquerda+(direita-esquerda)/2;

        //ordena metade da esquerda
        ordena(ilhas, esquerda, meio);
        //ordena metade da direita
        ordena(ilhas, meio+1, direita);

        //junta os arrays ordenados
        merge(ilhas, esquerda, meio, direita);
    }
}




void mergeSort(Ilha* ilhas, int n) {
    //inicia funcao de ordenacao por mergesort
    ordena(ilhas, 0, n-1);
}



