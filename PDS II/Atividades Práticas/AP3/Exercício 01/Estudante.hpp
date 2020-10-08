#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>
#include <vector>
#include <string>
#include "Pessoa.hpp"

using namespace std;

class Estudante:public Pessoa {
    public:

    vector<string> _curso;
    vector<float> _nota;

    Estudante (string,string);

    void adicionarCursoNota(string, float);

    vector<string> getCursos();
    vector<float> imprimirNotas();
    float getNotaMedia();




};


#endif
