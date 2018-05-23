//
// Created by shosh on 5/17/18.
//

#include "TicTacToe.h"
///TODO fix board parts.
TicTacToe::TicTacToe(int size):theBoard(size){
    this->BoardSize=size;

};
void TicTacToe::play(Player&p1,Player&p2){
    this->theBoard='.';
    int fullsize=BoardSize*BoardSize;
    int counter=0;
    p1.setMyChar('X');
    p2.setMyChar('O');
    Coordinate tmp(0,0);
    while (counter<fullsize){
        counter++;
        try{
            tmp.setcoordinate(p1.play(theBoard));
            if(theBoard[tmp]=='.'){
                theBoard[tmp]=p1.getChar();
            }else {theWinner=&p2; return;}
        }
        catch (const string& msg){

            theWinner=&p2;
            return;
        }
        if(check_Win('X')){
            theWinner=&p1;
            return;
        }
        counter++;
        if(counter<fullsize){
            try{
                tmp.setcoordinate(p2.play(theBoard));
                if(theBoard[tmp]=='.'){
                    theBoard[tmp]=p2.getChar();
                }else {theWinner=&p1; return;}

            }
            catch(const string& msg){
                theWinner=&p1;
                return;
            }
            if(check_Win('O')){
                theWinner=&p2;
                return;
            }
        }
    }
    theWinner=&p2;
};

bool TicTacToe::check_Win(char s)const{
    bool ans=true;
    for (uint i=0;i<BoardSize;++i) {
        ans = true;
        //cheak 1: row
        for (uint j = 0; j < BoardSize; ++j) {
            if (theBoard[{i, j}] != s) {
                ans = false;
                break;
            }
        }
        if (ans) return true;
        //cheak 2:colm
        ans = true;
        for (uint j = 0; j < BoardSize; ++j) {
            if (theBoard[{j, i}] != s) {
                ans = false;
                break;
            }
        }
        if (ans) return true;
    }
    //cheak 3: main diagonal
    ans=true;
    for (uint i = 0; i < BoardSize; ++i) {
        if (theBoard[{i, i}] != s) {
            ans = false;
            break;
        }
    }if (ans) return true;
    //cheak 4: secondary diagonal
    ans=true;
    for (uint i = 0; i < BoardSize; ++i) {
        if (theBoard[{BoardSize-1-i, i}] != s) {
            ans = false;
            break;
        }
    }
    return ans;
};





/////////
