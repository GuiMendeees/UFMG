#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.hpp"
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;

class Circulo : public FormaBidimensional{

    public:

    double _raio;
    string _nome = "Circulo";

    Circulo();
    Circulo(double);
    Circulo(double,double);
    Circulo (double,double,double);
    double getArea() override{

        const double pi  = 3.141592653589793238463;
        double area;
        area= (pi*(pow(this->_raio,2)));
        return area;

    };

};






#endif // CIRCULO_H
