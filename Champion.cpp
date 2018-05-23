//
// Created by shosh on 5/17/18.
//

#include "Champion.h"

//one way to win
// tnx for xgreenbeen
//one way to win many games
//const Coordinate Champion::play(const Board &board) {
//    for (uint i = 0; i < board.size(); ++i) {
//        board[{ board.size()-1,i}]=myChar;
//    }
//    return {board.size()-1,board.size()-1};
//}
//but this one better
const Coordinate Champion::play(const Board &board) {
    if(board[{board.size()-1,0}]=='.'){
        return{board.size()-1,0};
    }
    if(board[{0,board.size()-1}]=='.') {
        return{0,board.size()-1};
    }

    uint i,j;
    i=board.size()-1;
    j=0;
    while(j<board.size()){
        Coordinate c1{i,j};
        if(board[c1]=='.'){return c1;}
        i--;
        j++;
    }
    return{0,0};
}