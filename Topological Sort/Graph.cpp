//CMPE250 - Fall 2019
//PS7 - Topological Sort

#include "Graph.h"

Graph::Graph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    adjacencyList = new list<int>[numberOfVertices];
}

Graph::~Graph() {
    delete[] adjacencyList;
}
void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
}


// The function to perform Topological Sort.
void Graph::topologicalSort() {
    // Create a vector to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    vector<int> inDegree(numberOfVertices, 0);

    // Traverse adjacency lists to fill actual indegrees of
    // vertices.  This step takes O(|V|+|E|) time
    for (int u = 0; u < numberOfVertices; u++) {
        list<int>::iterator itr;
        for (itr = adjacencyList[u].begin(); itr != adjacencyList[u].end(); itr++)
            inDegree[*itr]++;
    }

    // Create a queue and enqueue all vertices with
    // indegree 0
    queue<int> q;
    for (int i = 0; i < numberOfVertices; i++)
        if (inDegree[i] == 0)
            q.push(i);

    // Initialize the number of visited vertices
    int cnt = 0;

    // Create a vector to store the result
    // (A topological ordering of the vertices)
    vector<int> topOrder;

    // One by one dequeue vertices from the queue and enqueue
    // adjacent nodes if indegree of adjacent node becomes 0
    while (!q.empty()) {
        // perform dequeue
        // and add the vertex to the topological order
        int u = q.front();
        q.pop();
        topOrder.push_back(u);

        // Iterate through all its neighboring nodes
        // of dequeued node u and decrease their indegree
        // by 1
        list<int>::iterator itr;
        for (itr = adjacencyList[u].begin(); itr != adjacencyList[u].end(); itr++)

            // If indegree becomes zero, add it to queue
            if (--inDegree[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    // Check if there is a cycle
    if (cnt != numberOfVertices) {
        cout << "There exists a cycle in the graph" << endl;
        return;
    }

    // Print the topological order
    for (int i = 0; i < topOrder.size(); i++)
        cout << topOrder[i] << " ";
    cout << endl;
}