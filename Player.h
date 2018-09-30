//
// Created by yyf on 9/25/18.
//

#ifndef AIPROJECT_1_PLAYER_H
#define AIPROJECT_1_PLAYER_H

#include <iostream>
#include "Board.h"
#include "Grid.h"

using namespace std;


class Player{
private:
    int player;
    Board board;
    Grid grid;
    Board* next_board;
    Grid* next_grid;


public:
    Player();
    Player(int player, Board board);
    Player(int player, Grid grid);
    Board get_next_board();
    Board get_board();
    Grid get_grid();
    Grid get_next_grid();
    int get_player();
    void set_board(Board board);
    void set_grid(Grid grid);
    float minimax(Board board, float alpha, float beta, int depth);
    float maxvalue(Board board, float alpha, float beta, int depth);
    float minvalue(Board board, float alpha, float beta, int depth);

    float minimax(Grid grid, float alpha, float beta, int depth, int part);
    float maxvalue(Grid grid, float alpha, float beta, int depth, int part);
    float minvalue(Grid grid, float alpha, float beta, int depth, int part);

    float heuristic(Board board, int player);
    float heuristic(Grid grid);
    float heuristic_2(Grid grid);

};
#endif //AIPROJECT_1_PLAYER_H
