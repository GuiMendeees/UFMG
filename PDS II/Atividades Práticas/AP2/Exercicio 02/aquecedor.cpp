#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Aquecedor.hpp"

using namespace std;

Aquecedor::Aquecedor(): _temperatura (20){}
Aquecedor::Aquecedor(double x): _temperatura(x){}

void Aquecedor:: aquecer (){
     _temperatura +=5;
}

void Aquecedor:: aquecer (double x){

   _temperatura +=x;
}

void Aquecedor:: resfriar(){
    _temperatura -= 5;
}

void Aquecedor:: resfriar (double x){

   _temperatura -=x;
}


double Aquecedor:: getTemperatura(){
    return _temperatura;
    //cout << setprecision(2)<< fixed << this -> _temperatura << endl;

}
