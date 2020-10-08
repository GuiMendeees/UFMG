#ifndef PACOTENOTURNO_H
#define PACOTENOTURNO_H

#include "Pacote.hpp"


class PacoteNoturno : public Pacote {

    private:

    double _taxaNoturna;

    public:

    double getTaxaNoturnaPorQuilo();
    void setTaxaNoturnaPorQuilo (double);

    //Construtor
    PacoteNoturno(string, string, string, string, int,string, string, string, string, int, double, double ,double);

    //Metodos Redefinido
    double calcularCusto();

};



#endif
