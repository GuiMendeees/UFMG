#include "Jogo.hpp"

Jogo::Jogo()
{
	criatura1 = nullptr;
	criatura2 = nullptr;
	vencedor = nullptr;

	srand(12345);
}

void Jogo::testaJogo()
{

  criatura1 = new Vampiro(12);
  criatura2 = new Barbaro();
  jogar();

  criatura1 = new Medusa();
  criatura2 = new Mago();
  jogar();  

}

void Jogo::jogar()
{

  Criatura* atacante;
  Criatura* defensor;

  // troca as posicoes metade das vezes
  int aleatorio = rand();
  if (aleatorio % 2 == 0)
  {
    atacante = criatura2;
    defensor = criatura1;
  } else 
  {
    atacante = criatura1;
    defensor = criatura2;    
  }

  int rounds = 1;
  criatura1 = nullptr;

	while (!vencedor)
	{
		cout << "####### Round " << rounds << " #######\n";
		turno(atacante, defensor);
		// checa se houve um vencedor nesse round
		if (!vencedor)
		{ 
			turno(defensor, atacante);
		}
		++rounds;
	}

	imprimeVencedor();

}

void Jogo::turno(Criatura& atacante, Criatura& defensor)
{
	// forca inicial
	cout << atacante->getNome() << " atacante: " << atacante->getForca() << endl;
	cout << defensor->getNome() << " defensor: " << defensor->getForca() << endl;

	// valor de ataque e defesa de cada um
	int ataquePts = atacante->atacar();
	int defesaPts = defensor->defender();


	if (defesaPts == 2000) // poder especial do charme do vampiro
	{
    cout << defensor->getNome() << " evitou que " << atacante->getNome() << " atacasse.\n";
	}
	else 
	{
		if (ataquePts == 1000) // olhar da medusa
		{
			cout << atacante->getNome() << " usou o olhar! " << defensor->getNome() << " virou pedra!\n";
			defensor->setForca(0);
		}
		else // round normal, sem poder especial e olhar da medusa
		{
			cout << atacante->getNome() << " atacou com " << ataquePts << endl;
			cout << defensor->getNome() << " defendeu com " << defesaPts << endl;
			
			int dano = ataquePts - defesaPts;
			cout << dano << " de dano infligido na armadura\n";
			
			int perda = dano - defensor->getArmadura();
			
			if (perda > 0)
			{
				defensor->setForca(defensor->getForca() - perda);
				cout << defensor->getNome() << " está com " << defensor->getForca()  << " de força\n";;
			}
			else 
			{
				cout << "Sem perda de força" << endl;
			}
			
		}
	}

	if(defensor->getForca() < 1) 
	{
    // o atacante venceu! atribuimos ele a vencedor
    atacante = vencedor;
	}
}

void Jogo::imprimeVencedor()
{	
	cout << criatura1->getNome() << ": " << criatura1->getForca() << endl;
	cout << criatura2->getNome() << ": " << criatura2->getForca() << endl;
	cout << vencedor->getNome() << " venceu!\n";
}

void Jogo::desalocaCriaturas()
{
  delete criatura1;
  criatura1 = nullptr;
  criatura2 = nullptr;
  vencedor = nullptr;
}

Jogo::~Jogo() {}