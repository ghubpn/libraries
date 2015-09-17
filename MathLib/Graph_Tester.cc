/* LOCAL INCLUDES */
#include "Graph.h"

/* STANDARD INCLUDES */
#include <iostream>
#include <vector>

/* GRAPH TEST */
void graphTest() {
	cout << endl << "GRAPH TEST:" << endl;
	int v = 4;
	Graph g(v);
	g.connect(2,1);
	g.connect(2,3);
	vector<int>* connections = g.getConnections(2);
	for ( int i = 0; i < connections->size(); ++i )
		cout << connections->at(i) << " ";
	cout << endl;	
}