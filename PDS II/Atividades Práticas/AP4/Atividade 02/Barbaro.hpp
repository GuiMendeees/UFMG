#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "Criatura.hpp"

class Barbaro : public Critura
{

private:
	Dado dadoAtaque1;
	Dado dadoAtaque2;
	Dado dadoDefesa1;
	Dado dadoDefesa2;

public:
	Barbaro();
	int atacar();
	int defender();
	~Barbaro();
  
};

#endif