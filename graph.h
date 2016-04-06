#include <iostream>
#include <vector>

//to make passing these around easier
struct coord {
    //x, y, wealth
    int x, y, w
};

class Graph {
  private:
    int length, width;
    vector<vector<char>> graph;
  
  public:
    //reads in a graph from standard input
    Graph();
    
    //returns the character at the given coordinate
    char at(coord);
}
