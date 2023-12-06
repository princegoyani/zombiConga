OBJS = hw5_goyani_prince.o
EXE = exe
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
FLAG = -Wall $(DEBUG)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE) -lm

Zombie: hw5_goyani_prince.o
	$(CC) $(CFLAGS) hw5_goyani_prince.cpp -lm

goyani_prince_assn3.o: hw5_goyani_prince.cpp Conga.hpp linkedlist_goyani.hpp Node.hpp zombie.hpp
	$(CC) $(CFLAGS) hw5_goyani_prince.cpp -lm

clean:
	rm *.o $(EXE) -v