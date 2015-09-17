OBJ = debug.o fileIO.o

test:	$(OBJ)
	g++ -o run $(OBJ)

debug.o:	debug.cpp
	g++ -c debug.cpp

fileIO.o:	fileIO.cpp
	g++ -c fileIO.cpp

clean:
	rm -f *.o 