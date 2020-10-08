#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include "Retangulo.hpp"


using namespace std;

void Retangulo :: calcularArea (){
   double larg;
   double alt;

    larg = fabs(_PtSupEsq._x - _PtInfDir._x);
    alt = fabs(_PtSupEsq._y - _PtInfDir._y);
    double area = larg*alt;
    cout << fixed << setprecision(2);
    cout <<area<<endl;

}


void Retangulo ::  calcularIntersecao (Retangulo ret2){
    double area = 0;
    Ponto2D IntSupEsq; // Ponto2D de Intersecao Superior Esquerda
    IntSupEsq._x = max(this->_PtSupEsq._x,ret2._PtSupEsq._x);
    IntSupEsq._y = min(this->_PtSupEsq._y,ret2._PtSupEsq._y);

    Ponto2D IntInfDir;
    IntInfDir._x = min(this->_PtInfDir._x,ret2._PtInfDir._x);
    IntInfDir._y = max(this->_PtInfDir._y,ret2._PtInfDir._y);

    /*cout << fixed << setprecision(2);
    cout <<"O ponto superior esquerdo x da intersecao eh:"<<IntSupEsq._x << endl;
    cout <<"O ponto superior esquerdo y da intersecao eh:"<<IntSupEsq._y <<endl;
    cout <<"O ponto inferior direito x da intersecao eh:"<<IntInfDir._x <<endl;
    cout <<"O ponto inferior direito y da intersecao eh:"<<IntInfDir._y <<endl;*/

/*Uso do This para referenciar o Retangulo 1 (dono do metodo)

 ///////////////////////////Algoritmo:
 Se o Ponto Superior Esquerdo X da Intersecao for menor que o Inferior Direito X da Intersecao
 e o Ponto Superior Esquerdo Y da Intercao for maior que o Inferior Direito Y da Intersecao ela existe
 e sua área é (InfDir._x - SupEsq._x) * (SupEsq._y - InfDir._y)
 caso haja alguma premissa inválida ela não existe e a área = 0 ];*/


    if ((IntSupEsq._x < IntInfDir._x) && (IntSupEsq._y > IntInfDir._y)){
        area = ((IntInfDir._x - IntSupEsq._x) * (IntSupEsq._y - IntInfDir._y));
        cout.precision(2);
        cout << area << endl;
    }

    else
        cout << "0" <<endl;

}

