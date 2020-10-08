#include "Pacote.hpp"
#include <string>



Pacote::Pacote(string nomeDest, string enderecoDest, string cidadeDest, string estadoDest, int cepDest, string nomeRemet, string enderecoRemet,
string cidadeRemet ,string estadoRemet, int cepRemet, double peso, double custo){

    _nomeDest = nomeDest;
    _enderecoDest = enderecoDest;
    _cidadeDest = cidadeDest;
    _estadoDest = estadoDest;
    _cepDest = cepDest;

    _nomeRemet = nomeRemet;
    _enderecoRemet = enderecoRemet;
    _cidadeRemet = cidadeRemet;
    _estadoRemet = estadoRemet;
    _cepRemet = cepRemet;

     if (custo <= 0)
        _custoPorQuilo = 0;
    else
        _custoPorQuilo = custo;

    if ( peso <= 0)
        _peso = 0;
    else
        _peso = peso;
}


// Get Destinatario

string Pacote::getDestinatarioNome(){
    return _nomeDest;
}

string Pacote::getDestinatarioEndereco(){
    return _enderecoDest;
}

string Pacote::getDestinatarioCidade(){
    return _cidadeDest;

}

string Pacote::getDestinatarioEstado(){
    return _estadoDest;

}

int Pacote::getDestinatarioCEP(){
    return _cepDest;
}

// Get Remetente

string Pacote::getRemetenteNome(){

    return _nomeRemet;
}
string Pacote::getRemetenteEndereco(){

    return _enderecoRemet;
}
string Pacote::getRemetenteCidade(){

    return _cidadeRemet;

}
string Pacote::getRemetenteEstado(){

    return _estadoRemet;

}
int Pacote::getRemetenteCEP(){

    return _cepRemet;

}


// Set Destinatario

void Pacote::setDestinatarioNome(string nome){

    this-> _nomeDest = nome;
}
void Pacote::setDestinatarioEndereco(string endereco){
    this-> _enderecoDest = endereco;
}
void Pacote::setDestinatarioCidade(string cidade){
    this-> _cidadeDest = cidade;

}
void Pacote::setDestinatarioEstado(string estado){
    this-> _estadoDest = estado;
}
void Pacote::setDestinatarioCEP(int cep){
    this-> _cepDest = cep;
}

//Set Rementente
void Pacote::setRemetenteNome(string nome){
    this-> _nomeRemet = nome;
}
void Pacote::setRemetenteEndereco(string endereco){
    this-> _enderecoRemet = endereco;
}
void Pacote::setRemetenteCidade(string cidade){
    this-> _cidadeRemet = cidade;
}
void Pacote::setRemetenteEstado(string estado){
    this-> _estadoRemet = estado;
}
void Pacote::setRemetenteCEP(int cep){
    this-> _cepRemet = cep;
}

//Calcular custo

double Pacote::calcularCusto(){

    return (_peso*_custoPorQuilo);

}

void Pacote::setPeso(double peso){

    _peso = peso;

}

double Pacote::getPeso(){
    return _peso;
}
