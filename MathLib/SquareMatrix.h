#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Matrix.h"

using namespace std;

class SquareMatrix : public Matrix {

	public:
		SquareMatrix( int d );
		SquareMatrix( SquareMatrix& m );
		SquareMatrix inverse();
	
	private:
		
	
};

#endif