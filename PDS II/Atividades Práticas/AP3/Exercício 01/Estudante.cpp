#include "Estudante.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Estudante::Estudante(string nome, string endereco): Pessoa(nome, endereco) {}

void Estudante::adicionarCursoNota(string curso, float nota){
    this-> _curso.push_back(curso);
    this-> _nota.push_back(nota);
    cout <<curso<<":"<<nota<<endl;
}

 vector<string> Estudante::getCursos(){

    return this->_curso;

}


float Estudante::getNotaMedia(){

    float media=0;
    float total=0;

        for(auto nota : this->_nota) {
            total += nota;
        }

        media = total/(this-> _nota.size());

        return media;
}


vector<float> Estudante::imprimirNotas(){

    return this -> _nota;

}
