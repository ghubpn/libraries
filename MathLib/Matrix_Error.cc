/* LOCAL INCLUDES */
#include "Matrix_Error.h"

void defaultHandler() {
	exit(1);
}

bool outOfBounds_Exception() {
	cerr << "ERROR: [Matrix] out of bounds exception" << endl;
	defaultHandler();
	return true;
}

bool invalidDimensions_Exception() {
	cerr << "ERROR: [Matrix] operand dimensions invalid" << endl;
	defaultHandler();
	return true;
}
