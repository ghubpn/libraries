OBJ = debug.o sort.o

test:	$(OBJ)
	g++ -o run $(OBJ)

debug.o:	debug.cpp
	g++ -c debug.cpp

sort.o:	sort.cpp
	g++ -c sort.cpp

clean:
	rm -f *.o 
