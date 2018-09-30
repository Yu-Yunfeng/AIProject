//
// Created by yyf on 9/25/18.
//

#include "Player.h"

Player::Player() {
    this->board = Board();
    this->player = 1;
    this->grid = Grid();
    this->next_board = NULL;
    this->next_grid = NULL;
}

Player::Player(int player, Board board) {
    this->board = board;
    this->player = player;
//    this->grid = NULL;
    this->next_grid = NULL;
    this->next_board = NULL;
}

Player::Player(int player, Grid grid) {
//    this->board = NULL;
    this->player = player;
    this->grid = grid;
    this->next_board = NULL;
    this->next_grid = NULL;
}

Board Player::get_board() {
    return this->board;
}

Board Player::get_next_board() {
    return *(this->next_board);
}

Grid Player::get_grid() {
    return this->grid;
}

Grid Player::get_next_grid() {
    return *(this->next_grid);
}

int Player::get_player() {
    return this->player;
}

float Player::minimax(Board board, float alpha, float beta, int depth) {
    if(this->player == board.get_player()) return maxvalue(board,alpha,beta,depth);
    else return minvalue(board,alpha,beta,depth);
}

float Player::maxvalue(Board board, float alpha, float beta, int depth) {
    Board best;
    if(board.check() != 0 || depth == 0){
        return this->heuristic(board,board.get_player());
    }
    float v = float(INT_MIN);
    for (int i = 0; i < 9; ++i) {
        if(board.islegal(i)){
            Board tmp = board.play(i,board.get_player());
            float v_minimax = minimax(tmp,alpha,beta,depth-1);
            if(v_minimax > v){
                v = v_minimax;
                best = tmp;
            }
            if(v>beta) break;
            alpha = max(alpha,v);
        }
    }
    this->next_board = new Board(best.get_board(),best.get_player());
    return v;
}

float Player::minvalue(Board board, float alpha, float beta, int depth) {
    Board best;
    if(board.check() != 0 || depth == 0){
        return this->heuristic(board,board.get_player());
    }
    float v = float(INT_MAX);
    for (int i = 0; i < 9; ++i) {
        if(board.islegal(i)){
            Board tmp = board.play(i,board.get_player());
            float v_minimax = minimax(tmp,alpha,beta,depth-1);
            if(v_minimax < v){
                v = v_minimax;
                best = tmp;
            }
            if(v<alpha) break;
            beta = (beta,v);
        }
    }
    this->next_board = new Board(best.get_board(),best.get_player());
    return v;
}

float Player::heuristic(Board board,int player) {

    int cpt = this->player;
    int oppo = 3-cpt;
    if(board.check() == -1) {
        return 0;
    }
    if(board.check() == this->player) return 1500;
    if(board.check() + this->player == 3) return -1500;
    if(board.check() == 0){
        int first = 0;
        int second = 0;
        /*
        for (int i = 0; i < 9; ++i) {
            if(board.get_board()[i] == 1) first++;
            if(board.get_board()[i] == 2) second++;
            if(board.get_board()[i] == 0){
                Board nextboard = board.play(i,player);
                int winner = nextboard.check();
                if(winner == oppo) return -1500;
                if(winner == cpt) return 1500;
                if(winner == -1) {
                    if(player == this->player) return -500;
                    else return 500;
                }
            }
        }
         */
/*
        for (int i = 0; i < 9; ++i) {
            if(board.islegal(i)){
                Board boardnext = board.play(i,player);
                for (int j = 0; j < 9; ++j) {
                    if(boardnext.islegal(j)){
                        int winner = boardnext.play(j,player).check();
                        if(winner == oppo) return -500;
                        if(winner == cpt) return 300;
                        if(winner == -1) return -200;
                    }
                }
            }
        }
*/      Board b10 = board;
        return 100*board.diff(b10,this->player);

    }
}

void Player::set_board(Board board) {
    this->board = board;
}

void Player::set_grid(Grid grid) {
    this->grid = grid;
}

