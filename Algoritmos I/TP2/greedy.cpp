#include "greedy.hpp"


void greedy(Ilha* ilhas, int custoMax, int qntIlhas, int* dias, int* pontos){
    
    //Ordenação em tempo O(N LOG N)
    mergeSort(ilhas, qntIlhas);
     
    //Enquanto houver ilhas no "catalogo" ele executa o algorítmo
    for (int i=0; i < qntIlhas; i++) {
        int custoAcumulado = 0;

        //Se o Custo da Ilha for menor ou igual o Orçamento menos o custoAcumulado
        if (ilhas[i].custo <= (custoMax-custoAcumulado)) {
 
            //Escolhe a ilha o maximo de vezes que puder
            int diasEstadia = (orcamento-custoAcumulado)/ilhas[i].custo;

            //Pontuação Total e Quantidade de Dias Totais são atualizados
            *pontuacao += (ilha[i].pontuacao*diasEstadia);
            *dias += diasEstadia;

            //Custo Acumulado igual ao custo da ilha vezes os dias de estadia
            custoAcumulado += (ilhas[i].custo*diasEstadia);

        }
    }
}