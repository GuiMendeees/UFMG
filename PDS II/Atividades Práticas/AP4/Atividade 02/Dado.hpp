#ifndef DADO_HPP
#define DADO_HPP

#include <cstdlib>

class Dado
{

private:
	int lados;

public:
	Dado();
  Dado(int);
	int rolar();
	~Dado();

};

#endif