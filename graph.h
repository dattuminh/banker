#include <iostream>
#include <vector>
#include <string>

//to make passing these around easier
struct coord {
    //x, y, wealth
    int x, y, w;
};

class Graph {
  private:
    int length, width;
    vector<vector<char>> graph;
  
  public:
    //reads in a graph from standard input
    //space is the character being used as a blank space
    Graph(char space = ' ');
    
    //returns the character at the given coordinate
    char at(coord c);
}
