#include "Forma.hpp"


Forma::Forma (){
    this->_centroX =0;
    this->_centroY =0;
}

Forma::Forma(double x): _centroX(x), _centroY(0){}

Forma::Forma(double x, double y): _centroX(x), _centroY(y){}




