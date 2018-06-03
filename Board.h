
#ifndef TIC_TAC_TOE_BOARD_HPP
#define TIC_TAC_TOE_BOARD_HPP
#include <iostream>
#include "IllegalCharException.hpp"
#include "IllegalCoordinateException.hpp"
#include "Coordinate.hpp"
#include <exception>
#include <string>
#include "stdio.h"
#include <fstream>
using namespace std;
// huge tnx for omeressa and xgreenbeen, for help
//https://github.com/omeressa/Cpp-Ex7/blob/master/Board.h
class Board {
public:
    //variables:
    int bsize;
    Coordinate** boardmatrix;
    //ctor
    Board(const uint size);
    Board(const Board& b2);
    Board(); //empty ctor
    //dtor
    ~Board();
    // operators
    Board&operator =(char c);
    Board&operator =(const Board& b2);
    Coordinate&operator[](const Coordinate& c)const;
    friend  ostream&operator <<(ostream& os ,const Board& theboard);
    //
    uint size()const{ return bsize;}
    //input
    friend  istream&operator >>(istream& in , Board& theboard);
    //drew
    string draw(int picpx);


};
// struck for coloer
struct RGB{
    uint8_t red,green,blue;
public:
    RGB(){};
    RGB(uint8_t red,uint8_t green,uint8_t blue):red(red),green(green),blue(blue){}
};

#endif //TIC_TAC_TOE_BOARD_HPP


