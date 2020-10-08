#include "Professor.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

Professor::Professor(string nome, string endereco): Pessoa(nome, endereco) {}

bool Professor:: adicionarCurso(string curso){
    vector<string>::iterator it = _curso.begin();

    for(;it !=_curso.end(); it++){
    }

     if (it != _curso.end())
        return 1;

    else
      this -> _curso.push_back(curso);
        return 0;

}


bool Professor::removerCurso(string curso){

    vector<string>::iterator it = find(_curso.begin(), _curso.end(), curso);

        if (it != _curso.end()){
            _curso.erase(it);
            return 1;
        }


            else
            return 0;

}






 vector<string> Professor::getCursos(){

    return this->_curso;

}


