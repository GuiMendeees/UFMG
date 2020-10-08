#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Stats{

    string nome;
    vector<float> valores;
    float maximo, minimo, medio;
 
};

    void lerValores(Stats *ajuda);
    void preencherStats(Stats *conjunto, map<string, vector<float> > mapa);
    void limparStats(Stats* conjunto);