//CMPE250 - Fall 2019
//PS7 - Breadth First Search (BFS)

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {

private:
    int numberOfVertices;    // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adjacencyList;
public:
    Graph(int numberOfVertices);  // Constructor
    ~Graph();  // Destructor
    // Copy constructor is not implemented for sake of simplicity
    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void breadthFirstSearch(int s);
};


#endif //BFS_GRAPH_H
