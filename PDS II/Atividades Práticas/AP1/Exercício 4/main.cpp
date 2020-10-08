#include "Stats.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>


using namespace std;

int main()
{

    Stats *structStats = new Stats;
    map<string, vector<float> > valores;
    string chave;
    float numeros;


    while(cin >> chave >> numeros){

        valores[chave].push_back(numeros);
    }


        preencherStats(structStats, valores);
        
    return 0;
}
