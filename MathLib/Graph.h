#ifndef GRAPH_H
#define GRAPH_H

#include "Matrix.h"

#include <vector>

using namespace std;

class Graph {

public:
	Graph( int v );
	~Graph();
	void connect( int from, int to );
	void disconnect( int from, int to );
	bool connected( int from, int to );
	vector<int>* getConnections( int v );

private:
	int     vCount;
	Matrix* edges;

};

#endif