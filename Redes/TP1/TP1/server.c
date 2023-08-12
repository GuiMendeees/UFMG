#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include <sys/socket.h>
#include <sys/types.h>

#define BUFSZ 500
#define MAXPTS 50

void usage(int argc, char **argv) {
    printf("usage: %s <v4|v6> <server port>\n", argv[0]);
    printf("example: %s v4 51511\n", argv[0]);
    exit(EXIT_FAILURE);
}


typedef struct ponto{
	int X;
	int Y;
} Ponto;

int distancia(Ponto A, Ponto B){
	return sqrt( pow((A.X - B.X), 2) + pow((A.Y - B.Y), 2) );
}

char* substr(const char *src, int m, int n){
    
    int len = n - m;
 
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
 
    strncpy(dest, (src + m), len);
 
    return dest;
}


int main(int argc, char **argv) {

//São no máximo 50 locais
Ponto pontos[MAXPTS];
int ptsCadastrados = 0;
int x,y = 0;

    if (argc < 3) {
        usage(argc, argv);
    }

    struct sockaddr_storage storage;
    if (0 != server_sockaddr_init(argv[1], argv[2], &storage)) {
        usage(argc, argv);
    }

    int s;
    s = socket(storage.ss_family, SOCK_STREAM, 0);
    if (s == -1) {
        logexit("socket");
    }

    int enable = 1;
    if (0 != setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int))) {
        logexit("setsockopt");
    }

    struct sockaddr *addr = (struct sockaddr *)(&storage);
    if (0 != bind(s, addr, sizeof(storage))) {
        logexit("bind");
    }

    if (0 != listen(s, 10)) {
        logexit("listen");
    }

    char addrstr[BUFSZ];
    addrtostr(addr, addrstr, BUFSZ);
    //printf("bound to %s, waiting connections\n", addrstr);

        //int disconnect = 0;
        struct sockaddr_storage cstorage;
        struct sockaddr *caddr = (struct sockaddr *)(&cstorage);
        socklen_t caddrlen = sizeof(cstorage);

        int csock = accept(s, caddr, &caddrlen);
        if (csock == -1) {
            logexit("accept");
        }

        char caddrstr[BUFSZ];
        addrtostr(caddr, caddrstr, BUFSZ);
        //printf("[log] connection from %s\n", caddrstr);
        char buf[BUFSZ];  
        memset(buf, 0, BUFSZ);
        size_t count;

    while ((count = recv(csock, buf, BUFSZ - 1, 0)) > 0) {
        
        //printf("[msg] %s, %d bytes: %s\n", caddrstr, (int)count, buf);
        
        if ((strncmp("kill",buf,4) == 0) || (count == 0)){
		    //disconnect = 1;
		    //printf("Strcmp identificou palavra kill\n");
            //printf("Valor de disconnect é %d", disconnect);
            sprintf(buf, "desconectar");
            //printf("buffer tem que ser disconnect = %s",buf);
        }
        //sprintf(buf, "remote endpoint: %.1000s\n", caddrstr);
        //Envia a flag de disconnect
        
       else{
           char bufferRecebido[sizeof(buf)];
           strcpy(bufferRecebido,buf);
 //---------------##### Aqui será a tratativa do buffer recebido  para enviar as informações
 //----Lembrar que pra instanciar o ponto deve colocar Ponto p1, Ponto p2 depois p1.X e p1.Y = ...
            //5 porque é o tamanho máximo de um comando, no caso query
            //char* comando;
            //char delimitador[2] = " ";
            //comando = strtok(bufferRecebido, delimitador);

            int flSpace1 = 0;

            while (bufferRecebido[flSpace1] != ' '){
                flSpace1 +=1;
            }

            char* comando = substr(bufferRecebido, 0, flSpace1);
            if((strncmp(comando,"add",3)== 0) || (strncmp(comando, "rm",2)== 0) ||(strncmp(comando, "query",5)== 0)){
                int flSpace2 = flSpace1+1;

                while (bufferRecebido[flSpace2] != ' '){
                    flSpace2 +=1;
                }

                char* xString = substr(bufferRecebido, flSpace1, flSpace2);
                char* yString = substr(bufferRecebido, flSpace2, strlen(bufferRecebido));
            
                x = atoi(xString);
                y = atoi(yString);
/*          
            printf("Buffer : %s \n",buf);
            printf("Comando extraido : %s \n",comando);
            printf("X Convertido : %i \n",x);
            printf("Y Convertido : %i \n",y);
 */          
            }

            if(strncmp("add",comando,3) == 0){
                //Só Executar procedimento se as coordenadas estiverem no range permitido
                if((0 <= x) &&(x <= 9999) && (0 <= y)&& (y <= 9999)){
                    //Se tiver espaço para cadastro
                    if(ptsCadastrados <= MAXPTS){
                        int fl_ptJaCadastrado = 0;

                        //Confere se ponto já está cadastrado
                        for (int i = 0 ; i<ptsCadastrados; i++){
                            //Se já tiver ponto retorna Mensagem que já existe
                            if((pontos[i].X == x) && (pontos[i].Y == y)){
                                fl_ptJaCadastrado +=1;
                                sprintf(buf,"%i %i already exists\n", x,y);
                            }
                        
                        }

                        //Se a flag de ponto ja cadastrado for falsa adiciona
                        if(fl_ptJaCadastrado == 0){
                            //printf("Passou no if do Comando Add \n");
                            pontos[ptsCadastrados].X = x;
                            pontos[ptsCadastrados].Y = y;

                            //printf("Valor de Xponto cadastro %i\n", pontos[ptsCadastrados].X);
                            //printf("Valor de Yponto cadastro %i\n", pontos[ptsCadastrados].Y);
                            sprintf(buf,"%i %i added\n",x,y);
                            ptsCadastrados +=1;
               
                            //printf("Total de Pontos Cadastrados %i\n", ptsCadastrados);
                        }
                    }
                    //Se já houver a quantidade máxima de pontos cadastrados retorna limite excedido
                    else{
                        sprintf(buf,"limit exceeded\n");
                    }
                }
                else{
                    sprintf(buf,"Invalid coordinates\n");
                }
 
            }

           

            else if(strncmp("list",comando,4) == 0){
                char bufList[BUFSZ];
                if(ptsCadastrados>0){
                    char bufTemp[BUFSZ];
                    //printf("Entrou no if list\n");
                    for(int i = 0; i < ptsCadastrados; i++){
                        //printf("Passou no for\n");
                        //printf("Ponto da posicao %i: X = %i, Y=%i \n",i,pontos[i].X,pontos[i].Y);
                        //Armazeno o valor do Ponto em bufList
                        sprintf(bufTemp,"%i %i ",pontos[i].X,pontos[i].Y);
                        //Concateno o buffer recebido no buffer que vai ser enviado
                        strcat(bufList, bufTemp);
                    }
                    strcat(bufList,"\n");
                    strcpy(buf,bufList);
                }
                else{
                    //Nenhum ponto cadastrado
                    sprintf(buf,"none\n");
                }
            }

            else if(strncmp("rm",comando,2) == 0){
                //Variavel que controla se a operação ja foi realizada
                int fl_Op = 0;
                if((ptsCadastrados > 0) && (fl_Op ==0)){
                    int fl_ptRemover = 0;
                    int pontoRemover = 0;
                    //Identifica o indice do ponto a ser removido
                    for(int i = 0; i < ptsCadastrados; i++){
                        if((pontos[i].X == x) && (pontos[i].Y == y)){
                            fl_ptRemover = 1;
                            pontoRemover = i;
                        }
                        else{
                            //Ponto não encontrado
                            sprintf(buf,"%i %i does not exist\n", x,y); 
                        }
                    }
                    //Se a flag achou ponto a ser removido executa rotina de remover
                    if(fl_ptRemover == 1){
                        sprintf(buf,"%i %i removed\n",pontos[pontoRemover].X,pontos[pontoRemover].Y);
                        for(int i = pontoRemover; i<ptsCadastrados; i++){
                            pontos[i].X = pontos[i+1].X;
                            pontos[i].Y = pontos[i+1].Y;
                        }
                    fl_Op = 1;
                    ptsCadastrados -=1;
                    }
                }
                else{
                    //Nenhum ponto cadastrado
                    sprintf(buf,"none\n");
                }
            
            }

            else if(strncmp("query",comando,5) == 0){
                if(ptsCadastrados>0){
                    //Marca o indice do ponto mais proximo
                    int ptProximo = 0;
                    //Marca a menor distancia encontrada para comparação
                    //Setado em 9999 para sempre calcular a menor distancia a partir do primeiro ponto
                    int menorDistancia = 9999;
                    //Instancia um ponto para comparar com os cadastrados
                    Ponto p;
                    p.X = x;
                    p.Y = y;

                    for (int i = 0; i< ptsCadastrados; i++){
                        //Se a distancia encontrada for menor que a atual troca
                        if(menorDistancia > distancia(p, pontos[i])){
                            menorDistancia = distancia(p, pontos[i]);
                            ptProximo = i;
                        } 
                    }
                    sprintf(buf,"%i %i\n",pontos[ptProximo].X,pontos[ptProximo].Y);
                    //printf("Pt mais próximo é %i, X %i, Y %i\n", ptProximo,pontos[ptProximo].X,pontos[ptProximo].Y);
                }
                else{
                    //Nenhum ponto cadastrado
                    sprintf(buf,"none\n");
                }
            }

            else{//Comando não cadastrado
                sprintf(buf,"none\n");
            }
            //sprintf(buf, "está comunicando\n");
       }
        size_t countSend  =  write(csock , buf , strlen(buf));
        //size_t countSend = send(csock, buf, strlen(buf), 0);
        

        if (countSend != strlen(buf)) {
            logexit("send");
        }
    //printf("Dentro do While\n");
    }
    //printf("Conexão Fechando\n");
    close(csock);
    
    exit(EXIT_SUCCESS);
}