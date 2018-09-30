//
// Created by yyf on 9/25/18.
//

#ifndef AIPROJECT_1_GRID_H
#define AIPROJECT_1_GRID_H


#include "Board.h"


class Grid{
private:
    Board grid[9];
    int player;
    int pos;
public:
    Grid();
    Grid(Board grid[9], int player, int pos);

    void set_grid(Board* grid);
    void set_grid_i(int i, Board b);
    void set_player(int player);
    void set_pos(int pos);
    Board* get_grid();
    int get_player();
    int get_pos();
    Grid play(int x, int y, int player);
    bool islegal(int x,int y);
    int check(int opponent);
    void display();
    bool operator==(Grid g1);
};


#endif //AIPROJECT_1_GRID_H
