//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_BOARD_HPP
#define TIC_TAC_TOE_BOARD_HPP
#include <iostream>
#include "IllegalCharException.hpp"
#include "IllegalCoordinateException.hpp"
//
#include "Coordinata.hpp"
#include <exception>

using namespace std;

class Boardloc{
public:
    char & location;
    Boardloc(char& loc): location(loc){}
    Boardloc & operator=(char c);
    Boardloc & operator=(Boardloc c);
    operator  char() const{return location;};
    ~Boardloc(){};

};
class Board {
    //mybe will be something here

public:
    int size;
    char* boardmatrix;
    //ctor
    Board(int n): size(n), boardmatrix(new char[size*size]) {

        operator=('.');
    }
    //TODO: fix deep copy
    Board(Board& b2){

        size = b2.size;
        boardmatrix = new char[size*size];
        //naive fix
        for(int i=0;i<size*size;++i){
            boardmatrix[i]=b2.boardmatrix[i];
        }

    }
    Board & operator =(Board &b2){
        delete[] this->boardmatrix;
        this->size=b2.size;
        //naive fix
        for(int i=0;i<size*size;++i){
            this->boardmatrix[i]=b2.boardmatrix[i];
        }
        return *this;
    }
    unsigned int indx(int x,int y) const{
        return x*size+y;
    }
    Board& operator=(char c);
    ostream& printmat(ostream &os)const{for (int i = 0; i < size; ++i) {
            for (int j = 0; j <size ; ++j) {
                os << boardmatrix[indx(i,j)];
            }
            os << endl;
        }
        return os;
    }

    char operator [] (Coordinata c) const{
        if(c.x>=size ||c.x<0||c.y>=size||c.y<0){
            throw IllegalCoordinateException(c);
        }
        return Boardloc(boardmatrix[indx(c.x,c.y)]);
    }

    Boardloc operator [](Coordinata c){
        if(c.x>=size ||c.x<0||c.y>=size||c.y<0){
            throw IllegalCoordinateException(c);
        }
        return boardmatrix[indx(c.x,c.y)];
    }


    //dtor
    ~Board(){

        delete[] boardmatrix;
        //cout << "mat deleted";
    }
};

inline ostream &operator << (ostream &os,const Board& b){
    return b.printmat(os);
};


#endif //TIC_TAC_TOE_BOARD_HPP


