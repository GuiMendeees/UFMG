#ifndef CRIATURA_HPP
#define CRIATURA_HPP

#include <string>
using std::string;
#include "Dado.hpp"

class Criatura
{

protected:
	string nome;
	int armadura;
	int forca;

public:
  Criatura();
	virtual ~Criatura();
  virtual int defender() = 0;
  virtual string getNome();
  virtual void setNome(string);
  virtual int atacar() = 0.;
  virtual int getArmadura();
  virtual int getForca();
  virtual void setForca(int);

};

#endif