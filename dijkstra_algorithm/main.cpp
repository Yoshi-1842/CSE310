#include <iostream>
#include <stdexcept>  // 
#include "graph.h"   // Assuming you have a header file for the Graph class

using namespace std;

int main(int argc, char* argv[]) {
    // Command-line argument validation
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <graph_filename> <direction>" << endl;
        return 1;
    }
    
    // Extract graph filename and direction from command-line arguments
    string graphFilename = argv[1];
    string direction = argv[2];

    // Create an instance of the Graph class
    Graph* graph = new Graph();

    // Load the graph from the specified file
    if (!graph->loadGraph(graphFilename, direction)) {
        cout << "Failed to load the graph from file: "  << endl;
        return 1;
    }

    while (true) {
        string query;
        cin>> query;
        int source;
        int destination;
        int flag;
        string action;
        if (query == "find") {
            cin >> source >> destination >>flag;
            graph->runDijkstra(source,destination,flag);
        } else if (query == "write") {
            cin >> action >> source >> destination;
            graph->writePath(source,destination);
        } else if (query == "stop") {
            delete graph;
            return 0;
        } else {
            cout << "Invalid query. Please use 'find', 'write', or 'stop'." << endl;
        }
    }
    
}
