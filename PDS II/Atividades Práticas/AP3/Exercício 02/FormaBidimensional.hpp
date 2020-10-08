#ifndef FORMABIDIMENSIONAL_H
#define FORMABIDIMENSIONAL_H
#include "Forma.hpp"
#include <string>

using namespace std;

class FormaBidimensional : public Forma {

    public:

    FormaBidimensional();
    FormaBidimensional(double);
    FormaBidimensional(double, double);


    virtual double getArea()=0;


};


#endif // FORMABIDIMENSIONAL_H
