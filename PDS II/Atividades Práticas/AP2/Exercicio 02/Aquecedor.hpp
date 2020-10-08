#ifndef AQUECEDOR_H
#define AQUECEDOR_H
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Aquecedor {

    public :

    double _temperatura;

    Aquecedor();
    Aquecedor(double);

    void aquecer();
    void aquecer (double);

    void resfriar();
    void resfriar (double);

    double getTemperatura();

};

#endif
