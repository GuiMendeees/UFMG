#include "common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void usage(int argc, char **argv) {
	printf("usage: %s <server IP> <server port>\n", argv[0]);
	printf("example: %s 127.0.0.1 51511\n", argv[0]);
	exit(EXIT_FAILURE);
}

#define BUFSZ 500

int main(int argc, char **argv) {
	char bufEnviar[BUFSZ];
	char bufReceber[BUFSZ];
	//printf("Valor do Buffer antes do WHile:");
	//printf(buf);
//Enquanto não vir um comando kill ele envia e recebe dados ao servidor	
	int disconnect = 0;

	if (argc < 3) {
		usage(argc, argv);
	}
	while(!disconnect) {

	struct sockaddr_storage storage;
	if (0 != addrparse(argv[1], argv[2], &storage)) {
		usage(argc, argv);
	}

	int s;
	s = socket(storage.ss_family, SOCK_STREAM, 0);
	if (s == -1) {
		logexit("socket");
	}
	struct sockaddr *addr = (struct sockaddr *)(&storage);
	if (0 != connect(s, addr, sizeof(storage))) {
		logexit("connect");
	}

	char addrstr[BUFSZ];
	addrtostr(addr, addrstr, BUFSZ);

	//printf("connected to %s\n", addrstr);
//---------------------------------------### Envio de Dados

		memset(bufEnviar, 0, BUFSZ);
		//printf("mensagem> ");
		fgets(bufEnviar, BUFSZ-1, stdin);

		//printf("String recebida %s\n", bufEnviar);
		//STRNCMP compara caracter por caracter com um limite (despresa o /0 do stdin)
		//if (strncmp("kill",bufEnviar,4) == 0){
		//printf("Strcmp identificou palavra kill \n");}

	size_t count = send(s, bufEnviar, strlen(bufEnviar)+1, 0);

	if (count != strlen(bufEnviar)+1) {
		logexit("send");
	}

	
	

//---------------------------------------###Recebimento de Dados
	while (1){
		unsigned total = 0;
		memset(bufReceber, 0, BUFSZ);
		count = recv(s, bufReceber + total, BUFSZ - total, 0);
		if (count == 0) {
			// Connection terminated.
			break;}
		total += count;
		//printf("Mensagem do recv: %s\n",bufReceber);
		//char flagServer = bufReceber[0];
		//printf("FlagServer = %c\n", flagServer);

		if(strncmp(bufReceber,"desconectar",11) == 0){
			disconnect = 1;
			//printf("Disconnect = 1\n");
		}
		//Só exibe o retorno do servidor se não tiver sido a confirmação do Kill
		if(disconnect == 0){
			printf("%s", bufReceber);
		}
	}
	close(s);
	}
//}

	
	//puts(buf);

	exit(EXIT_SUCCESS);
}