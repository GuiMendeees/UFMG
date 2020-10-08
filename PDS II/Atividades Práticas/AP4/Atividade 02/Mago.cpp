#include "Mago.h"

Mago::Mago()
{
  dadoAtaque1 = Dado(6);
  dadoAtaque2 = Dado(6);
  
  dadoDefesa1 = Dado(6);
  dadoDefesa2 = Dado(6);

  nome = "Mago";
  
  armadura = 0;
  forca = 10;
  vidas = 2;
}

Mago::~Mago() {}

int Mago::atacar()
{
  int atacarPts = 0;

  atacarPts += dadoAtaque1.rolar();
  atacarPts += dadoAtaque2.rolar();

  return atacarPts;
}

int Mago::defender()
{
  int defesaPts = 0;

  defesaPts += dadoDefesa1.rolar();
  defesaPts += dadoDefesa2.rolar();

  return defesaPts;
}

void Mago::setForca(int novaForca)
{
  forca = novaForca;

  if (vidas == 2 && forca < 1)
  {
    vidas--;
    forca = 20;
    cout << "Mago revive" << endl;
  }

}
