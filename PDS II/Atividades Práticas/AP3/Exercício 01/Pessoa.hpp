#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {

    public:

    string _nome;
    string _endereco;

    Pessoa (string, string);

    string getNome();
    string getEndereco();

    void setPessoa(string, string);
    void imprimirInformacoes();

};

#endif
