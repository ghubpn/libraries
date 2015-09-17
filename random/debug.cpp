#include <iostream>

#include "random.h"

int main() {
	char ar[48];
	for (int i = 0; i < 48; ++i ) {
		if (i < 24)
			ar[i] = 'O';
		else
			ar[i] = ' ';
	}
	Random r;
	for ( int i = 0; i < 20; ++i ) {
		r.permuteArray(ar, 48);
		for ( int j = 0; j < 48; ++j ) {
			cout << ar[j];
		}
		cout << endl;
	}
}