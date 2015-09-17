#ifndef RANDOM_H
#define RANDOM_H

#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Random
{
	public:
		// ctor/dtor
		Random();
		
		// pseudo-random generators
		bool  randBool();
		int   randInt(int min, int max);
		float randFloat(float min, float max);
		template<typename T>
		void  permuteArray( T* array, int n );

};

template<typename T>
void Random::permuteArray( T* array, int n ) {
	int r;
	T temp;
	for ( int i = 0; i < n; ++i ) {
		r        = randInt( i, n-1 );
		temp     = array[r];
		array[r] = array[i];
		array[i] = temp;
	}
}

#endif