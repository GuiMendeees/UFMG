#include "graph.hpp"
#include <fstream>
#include<iostream>
#include <string>


//Para deixar o codigo mais limpo fica predefinido escopo std
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int ladoSudoku;
int linhasQuadrante;
int colunasQuadrante;
int posVertice =0;
int k;
string nomeArquivo;
vector<Vertice> solution;


int main(int argc, char** argv){

    nomeArquivo = argv[1];
    ifstream arquivo (nomeArquivo);
    
    arquivo >> ladoSudoku >> colunasQuadrante >> linhasQuadrante;
    
   // vector<int> valoresPermitidos;
    Graph Sudoku((ladoSudoku*ladoSudoku),ladoSudoku);
    
    //Cria o Grafo com os Vertices
     for (int i=0; i < ladoSudoku; i++){
         int valorSudoku;
        // valoresPermitidos.push_back(i+1);
         for (int j=0; j<ladoSudoku; j++){
             arquivo >> valorSudoku;
             Vertice v (posVertice, valorSudoku);
             v.cordI = i;
             v.cordJ = j;
             Sudoku.addVertices(v);
             posVertice++;

             }
         }
        

    //Cria as arestas entre os vertices MESMA LIN TEM ARESTA MESMA COL TEM ARESTA
    for (int i=0;i<Sudoku.numVertices; i++){//Itera por todos os vertices do Grafo
        k=0;
        for (;k<Sudoku.numVertices;k++){
            if(i !=k){
                //Arestas mesma linha
                if(Sudoku.Vertices[i].cordI == Sudoku.Vertices[k].cordI)
                    Sudoku.addArestas (i,k);
                
                //Arestas mesma coluna
                if(Sudoku.Vertices[i].cordJ == Sudoku.Vertices[k].cordJ)
                    Sudoku.addArestas (i,k);

                //Arestas mesmo quadrante
                if(((Sudoku.Vertices[i].cordI/linhasQuadrante) == (Sudoku.Vertices[k].cordI/linhasQuadrante)) 
                    && (Sudoku.Vertices[i].cordJ/colunasQuadrante) == (Sudoku.Vertices[k].cordJ/colunasQuadrante)){
                    if(!Sudoku.existeAresta(i,k))
                        Sudoku.addArestas (i,k);
                    }
            }
        }
        
    }

    Sudoku.coloreVertices();


    if(Sudoku.verificaSolucao())
        cout<<"solucao"<<endl;
    else
        cout<<"sem solucao"<<endl;


int quebraLinha=0;
for (int i=0; i<Sudoku.numVertices; i++){

    if(quebraLinha != ladoSudoku){
        cout<<Sudoku.Vertices[i].valor<<" ";
        quebraLinha ++;
        
    }
    else if (quebraLinha == ladoSudoku){
        cout<<'\n'<<Sudoku.Vertices[i].valor<<" ";;
        quebraLinha = 1;
    }
   if (i == 15)
    cout<<'\n';

}



return 0;
}