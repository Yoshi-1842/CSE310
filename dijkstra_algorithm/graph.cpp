#include "graph.h"
#include "minheap.h"
#include <iostream>
#include <cstdio>

using namespace std;
const double DOUBLE_MAX = 99999999.0;

Graph::Graph() {
    // Constructor implementation
    // set pointers to nullptr
    adjacencyLists = nullptr;
    extractedVertices = nullptr;
    relaxedVertices = nullptr;
    predecessor = nullptr;
    distance = nullptr;
    // set variables to default values
    numVertices = 0;
    numEdges = 0;
    isDirected = false;
    source = 0;
}

Graph::~Graph() {
    // Destructor implementation
    // Deallocate memory for arrays and adjacency lists
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjacencyLists[i];
    }
    delete[] adjacencyLists;
    delete[] extractedVertices;
    delete[] relaxedVertices;
    delete[] predecessor;
    delete[] distance;
}


bool Graph::loadGraph(const string& filename, const string& direction) {
    ifstream file(filename);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Failed to open the graph file." << endl;
        return false;
    }

    // Read the first line from the file
    string line;
    getline(file, line);

    if(line.empty()){
        cout << "Empty file." << endl;
        return false;
    }

    // Parse the first line to get the number of vertices and edges
    istringstream iss(line);
    int n, m;
    if (iss >> n >> m) {
        numVertices = n + 1;
        numEdges = m;

        adjacencyLists = new Edge*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjacencyLists[i] = nullptr; // Initialize to nullptr
        }

        // Allocate memory for extractedVertices, relaxedVertices, predecessor, and distance
        extractedVertices = new double[numVertices];
        relaxedVertices = new double[numVertices];
        predecessor = new int[numVertices];
        distance = new double[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            extractedVertices[i] = -1;
            relaxedVertices[i] = -1;
        }
    } else {
        cerr << "Invalid format for the first line in the input file." << endl;
        return false;
    }

    // Close the file and reopen it to read the content again
    file.close();
    file.open(filename);

    // Check if the file is successfully reopened
    if (!file.is_open()) {
        cerr << "Failed to reopen the graph file." << endl;
        return false;
    }

    // Read the first line again to skip it
    getline(file, line);

    // Loop through the remaining lines to read edges and build adjacency lists
while (getline(file, line)) {
    int edgeId, startNode, endNode;
    double weight;
    istringstream iss(line);

    // Parse the line to get edge information
    if (iss >> edgeId >> startNode >> endNode >> weight) {
        startNode++;
        endNode++;

        // Check if node IDs are valid
        if (startNode > numVertices || endNode > numVertices || startNode < 1 || endNode < 1) {
            cerr << "Invalid node IDs in the input file." << endl;
            return false;
        }

        // Create a new edge
        Edge* edge = new Edge;
        edge->destination = endNode;
        edge->weight = weight;

        // Add edge to the adjacency list
        if (adjacencyLists[startNode] == nullptr) {
            adjacencyLists[startNode] = new Edge[numEdges]; // Initialize to zero
        }

        // Find the next available slot in the adjacency list
        int k = 0;
        while (adjacencyLists[startNode][k].destination != 0) {
            k++;
        }

        // Add the edge to the list
        adjacencyLists[startNode][k] = *edge;

        if(direction == "undirected"){
            Edge* reverseEdge = new Edge;
            reverseEdge->destination = startNode;
            reverseEdge->weight = weight;

            if(adjacencyLists[endNode] == nullptr){
                adjacencyLists[endNode] = new Edge[numEdges];
            }

            int j = 0;
            while(adjacencyLists[endNode][j].destination != 0){
                j++;
            }

            adjacencyLists[endNode][j] = *reverseEdge;

            delete reverseEdge;
        }

        delete edge;
    }else{
        cout << "Invalid format for an edge in the input file." << endl;
        return false;
    }
}
    // Set the graph direction
    isDirected = (direction == "directed");

    // Close the file
    file.close();

    return true;
}

