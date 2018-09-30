#include <iostream>
#include "Board.h"
#include "Player.h"
#include <ctime>
#include "Grid.h"

using namespace std;


int main() {

    Grid b = Grid();
    b.set_pos(0);
    Grid c;
    b.display();
    int part = 3;
    Player player = Player(1,b);
    Player player2 = Player(2,b);
    while(1){
        clock_t t = clock();
        player.minimax(player.get_grid(),-100000,100000,7,part);
        cout<<float(clock()-t)/CLOCKS_PER_SEC<<endl;
        b = player.get_next_grid();
        b.display();

        if(b.check(part) == 1){
            cout<<"Player"<<player.get_player()<<" win"<<endl;
            break;
        }

        if(b.check(part) == -1) break;

        player2.set_grid(b);
        t = clock();
        player2.minimax(player2.get_grid(),-100000,100000,2,part);
        cout<<float(clock()-t)/CLOCKS_PER_SEC<<endl;



//        int x,y;
//        cin>>x>>y;
//        x--;
//        y--;
//        c = b.play(x,y,2);


        c = player2.get_next_grid();
        c.display();
//        if (c.check(2)) break;
        if(c.check(part) == -1) break;
        if(c.check(part) == 2) {
            cout<<"Player"<<player2.get_player()<<" win"<<endl;
            break;
        }

        player.set_grid(c);

    }

/*
    Board board = Board();
//    board.set_board_i(4,1);
//    board.set_player(2);
    board.display();
    Player player = Player(1,board);
    while(1){
        clock_t t =clock();
        player.minimax(player.get_board(),-100,100,10);
        cout<<float(clock()-t)/CLOCKS_PER_SEC<<endl;
        Board b = player.get_next_board();
        b.display();
        if(b.check() != 0) break;
        int x;
        cin>>x;
        x--;
        b = b.play(x,b.get_player());
        b.display();
        if(b.check() != 0) break;
        player.set_board(b);
    }
*/
}
