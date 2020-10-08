#include "Medusa.hpp"

Medusa::Medusa()
{
	dadoAtaque1 = Dado(6);
	dadoAtaque2 = Dado(6);
	
	dadoDefesa = Dado(6);

	nome = "Medusa";
	armadura = 3;
	forca = 8;
}

int Medusa::atacar()
{
	int ataquePts = 0;

	ataquePts += dadoAtaque1.rolar();
	ataquePts += dadoAtaque2.rolar();

	if (ataquePts == 12)
	{
		ataquePts = 1000;
	}
		
	return ataquePts;
}

int Medusa::defender()
{
	int defesaPts = 0;

	defesaPts += dadoDefesa.rolar();

}


Medusa::~Medusa() {}