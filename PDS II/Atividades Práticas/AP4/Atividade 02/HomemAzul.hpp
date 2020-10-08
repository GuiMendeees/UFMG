#ifndef HOMEMAZUL_HPP
#define HOMEMAZUL_HPP

#include "Criatura.hpp"


class HomemAzul : public Criatura
{

private:
	Dado dadoAtaque1;
	Dado dadoAtaque2;
	Dado dadoDefesa1;
	Dado dadoDefesa2;
	Dado dadoDefesa3;

public:
	HomemAzul();
	int atacar();
	int defender();  
  
};

#endif