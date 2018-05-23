//
// Created by shosh on 5/17/18.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include "Board.h"
#include "Player.hpp"


class TicTacToe {
public:
    //variables:
    Board theBoard;
    Player* theWinner;
    int BoardSize;

    //ctor
    TicTacToe(int size);
    //game
    void play(Player&p1,Player&p2);
    bool check_Win(char s)const;
    Board board() const{return  theBoard;} //find the prb
    Player& winner() const {return *theWinner;};
    //

};


#endif //TIC_TAC_TOE_TICTACTOE_H
