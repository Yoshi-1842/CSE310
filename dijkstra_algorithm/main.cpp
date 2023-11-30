#include <iostream>
#include <stdexcept>  // 
#include "graph.h"   // Assuming you have a header file for the Graph class

using namespace std;

int main(int argc, char* argv[]) {
    // Command-line argument validation
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <graph_filename> <direction>" << endl;
        return EXIT_FAILURE;
    }
    
    // Extract graph filename and direction from command-line arguments
    char* graphFilename = argv[1];
    char* direction = argv[2];

    // Create an instance of the Graph class
    Graph graph;

    // Load the graph from the specified file
    if (!graph.loadGraph(graphFilename, direction)) {
        cerr << "Failed to load the graph from file: " << graphFilename << endl;
        return EXIT_FAILURE;
    }

    while (true) {
        string query, source, destination, flag, action;
        cout << "Enter a query: ";
        cin >> query >> source >> destination >> flag >> action;

        if (query == "find") {
            try {
                graph.runDijkstra(stoi(source), stoi(destination), stoi(flag));
            } catch (const invalid_argument& e) {
                cerr << "Invalid input for find query. Please enter valid integers." << endl;
            }
        } else if (query == "write") {
            try {
                graph.writePath(stoi(source), stoi(destination));
            } catch (const invalid_argument& e) {
                cerr << "Invalid input for write query. Please enter valid integers." << endl;
            }
        } else if (query == "stop") {
            return EXIT_SUCCESS;
        } else {
            cout << "Invalid query. Please use 'find', 'write', or 'stop'." << endl;
        }
    }
    
}
