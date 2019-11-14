//CMPE250 - Fall 2019
//PS7 - Topological Sort

#include <iostream>
#include "Graph.h"

int main() {
// Create a graph given the edges
    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    cout << "The following is a Topological Sort of the given graph" << endl;
    graph.topologicalSort();

    return 0;
}