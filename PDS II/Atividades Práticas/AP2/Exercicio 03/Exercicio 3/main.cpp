#include <iostream>
#include <iomanip>
#include "Poupanca.hpp"

using namespace std;

int main()
{
  double saldoInicial;
  cin >> saldoInicial;

  Poupanca *poupanca;

  if (saldoInicial == -1)
    poupanca = new Poupanca();
  else
    poupanca = new Poupanca(saldoInicial);

  cout << setprecision(2) << fixed << Poupanca::taxaDeJurosAnual << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->depositarValor(100);
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->sacarValor(200);
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->depositarValor(150.66);
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->sacarValor(40.33);
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  Poupanca::setTaxaDeJurosAnual(0.10);
  cout << setprecision(2) << fixed << Poupanca::taxaDeJurosAnual << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  Poupanca::setTaxaDeJurosAnual(0.03);
  cout << setprecision(2) << fixed << Poupanca::taxaDeJurosAnual << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;
  poupanca->calcularJurosMensal();
  cout << setprecision(2) << fixed << poupanca->getSaldoPoupanca() << endl;

  return 0;
}
