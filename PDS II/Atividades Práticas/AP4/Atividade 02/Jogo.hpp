#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::string;

#include "Criatura.hpp"
#include "Barbaro.hpp"
#include "HomemAzul.h"
#include "Mago.hpp"
#include "Vampiro.hpp"
#include "Medusa.hpp"

class Jogo
{

private:
	Criatura* criatura1;
	Criatura* criatura2;
	Criatura* vencedor;

public:
	Jogo();
	~Jogo();
  void jogar();
  void testaJogo();
  void turno(Criatura*, Criatura*);
  void imprimeVencedor();
  void desalocaCriaturas();

};

#endif