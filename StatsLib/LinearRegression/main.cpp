/* standard includes */
#include <iostream>

/* main */
using namespace std;
int main() {
	int sampleSize = 0;
	
	while (sampleSize < 1 || sampleSize > 10) {
		cout << "Enter sample size (between 1 and 10): ";
		cin >> sampleSize;
	}
	
	return 0;
}