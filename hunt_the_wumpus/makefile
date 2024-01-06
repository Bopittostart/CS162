CC=g++ -std=c++11 -g
exe=asm4


$(exe):  room.o event.o bats.o game.o gold.o stalactites.o wumpus.o rope.o main.cpp
	$(CC)  room.o event.o bats.o game.o gold.o stalactites.o wumpus.o rope.o main.cpp -o $(exe)

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp 

game.o: game.cpp game.h
	$(CC) -c game.cpp  

gold.o: gold.cpp gold.h 
	$(CC) -c gold.cpp 

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

rope.o: rope.cpp rope.h
	$(CC) -c rope.cpp

clean:
	rm -f *.o $(exe)
# Complete the makefile
# Your code here: 
