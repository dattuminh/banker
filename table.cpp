#include "table.h"
#include "legend.h"

//Creates a table with all utilities initialized to 0
Table::Table(Graph *in_g, float in_gamma, float in_epsilon) {    
    g = in_g;
    
    length = g->getLength();
    width = g->getWidth();
    coins = g->getCoins();
    
    gamma = in_gamma;
    epsilon = in_epsilon;
    
    //TODO:
    //there's probably a more elegant way to do this next part
    table.resize(length);
    for (int y = 0; y < length; ++y) {
        table[y].resize(width);
        for (int x = 0; x < width; ++x) {
            table[y][x].resize(coins);
            for (int w = 0; w < coins; ++w) {
                table[y][x][w] = 0;
            }
        }
    }
}

//given another table, uses its values to generate a new, more correct table
//note that this calculates the delta value - the max difference between this table's
//  utilities and the old table's
Table::Table(Table *t);

//returns the implicit reward for a certain coordinate
//(this is based on the graph)
reward(coord c) {
    switch(g->at(c)){
        case SPACE:
            return -1;
            
        case ROCKS:
            return -10;
            
        case COIN:
            return 5;
            
        case BANK:
            return 10 * c.w; //multiply by the number of coins you have
            
        default:
            cerr << "Tried to find reward of illegal tile: ";
            cerr << g->at(c);
            cerr << " at " << c << endl;
            exit(1);
    }
}

//returns the coordinate results of a transition on a set of coordinates
coord transition(coord c, action a) {
    
    //start by modifying the x/y coordinates
    switch(a){
        case UP:
            if (c.y < length && g->at(c.y + 1, c.x, c.w) != WALL) {
                ++c.y;
            }
        break;
        
        case RIGHT:
            if (c.x < width && g->at(c.y, c.x + 1, c.w) != WALL) {
                ++c.x;
            }
        break;
        
        case DOWN:
            if (c.y > 0 && g->at(c.y - 1, c.x, c.w) != WALL) {
                --c.y;
            }
        break;
        
        case LEFT:
            if (c.x > 0 && g->at(c.y, c.x - 1, c.w) != WALL) {
                --c.x;
            }
        break;
    }
    
    //if the coordinates now land on a coin, "raise up" a level
    if (g->at(c) == COIN) {
        ++c.w;
    }
    
    return c;c
}

//returns the best action for the given coord
action bestAction(coord);

//returns true if delta is less than a value based on epsilon and gamma
bool converged();
