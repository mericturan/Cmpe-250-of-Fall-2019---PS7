//CMPE250 - Fall 2019
//PS7 - Breadth First Search (BFS)

#include <iostream>

#import "Graph.h"
// Driver program to test BFS
int main() {
    // Create a graph given in the above diagram
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2)" << endl;
    graph.breadthFirstSearch(2);

    return 0;
}