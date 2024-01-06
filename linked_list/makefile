CC = g++
CFLAGS = -g -Wall
EXE = run_list

$(EXE): linked_list.cpp test_linked_list.cpp
	$(CC) $(CFLAGS) linked_list.cpp test_linked_list.cpp -o $(EXE)

stairs.o: linked_list.cpp linked_list.h node.h
	$(CC) -c linked_list.cpp 

clean:
	rm -f *.o $(EXE)