float Player::heuristic(Grid grid) {
    if(grid.check(3-this->player) == 2-this->player/2) return -2000;
    if(grid.check(3-this->player) == -1) return 0;
    if(grid.check(3-this->player) == this->player) return 2000;
/*
    if(grid.get_pos() == -1) return minimax(grid.get_grid()[4],-10000,10000,10);
    if(grid.get_grid()[grid.get_pos()].check() == 0){
        return minimax(grid.get_grid()[grid.get_pos()],-10000,10000,10);
    }
    else{
        float minnum = 100000;
        float maxnum = -100000;
        for (int i = 0; i < 9; ++i) {
            Board tmp = grid.get_grid()[i];
            if(tmp.check() == 0){
                if(grid.get_player() == this->player){
                    maxnum = max(maxnum,heuristic(tmp,grid.get_player()));
                }
                else{
                    minnum = min(minnum,heuristic(tmp,grid.get_player()));
                }
            }
        }
        if(grid.get_player() == this->player) return maxnum;
        return minnum;
    }
*/

/*
    if (grid.get_player() == this->player){
        float max_score = INT_MIN;
        for (int i = 0; i < 9; ++i) {
            Board board_i = grid.get_grid()[i];
            for (int j = 0; j < 9; ++j) {
                if(grid.islegal(i,j)){
                    max_score = max(max_score,heuristic(board_i,this->player));
                    break;
                }
            }
        }
        return max_score;
    }

    else{
        float min_score = INT_MAX;
        for (int i = 0; i < 9; ++i) {
            Board board_i = grid.get_grid()[i];
            for (int j = 0; j < 9; ++j) {
                if(grid.islegal(i,j)){
                    min_score = min(min_score,heuristic(board_i,2-this->player/2));
                    break;
                }
            }
        }
        return min_score;
    }
*/
    float res = 0;

    for (int i = 0; i < 9; ++i) {
        res += heuristic(grid.get_grid()[i],this->player);
    }
    return res;


}

float Player::minimax(Grid grid, float alpha, float beta, int depth, int part) {
    if(this->player == grid.get_player()) return maxvalue(grid,INT_MIN,INT_MAX,depth,part);
    else return minvalue(grid,INT_MIN,INT_MAX,depth,part);
}

float Player::maxvalue(Grid grid, float alpha, float beta, int depth, int part) {
    Grid best;
    if(grid.check(part)!=0 || depth == 0){
        if(part == 2) return this->heuristic(grid);
        if(part == 3)return this->heuristic_2(grid);
    }
    float v = INT_MIN;
    for (int i = 0; i < 9; ++i) {
        bool need_break = 0;
        for (int j = 0; j < 9; ++j) {
            if(grid.islegal(i,j)){
                Grid tmp = grid.play(i,j,grid.get_player());
//                if(tmp.check(this->player) == this->player) return 10000;

                float v_minimax = minimax(tmp,alpha,beta,depth-1,part);
//                if(depth == 1) tmp.display();
                if(v_minimax > v){
                    best = tmp;
                    v = v_minimax;
                }
                if(v>beta){
                    need_break = 1;
                    break;
                }
                alpha = max(v,alpha);
            }
        }
        if(need_break) break;
    }
    this->next_grid = new Grid(best.get_grid(),best.get_player(),best.get_pos());
    return v;
}

float Player::minvalue(Grid grid, float alpha, float beta, int depth, int part) {
    Grid best;
    if(grid.check(part)!=0 || depth == 0){
        if(part == 2) return this->heuristic(grid);
        if(part == 3)return this->heuristic_2(grid);
    }
    float v = INT_MAX;
    for (int i = 0; i < 9; ++i) {
        bool need_break = 0;
        for (int j = 0; j < 9; ++j) {
            if(grid.islegal(i,j)){
                Grid tmp = grid.play(i,j,grid.get_player());
                float v_minimax = minimax(tmp,alpha,beta,depth-1,part);
//                if(depth == 1) tmp.display();
                if(v_minimax < v){
                    best = tmp;
                    v = v_minimax;
                }
                if(v < alpha){
                    need_break = 1;
                    break;
                }
                beta = min(v,beta);
            }
        }
        if(need_break) break;
    }
    this->next_grid = new Grid(best.get_grid(),best.get_player(),best.get_pos());
    return v;
}

float Player::heuristic_2(Grid grid) {
    if(grid.check(3) == this->player) return 2000;
    if(grid.check(3) == 3-this->player) return -2000;
    if(grid.check(3) == -1) return 0;

    float res = 0;
    Board tmp;
    for (int i = 0; i < 9; ++i) {
        res += heuristic(grid.get_grid()[i],this->player);
        tmp.set_board_i(i,grid.get_grid()[i].check());
    }

    int he = heuristic(tmp,this->player);
    res += min(he,1000) * 1.3;

    return res;
}
