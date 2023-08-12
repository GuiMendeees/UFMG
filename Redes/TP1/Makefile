all:
	gcc -Wall -c utils.c
	gcc -Wall client.c utils.o -o client
	gcc -Wall server.c utils.o -o server
	gcc -Wall server-mt.c utils.o -lpthread -o server-mt

clean:
	rm utils.o client server server-mt
