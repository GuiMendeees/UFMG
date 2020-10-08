#ifndef PROFESSOR_H
#define PROFESSOR_H


#include <iostream>
#include <vector>
#include <string>
#include "Pessoa.hpp"

using namespace std;

class Professor:public Pessoa {
    public:

    vector<string> _curso;

    Professor (string, string);

    bool adicionarCurso(string);
    bool removerCurso(string);

    vector<string> getCursos();

};












#endif
