#include "Matrix.h"

/*
 * CONSTRUCTORS / DESTRUCTORS
 *		-default constructor
 *      -copy constructor
*/

// default constructor
template<typename T>
Matrix<T>::Matrix( int r, int c ) : dimR(r), dimC(c) {
	for (int i = 0; i < r*c; ++i)
		elems.push_back(0);
}

// copy constructor
template<typename T>
Matrix<T>::Matrix( Matrix<T>& m ) : dimR(m.dimR), dimC(m.dimC) {
	for (int i = 0; i < (m.dimR)*(m.dimC); ++i )
		elems.push_back(m.elems[i]);
}

/*
 * GETTERS / SETTERS
 *		-set element
 *      -set element operator: ()
 *      -get element
 *      -get element operator: ()
*/

// set element
template<typename T>
void Matrix<T>::set( int r, int c , T val) {
	if ( r < 0 || r > dimR || c < 0 || c > dimC )
		outOfBounds_Exception();
	elems[r*dimC + c] = val;
}

// set element operator: ()
template<typename T>
void Matrix<T>::operator()( int r, int c, T val ) {
	this->set(r,c,val);
}

// get element
template<typename T>
T Matrix<T>::get( int r, int c ) {
	if ( r < 0 || r > dimR || c < 0 || c > dimC )
		exit(1);
	return elems[r*dimC + c];
}

// get element operator: ()
template<typename T>
T Matrix<T>::operator()( int r, int c ) {
	return this->get(r,c);
}

/*
 * GET BOUNDS
 *		-get total number of rows
 *      -get total number of columns
*/

// get total number of rows
template<typename T>
int Matrix<T>::getDimR() {
	return dimC;
}

// get total number of columns
template<typename T>
int Matrix<T>::getDimC() {
	return dimC;
}

/*
 * MATHEMATICAL FUNCTIONS
 *		-assignment operator: =
 *      -matrix addition operator: +
 *      -matrix subtraction operator: -
 *      -scalar multiplication operator: *
 *		-matrix multiplication operator: *
 *      -matrix addition assignment operator: +=
 *      -matrix subtraction assignment operator: -=
 *      -scalar multiplication assignment operator: *=
 *		-matrix multiplication assignment operator: *=
 *      -transpose
 *      -reduced row echelon form
*/
/*
// assignment operator: =
Matrix Matrix::operator=( Matrix m ) {
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	for ( int i = 0; i < dimR*dimC; ++i )
		this->elems[i] = m.elems[i];
	return *this;
}
*/
// matrix addition operator: +
template<typename T>
Matrix<T> Matrix<T>::operator+( Matrix m ) {
	Matrix s( dimR, dimC );
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	for ( int i = 0; i < dimR*dimC; ++i )
		s.elems[i] = this->elems[i] + m.elems[i];
	return s;
}

// matrix subtraction operator: -
template<typename T>
Matrix<T> Matrix<T>::operator-( Matrix m ) {
	Matrix s( dimR, dimC );
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	for ( int i = 0; i < dimR*dimC; ++i )
		s.elems[i] = this->elems[i] - m.elems[i];
	return s;
}

// scalar multiplication operator: *
template<typename T>
Matrix<T> Matrix<T>::operator*( T k ) {
	Matrix m( dimR, dimC );
	for ( int i = 0; i < dimR*dimC; ++i )
		m.elems[i] = this->elems[i] * k;
	return m;
}

// matrix multiplication operator: *
template<typename T>
Matrix<T> Matrix<T>::operator*( Matrix m ) {
	Matrix p(this->dimR, m.dimC);
	if ( this->dimC != m.dimR )
		exit(1);
	for ( int i = 0; i < this->dimR; ++i )
		for ( int j = 0; j < m.dimC; ++j )
			for ( int k = 0; k < this->dimC; ++k )
				p.elems[i*m.dimC+j] += (this->get(i,k) * m.get(k,j));
	return p;
}

// matrix addition assignment operator: +=
template<typename T>
Matrix<T> Matrix<T>::operator+=( Matrix m ) {
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	for ( int i = 0; i < dimR*dimC; ++i )
		this->elems[i] += m.elems[i];
	return *this;
}

// matrix subtraction assignment operator: -=
template<typename T>
Matrix<T> Matrix<T>::operator-=( Matrix m ) {
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	for ( int i = 0; i < dimR*dimC; ++i )
		this->elems[i] -= m.elems[i];
	return *this;
}

// scalar multiplication assignment operator: *=
template<typename T>
Matrix<T> Matrix<T>::operator*=( T k ) {
	for ( int i = 0; i < dimR*dimC; ++i )
		this->elems[i] *= k;
	return *this;
}

// matrix multiplication assignment operator: *=
template<typename T>
Matrix<T> Matrix<T>::operator*=( Matrix m ) {
	if ( this->dimR != m.dimR || this->dimC != m.dimC )
		exit(1);
	Matrix p(this->dimR, this->dimC);
	for ( int i = 0; i < this->dimR; ++i )
		for ( int j = 0; j < m.dimC; ++j )
			for ( int k = 0; k < this->dimC; ++k )
				p.elems[i*m.dimC+j] += (this->get(i,k) * m.get(k,j));
	*this = p;
	return *this;
}

// transpose
template<typename T>
Matrix<T> Matrix<T>::transpose() {
	Matrix p(this->dimC, this->dimR);
	for ( int i = 0; i < p.dimR; ++i )
		for ( int j = 0; j < p.dimC; ++j )
			p.set(j,i,this->get(i,j));
	return p;
}

// reduced row echelon form
template<typename T>
Matrix<T> Matrix<T>::gaussian() {
	Matrix& g(*this);
	return g; // INCOMPLETE
}

/*
 * (NON-PUBLIC) UTILITY FUNCTIONS
 *		-swap two rows
 *      -multiply a row by a scalar constant
 *      -add a multiple of one row to another row
*/

// swap two rows
template<typename T>
void Matrix<T>::swapTwoRows( int r1, int r2 ) {
	if ( r1 < 0 || r1 > this->dimR || r2 < 0 || r2 > this->dimR )
		exit(1);
	int temp;
	for ( int i = 0; i < dimC; ++i ) {
		temp = this->get(r1,i);
		this->set(r1,i,this->get(r2,i));
		this->set(r2,i,temp);
	}
}

// multiply a row by a scalar constant
template<typename T>
void Matrix<T>::multiplyRow( int r, T k ) {
	if ( r < 0 || r > this->dimR || k == 0 )
		exit(1);
	for ( int i = 0; i < dimC; ++i )
		this->set(r,i,this->get(r,i)*k);
}

// add a multiple of one row to another row
template<typename T>
void Matrix<T>::addTwoRows( int r1, int r2, T k ) {
	if ( r1 < 0 || r1 > this->dimR || r2 < 0 || r2 > this->dimR )
		exit(1);
	int temp;
	for ( int i = 0; i < dimC; ++i ) {
		temp = this->get(r1,i)*k + this->get(r2,i);
		this->set(r2,i,temp);
	}
}
