#ifndef POUPANCA_H
#define POUPANCA_H

class Poupanca {

    public:

    static double taxaDeJurosAnual;
    double saldoPoupanca;

    Poupanca();
    Poupanca(double);

    void calcularJurosMensal();
    void depositarValor(double);
    void sacarValor(double);

    static double setTaxaDeJurosAnual (double);

    double getSaldoPoupanca();

};

#endif
