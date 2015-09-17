#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void loadAllLines( string filename, vector<string>* destination );
bool loadLines( string filename, int start, int end, vector<string>* destination );
bool loadLine( string filename, int position, string* destination );

void saveLines( string filename, vector<string>* source );

#endif
