#include "FormaBidimensional.hpp"
#include "Forma.hpp"
#include <string>


FormaBidimensional::FormaBidimensional(): Forma(0,0) {}

FormaBidimensional::FormaBidimensional(double x): Forma(x,0) {}

FormaBidimensional::FormaBidimensional(double x, double y): Forma(x, y) {}


