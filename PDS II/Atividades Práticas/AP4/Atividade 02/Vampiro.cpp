#include "Vampiro.hpp"

Vampiro::Vampiro()
{
	dadoAtaque = Dado(12);
	dadoDefesa = Dado(6);

	nome = "Vampiro";
	armadura = 1;
	forca = 18;
}

int Vampiro::ataque()
{
	int atacarPts = 0;

	atacarPts += dadoAtaque.rolar();

	return atacarPts;
}

int Vampiro::defesa()
{
	int defesaPts = 0;

	int defesaResultado = dadoDefesa.rolar();
	defesaPts += defesaResultado;

	if (defesaResultado % 2 == 0)
	{
		defesaPts = 2000;
	}

}

Vampiro::~Vampiro() {}