#include "Forma.hpp"
#include "FormaBidimensional.hpp"
#include "Circulo.hpp"
#include <cmath>

using namespace std;

Circulo::Circulo(): FormaBidimensional::Forma(0,0) _raio(0){}

Circulo::Circulo(double x): _raio (x) Forma(0,0) {}

Circulo::Circulo(double x, double y): _raio(x) Forma(y,0) {}

Circulo::Circulo(double x, double y, double y): _raio(x) Forma(y,z) {}


