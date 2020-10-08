#include "HomemAzul.hpp"

HomemAzul::HomemAzul()
{
  dadoAtaque1 = Dado(10);
  dadoAtaque2 = Dado(10);

  dadoDefesa1 = Dado(6);
  dadoDefesa2 = Dado(6);
  dadoDefesa3 = Dado(6);

  nome = "Homem Azul";
  armadura = 3;
  forca = 12;
}

HomemAzul::~HomemAzul() {}

int HomemAzul::ataca()
{
  int atacarPts = 0;

  atacarPts += dadoAtaque1.rolar();
  atacarPts += dadoAtaque2.rolar();

  return atacarPts;
}

int HomemAzul::defender()
{
  int defesaPts = 0;

  if (forca > 0)
  {
    defesaPts += dadoDefesa1.rolar();
  }

  if (forca > 4)
  {
    defesaPts += dadoDefesa2.rolar();
  }

  if (forca > 8)
  {
    defesaPts += dadoDefesa3.rolar();
  }
  
  return defesaPts;
}
