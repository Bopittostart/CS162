CC = g++
CFLAGS = -g -Wall
EXE = run_cafe

$(EXE): shop.o menu.o order.o coffee.o display.o prog.cpp
	$(CC) $(CFLAGS) shop.o menu.o order.o coffee.o display.o prog.cpp -o $(EXE)

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp 

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp  

coffee.o: coffee.cpp coffee.h 
	$(CC) -c coffee.cpp 

display.o: display.cpp display.h
	$(CC) -c display.cpp

clean:
	rm -f *.o $(EXE)