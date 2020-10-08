#include "graph.hpp"

Graph::Graph(int nVertices){
    this->numVertices = nVertices;
}


Vertice::Vertice(int idade, int idEntrada){
    this->idade = idade;
    this->indiceEntrada = idEntrada;
}


void Graph::addArestas(int idA, int idB){
    Vertices[idA].adj.push_back(Vertices[idB]);

}

void Graph::addVertices(int indiceEntrada, int idade){
    Vertice V(idade,indiceEntrada);
    Vertices.push_back(V);
}


void Graph::swap(int idA, int idB, bool * troca){
    //Procura o elemento B na lista de Adjacencia de A e o remove
    *troca = false;
    for (int i = 0; i<Vertices[idA].adj.size();i++){
        if (Vertices[idA].adj[i].indiceEntrada == idB){//Se houver aresta troca
            Vertices[idA].adj.erase(Vertices[idA].adj.begin()+i);//Tira a relação A-B
            Vertices[idB].adj.push_back(Vertices[idA]);//Insere a relaçao B-A
            *troca = true;// Marca o controlador troca como verdadeiro
        }

    } 
}

 
void Graph::commander(int A){//Para cada vertice V do Grafo busco se o Vertice A desejado é subordinado a algum V, 
//se sim compara qual é o mais novo
    bool subordinado = false;
    int commander = 1000;

    for (int i = 0; i<numVertices;i++){//Laço que cobre os Vertices do Grafo
        for (int j=0; j < Vertices[i].adj.size(); j++){//Laço que percorre a lista de cada vertice
            if(Vertices[i].adj[j].indiceEntrada == A){ //Se encontrar o vertice A na lista de algum vertice do Grafo 
                if (Vertices[i].idade < commander){ //Verifico se este vértice é o mais "novo"
                    commander = Vertices[i].idade; //Se sim o commander tem essa idade
                    subordinado = true; // Há um subordinado para o vértice
                }
            }
        }
    
    }

    if (subordinado == false) // Siginifica que não tem Chefe
        cout<<"C *"<<endl;
    else
        cout<<"C "<<commander<<endl;
   
} 


void Vertice::printList(){
    for(int i=0; i<this->adj.size(); i++)
        cout <<"Id "<<this->indiceEntrada+1<<" se relaciona com id "<<adj[i].indiceEntrada+1<<endl;
}

void Graph::verListaVertices(){
        for (int i=0;i<this->Vertices.size();i++){
            this->Vertices[i].printList();
        }
}

// Função baseada no algoritmo de DFS
bool Graph::verificaCiclosAux(int idVertice, bool visited[], bool *recStack) { 
    if(visited[idVertice] == false) { 
        // Marca todos os vertices da etapa recursiva como visitados e os coloca numa pilha de entrada na chamada recursiva.  
        visited[idVertice] = true;
        recStack[idVertice] = true; 
  
        //Empiha todos os vertices vizinhos 
        vector<Vertice>::iterator i; 

        for(i = Vertices[idVertice].adj.begin(); i != Vertices[idVertice].adj.end(); i++) {
            int indice = i->indiceEntrada;
            if ( !visited[indice] && verificaCiclosAux(indice, visited, recStack) ) 
                return true; 
            else if (recStack[indice]) 
                return true; 
        } 
  
    } 
    recStack[idVertice] = false;  // Remove o vertice da pilha 
    return false; 
} 
  
bool Graph::verificaCiclos(){ 
    // Marca todos os vertices como não visitados 
    bool *visited = new bool[numVertices]; 
    bool *recStack = new bool[numVertices]; 
    for(int i = 0; i < numVertices; i++) { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Recursivamente chama o Auxiliar para todas as subarvores do vertices atual e verifica se há ciclos 
    for(int idVertice = 0; idVertice < numVertices; idVertice++) 
        if (verificaCiclosAux(idVertice, visited, recStack)) 
            return true; 
  
    return false; 
} 


void Graph::meetingAux(int idVertice, bool visited[], stack<int>& Stack) { 
    //Marca o vertice da chamada como visitado
    visited[idVertice] = true; 
  
    //Recursivamente visita os vertices da 
    vector<Vertice>::iterator it;

    for (it = Vertices[idVertice].adj.begin(); it != Vertices[idVertice].adj.end(); it++) 
        if (!visited[it->indiceEntrada]) 
            meetingAux(it->indiceEntrada, visited, Stack); 
  
    // Push na pilha para o vertice atual caso ja tenha sido visitado 
    Stack.push(idVertice); 
} 
  
//Ordem topologica 
void Graph::meeting(){ 
    stack<int> Stack; 
  
    //Marca todos os vertices como não visitados 
    bool* visited = new bool[numVertices]; 
    for (int i = 0; i < numVertices; i++) 
        visited[i] = false; 
  
    // Chama a função auxiliar recursivamente para empilhar os vertices 
    for (int idVertice = 0; idVertice < numVertices; idVertice++) 
        if (visited[idVertice] == false) 
            meetingAux(idVertice, visited, Stack); 
  
    // Desempilha e imprime
    while (Stack.empty() == false) { 
        cout << Stack.top()+1 << " "; 
        Stack.pop(); 
    } 
} 