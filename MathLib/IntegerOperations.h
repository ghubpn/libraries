#ifndef COUNT_H
#define COUNT_H

using namespace std;



// n factorial
long fact( int n ) {
	int temp = 1;
	for ( int i = 1; i <= n; ++i )
		temp *= i;
	return temp;
} // end fact()



// n choose k
long choose( int n, int k ) {
	long temp = 1;
	if ( k >= n-k ) {
		int j = n-k;
		for ( int i = n; i > k; --i ) {
			temp *= i;
			temp /= j--;
		}
		for ( ; j > 1; --j )
			temp /= j--;
	} else {
		int j = k;
		for ( int i = n; i > n-k; --i ) {
			temp *= i;
			temp /= j--;
		}
		for ( ; j > 1; --j )
			temp /= j--;
	}
	return temp;
} // end choose()

#endif