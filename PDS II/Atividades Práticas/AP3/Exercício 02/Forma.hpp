#ifndef FORMA_H
#define FORMA_H
#include <string>

using namespace std;

class Forma {

public:

    double _centroX;
    double _centroY;
    double _raio;


    Forma();
    Forma(double);
    Forma(double, double);

    virtual void imprime()=0;

};



#endif
