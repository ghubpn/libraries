/* LOCAL INCLUDES */
#include "Matrix.h"
#include "SquareMatrix.h"

/* STANDARD INCLUDES */
#include <iostream>
#include <vector>

/* MATRIX TEST */
void matrixTest() {
	cout << endl << "MATRIX TEST:" << endl;
	int r1 = 3;
	int c1 = 3;
	int r2 = 3;
	int c2 = 3;
	Matrix m1(r1,c1);
	m1(0,0,1);
	m1(1,1,1);
	m1(1,2,1);
	Matrix m2(r2,c2);
	m2(0,0,2);
	m2(1,1,2);
	m2(2,1,4);
	Matrix m3(r1,c1);
	m3 = m1.transpose();
	// print m1
	for ( int i = 0; i < r1; ++i ) {
		for ( int j = 0; j < c1; ++j ) {
			cout << m1(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	// print m2
	for ( int i = 0; i < r2; ++i ) {
		for ( int j = 0; j < c2; ++j ) {
			cout << m2(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	// print m3
	for ( int i = 0; i < r1; ++i ) {
		for ( int j = 0; j < c2; ++j ) {
			cout << m3(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/* SQUARE MATRIX TEST */
void squareMatrixTest() {
	int d = 4;
	SquareMatrix m(d);
	SquareMatrix m2(d);
	m(0,0,1);
	m(1,1,1);
	m(1,2,1);
	//m= m*m2;
	//SquareMatrix m2(d);
	//m2 = m.gaussian();
	cout << endl;
	// print m
	for ( int i = 0; i < d; ++i ) {
		for ( int j = 0; j < d; ++j ) {
			cout << m(i,j) << " ";
		}
		cout << endl;
	}
	
}
