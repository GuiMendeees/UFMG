#ifndef VAMPIRO_HPP
#define VAMPIRO_HPP

#include "Criatura.hpp"

class Vampiro : public Criatura
{

private:
	Dado dadoAtaque;
	Dado dadoDefesa;

public:
	Vampiro();
  int ataque();
  int defesa();

};

#endif