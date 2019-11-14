//CMPE250 - Fall 2019
//PS7 - Breadth First Search (BFS)

#include "Graph.h"

Graph::Graph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    adjacencyList = new list<int>[numberOfVertices];
}

Graph::~Graph() {
    delete[] adjacencyList;
}

void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w); // Add w to v's list.
}


void Graph::breadthFirstSearch(int s)
{
    // Mark all the vertices as not visited
    bool visited[numberOfVertices];
    for(int i = 0; i < numberOfVertices; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!q.empty())
    {
        // Dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adjacencyList[s].begin(); i != adjacencyList[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}