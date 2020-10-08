#include "Barbaro.hpp"

Barbaro::Barbaro()
{
	dadoAtaque1 = Dado(6);
	dadoAtaque2 = Dado(6);

	dadoDefesa1 = Dado(6);
	dadoDefesa2 = Dado(6);

	nome = "Barbaro";
	armadura = 0;
	forca = 12;
}

Barbaro::~Barbaro() {}

int Barbaro::atacar()
{
  int ataquePts = 0;

  ataquePts += dadoAtaque1.rolar();
  ataquePts += dadoAtaque2.rolar();

  return ataquePts;
}

int Barbaro::defender()
{
  double defesaPts = 0;

  defesaPts += dadoDefesa1.rolar();
  defesaPts += dadoDefesa2.rolar();

  return defesaPts;
}
