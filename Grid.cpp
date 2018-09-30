//
// Created by yyf on 9/25/18.
//

#include "Grid.h"


Grid::Grid() {
    Board b;
    for (int i = 0; i < 9; ++i) {
        this->grid[i] = b;
    }
    this->pos = -1;
    this->player = 1;

}

Grid::Grid(Board *grid, int player, int pos) {
    for (int i = 0; i < 9; ++i) {
        this->grid[i] = grid[i];
    }
    this->player = player;
    this->pos = pos;
}
void Grid::set_grid(Board *grid) {
    for (int i = 0; i < 9; ++i) {
        this->grid[i] = grid[i];
    }
}

void Grid::set_player(int player) {
    this->player = player;
}

void Grid::set_pos(int pos) {
    this->pos = pos;
}

Board* Grid::get_grid() {
    return this->grid;
}

int Grid::get_player() {
    return this->player;
}

int Grid::get_pos() {
    return this->pos;
}

Grid Grid::play(int x, int y, int player) {
    Grid res = *this;
    res.set_player(2-player/2);
    res.set_pos(y);
    res.grid[x].set_board_i(y,player);
    return res;
}

bool Grid::islegal(int x, int y) {
    if(this->pos == -1) return true;
    /*
    if(x==8 && this->grid[x].islegal(y)) return 1;
    else return 0;
     */
    if(this->grid[x].check() != 0) return false;
    if(x == this->pos){
        if(this->grid[x].islegal(y)) return true;
        else return false;
    }
    else{
        if(this->grid[this->pos].check() == 0) return false;
        else{
            if (this->grid[x].islegal(y)) return true;
            return false;
        }
    }
}

//a0: tie a1: unfinished a2: player1 a3:player2
int Grid::check(int part) {

    if(part == 2){
        int opponent = 3-this->player;
//    return this->grid[8].check();
        int a[4] = {0,0,0,0};
        for (int i = 0; i < 9; ++i) {
            a[this->grid[i].check()+1] += 1;
        }
        /*
        if(a[opponent+1]>0) return opponent;
        if(a[0] == 9) return -1;
        if(a[1] > 0) return 0;
        return 2-opponent/2;
         */

        if(a[opponent+1] > 0) return opponent;
        if(a[2-opponent/2+1] > 0) return 3-opponent;
        if(a[0] == 9) return -1;
        if(a[1] > 0) return 0;
    }

    if(part == 3){
        int board[9];
        Board tmp;
        for (int i = 0; i < 9; ++i) {
            tmp.set_board_i(i,this->grid[i].check());
        }
        return tmp.check();
    }

}

void Grid::set_grid_i(int i, Board b) {
    this->grid[i] = b;
}

void Grid::display() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout<<this->grid[i/3*3+j].get_board()[i%3*3+k];
            }
            cout<<" ";
        }
        cout<<endl;
        if(i%3 == 2) cout<<endl;
    }
    cout<<"##############"<<endl;
}

bool Grid::operator==(Grid g1) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(g1.get_grid()[i].get_board()[j] != this->get_grid()[i].get_board()[j]) return false;
        }
    }
    return true;
}





