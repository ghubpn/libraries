OBJ = Main.o Matrix.o Matrix_Error.o Matrix_Tester.o

test:	$(OBJ)
	g++ -o test $(OBJ) -std=c++14

Main.o:	Main.cc
	g++ -c Main.cc -std=c++14
	
Matrix.o:	Matrix.cc
	g++ -c Matrix.cc -std=c++14
	
Matrix_Error.o:	Matrix_Error.cc
	g++ -c Matrix_Error.cc -std=c++14
	
Matrix_Tester.o:	Matrix_Tester.cc
	g++ -c Matrix_Tester.cc -std=c++14
	
clean:
	rm -f *.o 