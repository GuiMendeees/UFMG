#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Criatura.hpp"

class Medusa : public Criatura
{

private:
	Dado dadoAtaque1;
	Dado dadoDefesa;

public:
	Medusa();
	int atacar();
	int defender();
	~Medusa();

};

#endif