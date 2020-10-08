#include <iostream>
#include "Ponto2D.hpp"

using namespace std;

class Retangulo {
    public:

    Ponto2D _PtSupEsq;
    Ponto2D _PtInfDir;

    Retangulo (Ponto2D PtSupEsquerdo, Ponto2D PtInfDireito) : _PtSupEsq(PtSupEsquerdo), _PtInfDir (PtInfDireito){}

    void calcularArea();
    void calcularIntersecao (Retangulo ret2);

};

