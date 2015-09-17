#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
	
	private:
		int n;
		vector<vector<int>> nodes;
	public:
		Graph( int size );
		void addEdge( int i, int j );
		void addBiEdge( int i, int j );
		bool checkEdge( int i, int j );
		void print();
	
};

#endif