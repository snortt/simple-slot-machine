CC=g++
CC_FLAGS=-std=c++14 -Wall 

all: slot game main

slot: slot.cpp
	$(CC) $(CC_FLAGS) -c slot.cpp -o slot.o

game: game.cpp
	$(CC) $(CC_FLAGS) -c game.cpp -o game.o

main: main.cpp
	$(CC) $(CC_FLAGS) slot.o game.o main.cpp -o slot_machine

.PHONY:
clean:
	-rm *.o slot_machine 

