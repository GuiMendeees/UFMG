#ifndef PACOTE_H
#define PACOTE_H

#include <string>
using namespace std;

class Pacote{

    private:

   
    string _nomeDest;
    string _enderecoDest;
    string _cidadeDest;
    string _estadoDest;
    int _cepDest;

   
    string _nomeRemet;
    string _enderecoRemet;
    string _cidadeRemet;
    string _estadoRemet;
    int _cepRemet;

   
    double _peso;
    double _custoPorQuilo;

   public:

//M�todo Geral

    virtual double calcularCusto();
    Pacote(string, string, string, string, int,string, string, string, string, int, double, double);

// Get Destinatario
    string getDestinatarioNome();
    string getDestinatarioEndereco();
    string getDestinatarioCidade();
    string getDestinatarioEstado();
    int getDestinatarioCEP();
    double getPeso();

   // Set Destinatario
    void setDestinatarioNome(string);
    void setDestinatarioEndereco(string);
    void setDestinatarioCidade(string);
    void setDestinatarioEstado(string);
    void setDestinatarioCEP(int);
    void setPeso(double);

    //Get Rementente
    string getRemetenteNome();
    string getRemetenteEndereco();
    string getRemetenteCidade();
    string getRemetenteEstado();
    int getRemetenteCEP();

    //Set Rementente
    void setRemetenteNome(string);
    void setRemetenteEndereco(string);
    void setRemetenteCidade(string);
    void setRemetenteEstado(string);
    void setRemetenteCEP(int);

   
};


#endif 
