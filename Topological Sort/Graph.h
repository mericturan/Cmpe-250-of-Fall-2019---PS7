//CMPE250 - Fall 2019
//PS7 - Topological Sort

#ifndef TOPLOGICALSORT_GRAPH_H
#define TOPLOGICALSORT_GRAPH_H

// A C++ program to print topological sorting of a graph
// using indegrees.
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Class to represent a graph
class Graph {

private:
    int numberOfVertices;    // No. of vertices'

    // Pointer to an array containing the adjacency list
    list<int> *adjacencyList;

public:
    Graph(int numberOfVertices);   // Constructor
    ~Graph();  // Destructor
    // Copy constructor is not implemented for sake of simplicity

    // function to add an edge to the graph
    void addEdge(int u, int v);

    // prints a Topological Sort of the complete graph
    void topologicalSort();

};


#endif //TOPLOGICALSORT_GRAPH_H
