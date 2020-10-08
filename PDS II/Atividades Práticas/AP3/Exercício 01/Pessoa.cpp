#include "Pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

Pessoa::Pessoa(string nome, string endereco): _nome(nome), _endereco(endereco){}

void Pessoa::setPessoa(string nome, string endereco){

    this->_nome = nome;
    this->_endereco = endereco;

}

string Pessoa::getNome(){

    return this->_nome;

}

string Pessoa::getEndereco(){

    return this->_endereco;

}

void Pessoa::imprimirInformacoes(){

    cout <<_nome<<":"<<_endereco<<endl;

}

