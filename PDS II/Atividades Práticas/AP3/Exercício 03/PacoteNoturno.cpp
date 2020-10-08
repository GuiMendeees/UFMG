#include "PacoteNoturno.hpp"


PacoteNoturno::PacoteNoturno(string nomeDest, string enderecoDest, string cidadeDest, string estadoDest, int cepDest,
string nomeRemet, string enderecoRemet,string cidadeRemet ,string estadoRemet, int cepRemet, double peso, double custo, double taxa):

Pacote (nomeDest, enderecoDest, cidadeDest,estadoDest, cepDest, nomeRemet, enderecoRemet, cidadeRemet, estadoRemet, cepRemet,peso,custo)
,_taxaNoturna (taxa) {}




double PacoteNoturno::getTaxaNoturnaPorQuilo(){
    return _taxaNoturna;

}


void PacoteNoturno::setTaxaNoturnaPorQuilo (double taxa){

    _taxaNoturna = taxa;

}

double PacoteNoturno::calcularCusto(){

    return (Pacote::calcularCusto())+(Pacote::getPeso()*_taxaNoturna);

}
