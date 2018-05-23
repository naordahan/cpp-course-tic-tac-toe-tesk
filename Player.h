//
// Created by shosh on 5/17/18.
//

#ifndef TIC_TAC_TOE_PLAYER_HPP
#define TIC_TAC_TOE_PLAYER_HPP
#include <iostream>
// copy from Board.h
#include "IllegalCharException.hpp"
#include "IllegalCoordinateException.hpp"
#include "Coordinate.hpp"
#include "Board.h"
#include <exception>
#include <vector>
//

class Player {
public:
    //variable:
    char myChar;
    //ctor
    Player(){}
    Player(char symbol){
        if(symbol=='O'||symbol=='X'){
            myChar=symbol;
        }else throw IllegalCharException(symbol);
    }
    //auto generate
    char getChar() const {
        return myChar;
    }
    void setMyChar(char myChar) {
        Player::myChar = myChar;
    }
    //func
    virtual const Coordinate play(const Board& board)=0;
    virtual const std::string name() const { return "Player"; }
};


#endif //TIC_TAC_TOE_PLAYER_HPP
