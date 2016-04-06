#include <iostream>
#include <vector>

#include "graph.h"

enum action { UP, RIGHT, DOWN, LEFT };
const int NUM_ACTIONS = 4;
const action[] = [UP, RIGHT, DOWN, LEFT];

class Table {
  private:
    int coins; //how many coins are in the graph - ie the table's 3rd dimension
    Graph *g; //the actual graph with the information. Pointer bc it could be pretty big
    float gamma, epsilon, delta; //statistical stuff
    vector<vector<vector<float>>> table;

  public:
    //default constructor. Created a table with all utilities initialized to 0
    Table(int coins, Graph *g, float gamma, float epsilon);
    
    //given another table, uses its values to generate a new, more correct table
    //note that this calculates the delta value - the max difference between this table's
    //  utilities and the old table's
    Table(Table *t);
    
    //returns the implicit reward for a certain coordinate
    //(this is based on the graph)
    reward(coord c);
    
    //returns the coordinate results of a transition on a set of coordinates
    coord transition(coord, action);
    
    //returns the best action for the given coord
    action bestAction(coord);
    
    //returns true if delta is less than a value based on epsilon and gamma
    bool converged();

};