void Graph::runDijkstra(int newSource, int destination, int flag) {
    int n = numVertices;
    int source = newSource;
    bool graphTraversed = true;
    bool fullTraversal = true;

    // Create arrays and data structures for Dijkstra's algorithm
    bool* extracted = new bool[n];
    for (int i = 0; i < n; ++i) {
        extracted[i] = false;
        extractedVertices[i] = -1;
        relaxedVertices[i] = -1;
        predecessor[i] = -1;
        distance[i] = DOUBLE_MAX;
    }

    // Mark the source as extracted
    extracted[source] = true;

    minHeap.init(n);
    distance[source] = 0;
    minHeap.push(0, source);

    // If flag is set, print initial insertion
    if (flag == 1) {
        printf("Insert vertex %d, key=%12.4f\n", source, distance[source]);
    }

    // Main Dijkstra's algorithm loop
    while (!minHeap.empty()) {
        // Extract the minimum distance vertex from the MinHeap
        int u = minHeap.pop();

        // Mark the vertex as extracted
        extracted[u] = true;
        extractedVertices[u] = distance[u];

        // If flag is set, print deletion of vertex
        if (flag == 1) {
            printf("Delete vertex %d, key=%12.4f\n", u, distance[u]);
        }

        // If the destination is reached, exit the loop
        if (u == destination) {
            break;
        }

        // Loop through the adjacency list of the current vertex
        if (adjacencyLists[u]) {
            int j = 0;
            while (adjacencyLists[u][j].destination != 0) {
                // Extract neighbor information
                int v = adjacencyLists[u][j].destination;
                double w = adjacencyLists[u][j].weight;

                // If the neighbor is not extracted and relaxation is possible
                if (!extracted[v] && distance[u] + w < distance[v]) {
                    // Perform relaxation
                    double oldDistance = distance[v];
                    distance[v] = distance[u] + w;
                    predecessor[v] = u;
                    relaxedVertices[v] = distance[v];

                    // If flag is set, print decrease key operation
                    if (oldDistance != DOUBLE_MAX && flag == 1) {
                        printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, oldDistance, distance[v]);
                    }

                    // Push the neighbor into the MinHeap
                    minHeap.push(distance[v], v);

                    // If flag is set, print insertion of vertex
                    if (flag == 1) {
                        printf("Insert vertex %d, key=%12.4f\n", v, distance[v]);
                    }
                }
                j++;
            }
        }
    }

    // Handle vertices left in MinHeap after the main loop
    while (!minHeap.empty()) {
        int u = minHeap.pop();
        if (!extracted[u]) {
            fullTraversal = false;
        }
    }

    // Deallocate memory for extracted array
    delete[] extracted;
}

void Graph::writePath(int s, int d) {
    // Check if the graph has been traversed
    if (!graphTraversed) {
        printf("Error: graph has not been traversed yet.\n");
        return;
    }

    // Check for valid source-destination pair
    if (s != source || d < 1 || d >= numVertices) {
        printf("Error: invalid source-destination pair.\n");
        return;
    }

    // Case 1: Shortest s-d path is computed
    if (extractedVertices[d] != -1) {
        // Create an array to store the path
        int* path = new int[numVertices];
        int current = d;
        int pathSize = 0;

        // Reconstruct the path
        while (current != s) {
            path[pathSize] = current;
            current = predecessor[current];
            pathSize++;
        }

        path[pathSize] = s;

        // Print the shortest path
        printf("Shortest path: ");
        for (int i = pathSize; i >= 0; --i) {
            printf("%d ", path[i]);
        }
        printf("\n");

        // Print the path weight
        printf("The path weight is: %12.4f\n", distance[d]);

        // Deallocate memory for the path array
        delete[] path;
    }
    // Case 2: s-d path computed but not known if it's the shortest
    else if (relaxedVertices[d] != -1) {
        // Create an array to store the path
        int* path = new int[numVertices];
        int current = d;
        int pathSize = 0;

        // Reconstruct the path
        while (current != s) {
            path[pathSize] = current;
            current = predecessor[current];
            pathSize++;
        }

        path[pathSize] = s;

        // Print the path not known to be shortest
        printf("Path not known to be shortest: ");
        for (int i = pathSize; i >= 0; --i) {
            printf("%d ", path[i]);
        }
        printf("\n"); 

        // Print the path weight
        printf("The path weight is: %12.4f\n", distance[d]);

        // Deallocate memory for the path array
        delete[] path;
    }
    // Case 3: No s-d path computed, and no min-heap operations were printed
    else if (!fullTraversal) {
        printf("No %d-%d path has been computed.\n", s, d);
    }
    // Case 4: Entire graph has been traversed, and d is not in extracted or relaxed
    else {
        printf("No %d-%d path exists.\n", s, d);
    }
}

void Graph::printAdjacencyLists() {
    // Loop through each vertex in the graph
    for (int v = 0; v < numVertices; ++v) {
        cout << "Adjacency list for vertex " << v << ": ";

        // Check if the adjacency list for the current vertex exists
        if (adjacencyLists[v] != nullptr) {
            int j = 0;

            // Loop through each edge in the adjacency list
            while (adjacencyLists[v][j].destination != 0) {
                // Print the destination vertex and edge weight
                cout << "(" << adjacencyLists[v][j].destination << ", " << adjacencyLists[v][j].weight << ") ";

                // Move to the next edge in the list
                ++j;
            }
        }

        // Print the predecessor value for the current vertex
        cout << "Predecessor: " << predecessor[v] << endl;
        cout << endl;
    }
}
