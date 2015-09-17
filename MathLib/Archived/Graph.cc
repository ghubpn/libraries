#include "Graph.h"

Graph::Graph( int size ) {
	n = size;
	vector<int> temp;
	for (int i = 0; i < n; ++i)
		nodes.push_back( temp );
}

void Graph::addEdge( int i, int j ) {
	//if (nodes[i][j] != 1)
	nodes[i].push_back(j);
}

void Graph::addBiEdge( int i, int j ) {
	addEdge( i, j );
	addEdge( j, i );
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool Graph::checkEdge( int i, int j ) {
	//for (int k = 0; k < nodes[k].size(); ++k) {
		if (nodes[i][j] == j)
			return true;
		else
			return false;
	//}
}
	
void Graph::print() {
	for (int i = 0; i < nodes.size(); ++i) {
		std::cout << "Node " << i << ": ";
		for (int j = 0; j < nodes[i].size(); ++j) {
			std::cout << nodes[i][j];
			if (j < nodes[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
}