#include "ilha.hpp"
#include "mergesort.hpp"

#include <fstream>
#include<iostream>
#include <string>
#include <chrono>

//Para deixar o codigo mais limpo fica predefinido escopo std
using std::cout;
using std::endl;
using std::string;
using std::ifstream;


int custoMax;
int qntIlhas;
int dias, pontos;
string nomeArquivo;


int main(int argc, char** argv){

    nomeArquivo = argv[1];
    ifstream arquivo (nomeArquivo);

     arquivo >> custoMax >> qntIlhas;

    Ilha ilhas [qntIlhas];
     
    for (int i=0; i<qntIlhas; i++){

        int recebeCustos, recebePonto;
        float custoBen;
        arquivo >> recebeCustos >> recebePonto;
        custoBen = recebeCustos/recebePonto;
       
        ilhas[i].custo = recebeCustos;
        ilhas[i].pontuacao = recebePonto;
        ilhas[i].custoBeneficio = custoBen;
        
    }
/*
    cout<<"Antes do Merge:"<<endl;
    for (int i = 0 ; i<qntIlhas; i++){
        cout<<"Ilha "<<i+1 <<":\n"<<"custo - "<<ilhas[i].custo<<"Ponto - "<<ilhas[i].pontuacao<<"Custo Beneficio - "<<ilhas[i].custoBeneficio<<endl;
    }



    mergeSort(ilhas, qntIlhas);

    cout<<"Depois do Merge:"<<endl;
    for (int i = 0 ; i<qntIlhas; i++){
        cout<<"Ilha "<<i+1 <<":\n"<<"custo - "<<ilhas[i].custo<<"Ponto - "<<ilhas[i].pontuacao<<"Custo Beneficio - "<<ilhas[i].custoBeneficio<<endl;
    }
*/

return 0;
}