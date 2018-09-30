//
// Created by yyf on 9/25/18.
//

#ifndef AIPROJECT_1_BOARD_H
#define AIPROJECT_1_BOARD_H

#include <iostream>
using namespace std;



class Board{
private:
    int board[9];
    int next_action;
    int player;
public:
    Board(int board[],int player);
    Board();
    int* get_board();
    int get_player();
    int get_next_action();
    void set_board(int board[9]);
    void set_player(int player);
    void set_next_action(int action);
    void set_board_i(int pos,int value);

    void display();
    int check();
    Board play(int pos, int player);
    bool islegal(int pos);
    int diff(Board b,int cpt);


};
#endif //AIPROJECT_1_BOARD_H
