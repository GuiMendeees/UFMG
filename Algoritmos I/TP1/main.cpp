#include "graph.hpp"
#include <fstream>
#include<iostream>
#include <string>
#include<vector>
#include <chrono>

//Para deixar o codigo mais limpo fica predefinido escopo std
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;


//Variáveis que recebem as linhas de comandos
int numAlunos; 
int numRelacionamentos;
int numComandos;
bool troca;
string nomeArquivo;
int tempo=0;

int main(int argc, char** argv){

//Captura o horario pré execução
//high_resolution_clock::time_point t1 = high_resolution_clock::now();

     //Variavel responsável por receber o arquivo com a entrada de dados
     nomeArquivo = argv[1];
     ifstream arquivo (nomeArquivo);

     //Obtem a quantidade de Alunos, Relacionamentos, Instruções
     arquivo >> numAlunos >> numRelacionamentos >> numComandos;
     
     Graph Grafo(numAlunos);


     for (int i=0; i<numAlunos;i++){
          int recebeIdades;
          arquivo >> recebeIdades;
          Grafo.addVertices(i,recebeIdades);
     }


    for (int i=0; i<numRelacionamentos;i++){
          int idChefe,idSubordinado;
          arquivo >> idChefe >> idSubordinado;
          Grafo.addArestas((idChefe-1),(idSubordinado-1));
         
    }


    for (int i=0; i<numComandos;i++){
          char comando;
          int A,B;
          arquivo >> comando;

         if(comando == 'M'){
               cout<<"M ";
              Grafo.meeting();
          }

          if(comando == 'C'){
               arquivo>>A;
               Grafo.commander((A-1));
               
          }

          if (comando == 'S'){     
               arquivo >> A >> B;
               Grafo.swap((A-1),(B-1), &troca);
               //Caso a troca gere um ciclo, ela é desfeita e o controle troca é falso
               if(Grafo.verificaCiclos()){
                    Grafo.swap((B-1),(A-1),&troca);
                    troca = false;
               }
              
               if(troca)
                    cout<<"S T"<<endl;
               else 
                    cout<<"S N"<<endl;
          }
         
    }

/*//Medição Pos Execução
high_resolution_clock::time_point t2 = high_resolution_clock::now();
duration<double, std::micro> elapsed_time = duration_cast<duration<double>>(t2 - t1); 
tempo = elapsed_time.count();


cout<<'\n'<<"Tempo decorrido: "<<endl;
cout<<tempo<<" microsegundos"<<endl;*/

return 0;
}