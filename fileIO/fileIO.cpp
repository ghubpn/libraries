#include "fileIO.h"

void loadAllLines( string filename, vector<string>* destination ) {
	// local variables
	string   line;
	ifstream inFile;
	// open file specified in filename
	inFile.open(filename.c_str());
	// while current line read is not EOF
	while (getline(inFile, line)) {
		// add value to destination
		destination->push_back(line);
	}
	// close file
	inFile.close();
}

bool loadLines( string filename, int start, int end, vector<string>* destination ) {
	// local variables
	bool     notEOF = true;
	string   line;
	ifstream inFile;
	// open file specified in filename
	inFile.open(filename.c_str());
	// move to line specified in start (assuming lines start at 1, not 0)
	for ( int i = 0; i < start - 1; ++i )
		inFile.ignore(numeric_limits<streamsize>::max(),'\n');
	// iterate through lines [start, end]
	for ( int i = 0; i <= end - start; ++i ) {
		// read current line
		if (getline(inFile, line))
			// if not EOF, add value to destination
			destination->push_back(line);
		// if EOF was read
		else {
			// set return value to false and stop reading lines
			notEOF = false;
			break;
		}
	}
	// close file
	inFile.close();
	// return false if EOF was read, otherwise return true
	return notEOF;
}

bool loadLine( string filename, int position, string* destination ) {
	// local variables
	bool     notEOF = true;
	string   line;
	ifstream inFile;
	// open file specified in filename
	inFile.open(filename.c_str());
	// move to line specified in start (assuming lines start at 1, not 0)
	for ( int i = 0; i < position - 1; ++i )
		inFile.ignore(numeric_limits<streamsize>::max(),'\n');
	// read current line
	if (getline(inFile, line))
		// if not EOF, add value to destination
		*destination = line;
	// if EOF was read, set return value to false
	else
		notEOF = false;
	// close file
	inFile.close();
	// return false if EOF was read, otherwise return true
	return notEOF;
}

void saveLines( string filename, vector<string>* source ) {
	// local variables
	ofstream outFile;
	vector<string>::const_iterator i;
	// open file specified in filename
  outFile.open(filename.c_str());
	// for each line in source, from beginning to end
	for ( i = source->begin(); i != source->end(); ++i ) {
		// write current line to file
		outFile << (*i) << endl;
	}
  // close file
	outFile.close();
}
