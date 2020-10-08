OBJS	= main.o graph.o
SOURCE	= main.cpp graph.cpp
HEADER	= graph.hpp
OUT	= tp3
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

graph.o: graph.cpp
	$(CC) $(FLAGS) graph.cpp 


clean:
	rm -f $(OBJS) $(OUT)
