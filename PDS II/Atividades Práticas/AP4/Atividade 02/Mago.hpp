#ifndef MAGO_HPP
#define MAGO_HPP

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Mago : public Criatura
{

private:
	Dado dadoAtaque1;
	Dado dadoAtaque2;
	Dado dadoDefesa1;
	Dado dadoDefesa2;
	int vidas;

public:
	Mago();
	~Mago();
  int atacar();
  int defender();
  void setForca(int);

};

#endif