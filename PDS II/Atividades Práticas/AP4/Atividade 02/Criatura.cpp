Criatura::Criatura() {}

string Criatura::getNome()
{
	return nome;
}

void Criatura::setNome(string novoNome)
{
	nome = novoNome;
}

int Criatura::getArmadura()
{
	return armadura;
}

int Criatura::getForca()
{
	return forca;
}
	
void Criatura::setForca(int novaForca)
{
	forca = novaForca;
}

Criatura::~Criatura(){}