#include "graph.hpp"

Graph::Graph(int nVertices, int ladoSudoku){
    this->numVertices = nVertices;
    this->ladoSudoku = ladoSudoku;
    this->solucao = false;

}


Vertice::Vertice(int IdVertice, int valor){
    this->idVertice = IdVertice;
    this->valor = valor;
    this->saturacao = 0;

    if(valor == 0)
        color = false;
}

//Adiciona aresta já computando a saturação do vertice (cores diferentes dos seus vizinhos)
void Graph::addArestas(int idA, int idB){

    if(!existeAresta(idA,idB));
    Vertices[idA].adj.push_back(Vertices[idB]);
    int repeteCor = 0;


    if (Vertices[idB].valor != 0){

        for(auto cor : Vertices[idA].coresVizinhos){
        repeteCor = 0;
            if (cor == Vertices[idB].valor)
                repeteCor++;
        }

        if (repeteCor == 0){
            Vertices[idA].coresVizinhos.push_back(Vertices[idB].valor);
            Vertices[idA].saturacao +=1;
        }
    }
}


void Graph::addVertices(Vertice v){
    Vertices.push_back(v);
}



void Vertice::printList(){
    for(int i=0; i<this->adj.size(); i++)
   // cout<< adj.size()<<endl;
    cout <<"Vertice  "<<this->idVertice<<" se relaciona com Vertice "<<adj[i].idVertice<<endl;
}

void Graph::verListaVertices(){
        for (int i=0;i<this->Vertices.size();i++){
            this->Vertices[i].printList();
        }
}


bool Graph::existeAresta(int idA, int idB){

    for(auto it : Vertices[idA].adj){
        if (it.idVertice == idB)
            return true;
    }

     return false;   

}

void Graph::coloreVertices(){
    
        //Percorro por vertice com o maior Grau de Saturacao que não tem valor
        int maiorValorPermitido = ladoSudoku-1;

        for (int i=0;i<numVertices;i++){
           if (!Vertices[i].color)
                if(Vertices[i].valor == 0){
                    if(!Vertices[i].buscaValor(maiorValorPermitido)){
                        Vertices[i].valor = maiorValorPermitido;
                        Vertices[i].color = true;
                        maiorValorPermitido = ladoSudoku-1;
                        //Toda vez que houver uma adição de Valor no Sudoku recalcula a saturação
                        calculaSat();
                    }
                    else
                        maiorValorPermitido--;
                    }
           }     

}

bool Graph::verificaSolucao(){
    for (int i = 0; i<numVertices; i++){
       
        for (int j =0; j<Vertices[i].adj.size();j++){
            if(Vertices[i].valor == Vertices[i].adj[j].valor)
            return false;
        }
    }
    return true;
}


bool Vertice::buscaValor(int valor){

    for(int i = 0; i<this->adj.size();i++){
        if(valor == this->adj[i].valor)
            return true;
    }

    return false;
}


void Graph::calculaSat(){

    for(int i = 0; i<numVertices;i++){
        for(int j =0; j<Vertices[i].adj.size();j++){
            if(Vertices[i].adj[j].valor !=0)
                this->Vertices[i].saturacao +=1;
        
        }
    }
}