//
// Created by yyf on 9/25/18.
//

#include "Board.h"

Board::Board() {
    for (int i = 0; i < 9; ++i) {
        this->board[i] = 0;
    }
    this->player = 1;
    this->next_action = -1;
}

Board::Board(int* board, int player) {
    for (int i = 0; i < 9; ++i) {
        this->board[i] = board[i];
    }
    this->player = player;
    this->next_action = -1;
}

int *Board::get_board() {
    return this->board;
}

void Board::set_board(int *board) {
    for (int i = 0; i < 9; ++i) {
        this->board[i] = board[i];
    }
}

int Board::get_player() {
    return this->player;
}

int Board::get_next_action() {
    return this->next_action;
}

void Board::set_next_action(int action) {
    this->next_action = action;
}

void Board::set_player(int player) {
    this->player = player;
}

void Board::display() {
    for (int i = 0; i < 9; ++i) {
        cout<<this->board[i]<<" ";
        if(i%3 == 2) cout<<endl;
    }
}

int Board::check() {
    for (int i = 0; i < 3; ++i) {
        if(this->board[i*3+0] == this->board[i*3+1] && this->board[i*3+1] == this->board[i*3+2] && this->board[i*3+0] > 0) {
            return this->board[i*3+0];
        }
        if(this->board[0*3+i] == this->board[1*3+i] && this->board[1*3+i] == this->board[2*3+i] && this->board[0*3+i] > 0) return this->board[0*3+i];
    }
    if(this->board[0] == this->board[4] && this->board[4] == this->board[8] && this->board[4] > 0) return this->board[4];
    if(this->board[2] == this->board[4] && this->board[4] == this->board[6] && this->board[4] > 0) return this->board[4];
    for (int i = 0; i < 9; ++i) {
        if(!this->board[i]) return 0;
    }
    return -1;
}


Board Board::play(int pos, int player) {
    Board res = *this;
    res.set_player(2-player/2);
    res.set_board_i(pos,player);
    return res;
}

bool Board::islegal(int pos) {
    if(!this->board[pos]) return true;
    return false;
}

void Board::set_board_i(int pos, int value) {
    this->board[pos] = value;
}

int Board::diff(Board b, int cpt) {
    Board b1 = b;
    Board b2 = b;
    for (int i = 0; i < 9; ++i) {
        if(b.get_board()[i] == 0) b1.set_board_i(i,cpt);
    }
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        bool br = 0;
        for (int j = 0; j < 3; ++j) {
            if(b1.get_board()[1*3+j] != cpt) br = 1;
        }
        if(br) continue;
        count += 1;
    }

    for (int i = 0; i < 3; ++i) {
        bool br = 0;
        for (int j = 0; j < 3; ++j) {
            if(b1.get_board()[j*3+i] != cpt) br = 1;
        }
        if(br) continue;
        count += 1;
    }

    if(b1.get_board()[0] == b1.get_board()[4] && b1.get_board()[4] ==b1.get_board()[8] && b1.get_board()[4] == cpt) count++;
    if(b1.get_board()[2] == b1.get_board()[4] && b1.get_board()[4] ==b1.get_board()[6] && b1.get_board()[4] == cpt) count++;

    for (int i = 0; i < 9; ++i) {
        if(b.get_board()[i] == 0) b2.set_board_i(i,cpt);
    }
//    int count = 0;
    for (int i = 0; i < 3; ++i) {
        bool br = 0;
        for (int j = 0; j < 3; ++j) {
            if(b2.get_board()[1*3+j] != cpt) br = 1;
        }
        if(br) continue;
        count--;
    }

    for (int i = 0; i < 3; ++i) {
        bool br = 0;
        for (int j = 0; j < 3; ++j) {
            if(b2.get_board()[j*3+i] != cpt) br = 1;
        }
        if(br) continue;
        count--;
    }

    if(b2.get_board()[0] == b2.get_board()[4] && b2.get_board()[4] ==b2.get_board()[8] && b2.get_board()[4] == 3-cpt) count--;
    if(b2.get_board()[2] == b2.get_board()[4] && b2.get_board()[4] ==b2.get_board()[6] && b2.get_board()[4] == 3-cpt) count--;

    return count;
}

