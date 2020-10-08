#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include<iostream>
#include <algorithm>

using std::vector;
using std::stack;
using std::string;
using std::cout;
using std::endl;

class Vertice{
    public:
    int idade;
    int indiceEntrada;
    vector<Vertice> adj;
    Vertice(int Idade, int indiceEntrada);
    void printList();
};

class Graph{
    public:
    int numVertices;
    vector<Vertice> Vertices;
  
    Graph(int nVertices);
    bool verificaCiclos();
    bool verificaCiclosAux(int idVertice, bool visited[], bool *recStack);
    void addVertices(int indiceEntrada, int idade);
    void addArestas(int idA, int idB);
    void verListaVertices();
    void swap(int idA, int idB, bool* troca);
    void commander(int idA);
    void meeting();
    void meetingAux(int idVertice, bool visited[], stack<int>& Stack) ;

};

















#endif