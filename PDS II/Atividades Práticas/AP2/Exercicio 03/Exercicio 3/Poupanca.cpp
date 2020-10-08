#include <iostream>
#include <iomanip>
#include "Poupanca.hpp"


Poupanca :: Poupanca (): saldoPoupanca (0){}
Poupanca :: Poupanca (double x): saldoPoupanca(x){}
double Poupanca::taxaDeJurosAnual = 0.05;

void Poupanca::calcularJurosMensal(){

    double jurosMensal = 0;
    jurosMensal = ((this ->saldoPoupanca)*(this->taxaDeJurosAnual)/12);
    saldoPoupanca += jurosMensal;

}

void Poupanca :: depositarValor (double x){
    saldoPoupanca += x;

}

void Poupanca :: sacarValor (double x){
    saldoPoupanca -= x;

}

double Poupanca:: setTaxaDeJurosAnual (double x){

     taxaDeJurosAnual = x;

}

double Poupanca::getSaldoPoupanca(){

    return saldoPoupanca;

}
