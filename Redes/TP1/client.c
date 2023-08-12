#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


//Buffer é tamanho pra escrita e leitura de dados
#define BUFSZ 1024

int main(int argc, char **argv) {
//-----------------------------###### Inicio bloco de configuração do Cliente #############################-----------------------
    //Instância do endereço e porto passados via linha de comando
    struct sockaddr_storage storage;

    if(0 != addrparse(argv[1],argv[2],&storage)){
        logexit("Erro criação Struct addr");
    }

    //Declarando objeto Socket
    int s = socket(storage.ss_family, SOCK_STREAM,0);

    //Verificando erro atraves do retorno da criação do socket
    if(s == -1){
        logexit("socket");        
    }


    //Interface abstrata que lida com ipV4 e ipV6 e aponta para a instancia storage
    //Há o cast do tipo storage para o addr
    struct sockaddr *addr = (struct sockaddr *) (&storage);
//-----------------------------###### Fim bloco de configuração do Cliente #############################-----------------------
//-----------------------------###### Inicio do bloco de conexão do Cliente com Servidor #############################-----------------------


    //Avalia a conexão, se a função connect retornar algo diferente de 0 é porque tem alguma coisa errada
    if (0 != connect(s,addr, sizeof(storage))){
        logexit("connect");
    }

    //Variavel que recebe o endereço para conexão em formato de string
    char addrstr[BUFSZ];

    //Função que recebe o valor de addr, transforma em string e armazena no array de char(string) addrstr
    addrtostr(addr, addrstr, BUFSZ);

    printf("CONECTADO AO ENDERECO %s \n", addrstr);


//-----------------------------###### Fim do bloco de conexão do Cliente com Servidor #############################-----------------------

//-----------------------------###### Inicio bloco de envio de Mensagem ao Servidor ####################-----------------------
    //Inicializa um buffer especifico para ENVIAR os dados do SERVIDOR
    char bufEnviado[BUFSZ];

    //Instancia 0 ao buffer
    memset(bufEnviado,0,BUFSZ);
    
    //Le do teclado e salva no bufEnviado
    fgets(bufEnviado,(BUFSZ-1),stdin);

    //Count armazena o valor de bytes transmitidos na rede 
    size_t count = send(s,bufEnviado, strlen(bufEnviado)+1,0);

    if(count != strlen(bufEnviado)+1){
        logexit("Send");
    }
//-----------------------------###### Fim bloco de envio de Mensagem ao Servidor ####################-----------------------
//-----------------------------###### Inicio do bloco de Recebimento de dados do Servidor ####################-----------------------


    //Inicializa um buffer especifico para RECEBER os dados do SERVIDOR
    char buffRecebido[BUFSZ];
    
    //Instancia 0 ao buffer
    memset(buffRecebido,0,BUFSZ);
    
    //Variavel que controla os bytes recebidos, nao necessariamente o servidor transmite tudo de uma vez
    unsigned total = 0;

    while(1){
        //Controla a quantidade de bytes recebidos pelo servidor
        count = recv(s, buffRecebido+total, BUFSZ - total,0);

        //Se não há mais transmissão de dados pelo servidor
        if (count == 0){
            break;
        
        }

        //Adiciona a quantidade já transmitidade
        total += count; 
    }







  /*  Arquitetura de Receber as linhas 
        if (1º arg linha == "list"){
            //processo de listar as coisas adicionadas
        }
        else if (1º arg linha == "kill"){
            //Encerra as conexões
        }
    
        else if (1º arg linha == "add"){
            //adiciona argv[1] -> X e argv[2] -> Y na matriz de coordenadas (Estrutura de dados ainda não definida)
        }

        else if (1º arg linha == "rm"){
            //remove argv[1] -> X e argv[2] -> Y na matriz de coordenadas (Estrutura de dados ainda não definida)
            
        }

        else if (1º arg linha == "query"){
            //seleciona na matriz de coordenadas (Estrutura de dados ainda não definida)
            // locais mais próximos de argv[1] -> X e argv[2] -> Y
        }

        else {
            //ERROR DE COMANDO
        }
    }

*/
    //Encerra o Socket
    close(s);
	exit(EXIT_SUCCESS);
}