//
// Created by shosh on 5/17/18.
//

#include "Champion.h"

//one way to win
// tnx for xgreenbeen
//https://github.com/xGreenbean/TicTacToe/blob/master/Champion.cpp
const Coordinate Champion::play(const Board &board) {
    for (uint i = 0; i < board.size(); ++i) {
        board[{ board.size()-1,i}]=myChar;
    }
    return {board.size()-1,board.size()-1};

}