#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#define BUFSZ 1024



int main(int argc, char **argv) {
//-----------------------------###### Inicio bloco de configuração do Servidor #############################-----------------------

    //Instância do endereço e porto passados via linha de comando
    struct sockaddr_storage storage;

    if(0 != server_sockaddr_init(argv[1],argv[2],&storage)){
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
//-----------------------------###### Fim bloco de configuração do Servidor #############################-----------------------
//-----------------------------###### Inicio do bloco de bind do Servidor com Cliente #############################-----------------------
    
    //Bind com o Cliente
    if(0 != bind(s, addr, sizeof(storage))){
        logexit("Bind");
    }

    //Maximo de Conexões pendentes para o servidor
    if (0 != listen(s, 50)){
        logexit("Listen");
    }

    //Variavel que recebe o endereço para bind em formato de string
    char addrstr[BUFSZ];

    //Função que recebe o valor de addr, transforma em string e armazena no array de char(string) addrstr
    addrtostr(addr, addrstr, BUFSZ);

    printf("BOUND AO ENDERECO %s \n", addrstr);


    while(1){
        struct sockaddr_storage client_storage;
        struct sockaddr * client_addr = (struct sockaddr *) (&client_storage);
        socklen_t caddrlen = sizeof(client_storage);

        //Ao aceitar a conexão acept cria novo socket com identificações de cada cliente para comunicar
        //O socket s é o que permite a conexão
        int cliente_socket = accept(s, client_addr, &caddrlen);

        if (cliente_socket == -1){
            logexit("Cliente Socket Error");
        }

        //Variavel que recebe o endereço cliente que está conectado com o servidor em formato de string
         char caddrstr[BUFSZ];

        //Função que recebe o valor do addr do cliente , transforma em string e armazena no array de char(string) addrstr
        addrtostr(client_addr, caddrstr, BUFSZ);

        printf("Conectado ao cliente %s \n", caddrstr);

    

//-----------------------------###### Fim do bloco de bind do Servidor com Cliente #############################-----------------------
//-----------------------------###### Inicio do bloco de Recebimento de dados do  Cliente #############################-----------------------
    
    //Inicializa um buffer especifico para RECEBER os dados do CLIENTE
    char buffRecebido[BUFSZ];
    
    //Instancia 0 ao buffer
    memset(buffRecebido,0,BUFSZ);

    //Controla o numero de bytes recebidos
    size_t count = recv(cliente_socket,buffRecebido,BUFSIZ,0);

    //TODO: TRATAR QUE A CONEXÃO SÓ PODE SER ENCERRADA QUANDO VIER KILL DO CLIENTE
    //Ver se o BUFF == "KILL" ?

    printf("Cliente %s : Mensagem: %s , total de bytes %d", caddrstr, buffRecebido, (int)count);
    //Envia pro cliente uma resposta
    send(cliente_socket,buffRecebido,(strlen(buffRecebido)+1),0);
    
    if (count != (strlen(buffRecebido)+1)){
        logexit("Error Recebimento de dados");
    }

    //Fecha a conexão e volta no While para tratar a próxima conexão do cliente
    close(cliente_socket);
    
    }
exit(EXIT_SUCCESS);

}