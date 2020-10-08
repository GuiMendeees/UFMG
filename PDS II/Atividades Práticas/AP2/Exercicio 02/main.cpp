#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Aquecedor.hpp"

using namespace std;

int main()
{
  double valorInicial;
  cin >> valorInicial;

  Aquecedor *aque;

  if (valorInicial == -1)
    aque = new Aquecedor();
  else
    aque = new Aquecedor(valorInicial);

  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;

  aque->aquecer(10);
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;
  aque->aquecer();
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;
  aque->aquecer(2.5);
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;
  aque->aquecer(0);
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;

  aque->resfriar(7.5);
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;
  aque->resfriar();
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;
  aque->resfriar(0);
  cout << setprecision(2) << fixed << aque->getTemperatura() << endl;

  return 0;
}
