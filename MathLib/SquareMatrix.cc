#include "SquareMatrix.h"

// constructors, destructors
SquareMatrix::SquareMatrix( int d ) : Matrix(d,d) {
	for (int i = 0; i < d*d; ++i)
		elems.push_back(0);
}

SquareMatrix::SquareMatrix( SquareMatrix& m )
: Matrix( m.dimR, m.dimC ) {
	for (int i = 0; i < (m.dimR)*(m.dimC); ++i )
		elems.push_back(m.elems[i]);
}

// maths
SquareMatrix SquareMatrix::inverse() {
	if ( this->dimR != this->dimC )
		exit(1);
	SquareMatrix g(this->dimR);
	// DOME
	return g;
}