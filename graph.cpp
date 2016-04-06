#include "graph.h"

using namespace std;

//reads in a graph from standard input
Graph::Graph(char space) {
    cin > length;
    
    graph.resize(length);
    
    width = 0;
    string line;
    
    //read in what data exists
    
    for (int i = graph.size() - 1; i >= 0; --i) {
        if (line.length() > width) {
            width = line.length();
        }
        
        for (int j = 0; j < line.length(); ++j) {
            graph[i][j] = line[j];
        }
    }
    
    //pad any lines that aren't completely full
    
    for (int i = 0; i < length; ++i) {
        if (graph[i].size < width) {
            for (int j = graph[i].size(); j < width; ++j) {
                graph[i].push_back(space);
            }
        }
    }
}

//returns the character at the given coordinate
char Graph::at(coord c) {
    return graph[c.y][c.x];
}
