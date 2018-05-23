//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_COORDINATE_HPP
#define TIC_TAC_TOE_COORDINATE_HPP

#include <iostream>
#include "IllegalCharException.hpp"

class Coordinate {
private:
    //variables:
    char symbol;
    uint  x_ind,y_ind;
public:
    //ctor:
    Coordinate(){
        this->symbol='.';}
    Coordinate(char c){
        if(c !='.'&&c !='O'&&c !='X')
            throw IllegalCharException(c);
        this->symbol=c;
    }
    Coordinate(uint x,uint y){x_ind=x;y_ind=y;}
    //getter
    uint getX()const { return x_ind;}
    uint getY()const { return y_ind;}
    char getsymbol()const { return symbol;}
    operator char(){ return this->symbol;}
    //setter
    void setSymbol(char c){
        if(c !='.'&&c !='O'&&c !='X')
            throw IllegalCharException(c);
        this->symbol=c;
    }
    void setcoordinate(Coordinate b){
        x_ind=b.x_ind;
        y_ind=b.y_ind;
    }
    //operators
    void operator=(char c){
        if(c !='.'&&c !='O'&&c !='X')
            throw IllegalCharException(c);
        this->symbol=c;
    }
    friend bool operator==(const Coordinate &c1,char const s){
        return c1.symbol == s;
    }
    //stream out
    friend std::ostream&operator <<(std::ostream& os,const Coordinate& c1){os <<c1.symbol;
        return os;
    }
};

// for clean code?
//    void verify(char c){if(c !='.'&&c !='O'&&c !='X')
//            throw IllegalCharException(c);}


#endif //TIC_TAC_TOE_COORDINATE_HPP
