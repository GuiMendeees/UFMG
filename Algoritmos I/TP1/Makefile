OBJS	= graph.o main.o
SOURCE	= graph.cpp main.cpp
HEADER	= graph.hpp
OUT	= tp1
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

graph.o: graph.cpp
	$(CC) $(FLAGS) graph.cpp -std=c11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c11


clean:
	rm -f $(OBJS) $(OUT)