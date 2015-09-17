OBJ = debug.o random.o

test:	$(OBJ)
	g++ -o debug $(OBJ)

debug.o:	debug.cpp
	g++ -c debug.cpp

random.o:	random.cpp
	g++ -c random.cpp

clean:
	rm -f *.o 