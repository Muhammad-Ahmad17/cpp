/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-12-31.  
           
  TIME: 4:36 PM.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

class Graph {
private:
    int vertices; // Total number of vertices in the graph
    vector<vector<pair<int, int>>> adjList; // Adjacency list representation with weights

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v); // Initialize adjacency list with empty vectors
        cout << "Graph initialized with " << v << " vertices." << endl;
    }

    void addEdge(int u, int v, int weight, bool directed = false) {
        adjList[u].push_back({v, weight}); // Add edge from u to v
        if (!directed) {
            adjList[v].push_back({u, weight}); // Add edge from v to u if the graph is undirected
        }
        cout << "Edge added between " << u << " and " << v << " with weight " << weight << (directed ? " (directed)." : " (undirected).") << endl;
    }

    vector<int> bfs(int start) {
        vector<bool> visited(vertices, false); // Keep track of visited nodes
        queue<int> q; // Queue for BFS
        vector<int> traversal; // Store BFS traversal order

        cout << "Starting BFS from vertex " << start << "." << endl;
        visited[start] = true; // Mark the start node as visited
        q.push(start); // Enqueue the start node

        while (!q.empty()) {
            int current = q.front(); // Get the front node from the queue
            q.pop(); // Dequeue the front node

            cout << "Visiting vertex " << current << "." << endl;
            traversal.push_back(current); // Add the current node to the traversal

            for (const auto& neighbor : adjList[current]) {
                if (!visited[neighbor.first]) { // If neighbor is not visited
                    visited[neighbor.first] = true; // Mark as visited
                    q.push(neighbor.first); // Enqueue the neighbor
                    cout << "Queueing vertex " << neighbor.first << "." << endl;
                }
            }
        }

        return traversal; // Return the BFS traversal
    }

    vector<int> dfs(int start) {
        vector<bool> visited(vertices, false); // Keep track of visited nodes
        stack<int> s; // Stack for DFS
        vector<int> traversal; // Store DFS traversal order

        cout << "Starting DFS from vertex " << start << "." << endl;
        s.push(start); // Push the start node onto the stack

        while (!s.empty()) {
            int current = s.top(); // Get the top node from the stack
            s.pop(); // Pop the top node

            if (!visited[current]) { // Process the node if not visited
                visited[current] = true; // Mark as visited
                traversal.push_back(current); // Add to the traversal
                cout << "Visiting vertex " << current << "." << endl;

                // Push neighbors onto the stack in reverse order for correct DFS
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[it->first]) {
                        s.push(it->first); // Push unvisited neighbors
                        cout << "Stacking vertex " << it->first << "." << endl;
                    }
                }
            }
        }

        return traversal; // Return the DFS traversal
    }

    vector<int> dijkstra(int start) {
        vector<int> distances(vertices, INT_MAX); // Initialize distances to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap for shortest distance

        cout << "Starting Dijkstra's algorithm from vertex " << start << "." << endl;
        distances[start] = 0; // Distance to the start node is 0
        pq.push({0, start}); // Push the start node with distance 0

        while (!pq.empty()) {
            int currentDist = pq.top().first; // Current shortest distance
            int currentNode = pq.top().second; // Current node being processed
            pq.pop(); // Remove the node from the priority queue

            cout << "Processing vertex " << currentNode << " with current distance " << currentDist << "." << endl;

            if (currentDist > distances[currentNode]) {
                continue; // Skip if a shorter path to the node is already found
            }

            for (const auto& neighbor : adjList[currentNode]) {
                int nextNode = neighbor.first; // Neighboring node
                int weight = neighbor.second; // Weight of the edge

                // Relaxation step: update distance if a shorter path is found
                if (distances[currentNode] + weight < distances[nextNode]) {
                    distances[nextNode] = distances[currentNode] + weight; // Update distance
                    pq.push({distances[nextNode], nextNode}); // Push updated distance to priority queue
                    cout << "Updating distance of vertex " << nextNode << " to " << distances[nextNode] << "." << endl;
                }
            }
        }

        return distances; // Return the shortest distances from the start node
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges with weights
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 6);

    // Perform BFS and DFS starting from vertex 0
    vector<int> bfsResult = g.bfs(0);
    vector<int> dfsResult = g.dfs(0);

    // Print BFS traversal
    cout << "BFS traversal starting from vertex 0: ";
    for (int v : bfsResult) {
        cout << v << " ";
    }
    cout << endl;

    // Print DFS traversal
    cout << "DFS traversal starting from vertex 0: ";
    for (int v : dfsResult) {
        cout << v << " ";
    }
    cout << endl;

    // Perform Dijkstra's algorithm starting from vertex 0
    vector<int> dijkstraResult = g.dijkstra(0);
    cout << "Shortest distances from vertex 0: ";
    for (int i = 0; i < dijkstraResult.size(); ++i) {
        cout << "Vertex " << i << ": " << dijkstraResult[i] << " ";
    }
    cout << endl;

    return 0;
}
