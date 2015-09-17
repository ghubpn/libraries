#include <iostream>
#include <vector>
#include <string>

#include "fileIO.h"

int main() {
	/*
	vector<string> list;
	//loadList( "list.txt", &list );
	if (!loadLines( "list.txt", 2, 6, &list ))
		cout << "EOF reached" << endl;
	for (int i = 0; i < list.size(); ++i)
		cout << list[i] << endl;
	saveLines( "out.txt", &list );
	*/
	string line;
	if (!loadLine( "list.txt", 3, &line ))
		cout << "EOF reached" << endl;
	cout << line << endl;
	//saveLines( "out2.txt", &line );
}
