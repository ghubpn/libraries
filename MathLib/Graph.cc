#include "Graph.h"

Graph::Graph( int v ) : vCount(v) {
	edges = new Matrix(v,v);
}

Graph::~Graph() {
	delete edges;
}

void Graph::connect( int from, int to ) {
	edges->set(from,to, 1);
}

void Graph::disconnect( int from, int to ) {
	edges->set(from,to, 0);
}

bool Graph::connected( int from, int to ) {
	if ( edges->get(from,to) == 1 )
		return true;
	else
		return false;
}

vector<int>* Graph::getConnections( int v ) {
	vector<int>* connections = new vector<int>();
	if ( v < 0 )
		v = 0;
	else if ( v > vCount )
		v = vCount;
	for ( int i = 0; i < vCount; ++i ) {
		if ( edges->get(v,i) )
			connections->push_back(i);
	}
	return connections;
}