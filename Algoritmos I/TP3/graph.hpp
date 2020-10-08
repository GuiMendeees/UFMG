#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include<iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::find;
using std::max_element;
using std::remove;
using std::sort;

class Vertice{
    public:
    int idVertice;
    int valor; 
    int cordI;
    int cordJ;
    int saturacao;
    bool color;
    vector<int> coresVizinhos;
    vector<Vertice> adj;
    Vertice(int idVertice, int valor);
    void printList();
    bool buscaValor(int valor);
};

class Graph{
    public:
    int numVertices;
    int ladoSudoku;
    bool solucao;
    vector<Vertice> Vertices;
  
    Graph(int nVertices, int ladoSudoku);
    void addVertices(Vertice v);
    void addArestas(int idA, int idB);
    void verListaVertices();
    bool existeAresta(int idA, int idB);
    void coloreVertices();
    void calculaSat();
    bool verificaSolucao();
    

};

















#endif