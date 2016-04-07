#include <iostream>
#include <vector>
#include <string>

using namespace std;

//to make passing these around easier
struct coord {
    //y, x, wealth
    int y, x, w;
};



class Graph {
  private:
    int length, width, coins;
    vector<vector<char>> graph;
  
  public:
    //reads in a graph from standard input
    //space is the character being used as a blank space
    Graph(char space = ' ');
    
    //returns the character at the given coordinate
    char at(coord c);
    char at(int y, int x, int w);
    
    //getters
    int getLength() { return length; }
    int getWidth() { return width; }
    int getCoins { return coins;}
}
