#ifndef MATRIX_H
#define MATRIX_H

#include "Matrix_Error.h"

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix {

public:
	/* CONSTRUCTORS / DESTRUCTORS */
	Matrix( int r, int c );
	Matrix( Matrix& m );
	
	/* GETTERS / SETTERS */
	void set( int r, int c, T val );
	void operator()( int r, int c, T val );
	T    get( int r, int c );
	T    operator()( int r, int c );
	
	/* GET BOUNDS */
	int  getDimR();
	int  getDimC();
	
	/* MATHEMATICAL FUNCTIONS */
	//Matrix operator=( Matrix m );
	
	Matrix operator+( Matrix m );
	Matrix operator-( Matrix m );
	Matrix operator*( T k ); // scalar
	Matrix operator*( Matrix m ); // matrix
	
	Matrix operator+=( Matrix m );
	Matrix operator-=( Matrix m );
	Matrix operator*=( T k ); // scalar
	Matrix operator*=( Matrix m ); // matrix
	
	Matrix transpose();
	Matrix gaussian(); // Gaussian elimination
	
protected:
	/* DATA MEMBERS */
	int       dimR;
	int       dimC;
	vector<T> elems;

	/* (NON-PUBLIC) UTILITY FUNCTIONS */
	void swapTwoRows( int r1, int r2 );
	void multiplyRow( int r, T k );
	void addTwoRows( int r1, int r2, T k );
};

#endif