#ifndef PACOTEDOISDIAS_H
#define PACOTEDOISDIAS_H

#include "Pacote.hpp"


class PacoteDoisDias :public Pacote{

    //Atributo
    private:
    double _taxaFixa;

    public:

    //Métodos
    void setTaxaFixa (double);
    double getTaxaFixa ();

    //Construtor
    PacoteDoisDias(string, string, string, string, int,string, string, string, string, int, double, double ,double);

    //Metodos Redefinido
    double calcularCusto();

};





#endif
