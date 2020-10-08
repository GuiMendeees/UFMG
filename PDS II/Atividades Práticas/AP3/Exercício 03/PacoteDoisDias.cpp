#include "PacoteDoisDias.hpp"


PacoteDoisDias::PacoteDoisDias(string nomeDest, string enderecoDest, string cidadeDest, string estadoDest, int cepDest,
string nomeRemet, string enderecoRemet,string cidadeRemet ,string estadoRemet, int cepRemet, double peso, double custo, double taxa):
    Pacote (nomeDest, enderecoDest, cidadeDest,estadoDest, cepDest, nomeRemet, enderecoRemet, cidadeRemet, estadoRemet, cepRemet,peso,custo),

    _taxaFixa (taxa){}



void PacoteDoisDias::setTaxaFixa (double taxa){
    _taxaFixa = taxa;

}



double PacoteDoisDias::getTaxaFixa (){
    return _taxaFixa;
}


    //Metodos Redefinido
double PacoteDoisDias::calcularCusto(){
    return (Pacote::calcularCusto())+_taxaFixa;

}

