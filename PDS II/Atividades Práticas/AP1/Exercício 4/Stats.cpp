#include "Stats.hpp"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void lerValores(Stats *aux){

    float maior, menor , medio = 0, cont = 0;
    int i;

    maior = aux->valores[0];
    menor = aux->valores[0];

    for(i = 0 ; i < aux->valores.size(); ++i){

        cont += aux->valores[i];
        if(menor > aux->valores[i]){
            menor = aux->valores[i];
        }

        if(maior < aux->valores[i]){
            maior = aux->valores[i];
        }
    }
    medio = cont/(float)i;

    cout << " " << "|" << " " << menor << " " << maior << " " << medio;

}

void limparStats(Stats* conjunto){

    conjunto->nome = "";
    conjunto->valores.clear();

}

void preencherStats(Stats *conjunto, map<string, vector<float> > mapa){

    for(auto it=mapa.begin(); it != mapa.end(); ++it){

        cout << it->first << " ";
        conjunto->nome = it->first;

        for(int i=0; i < it->second.size() ; ++i){
        
        cout.precision(2);
        cout << fixed << it->second[i] << " ";
        conjunto->valores.push_back(it->second[i]);

        }
        
        lerValores(conjunto);
        limparStats(conjunto);
        
        cout << endl;
    }
}

