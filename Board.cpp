//
// Created by shosh on 5/1/18.
//

#include "Board.h"
//ctor:
Board::Board(const uint size){
    this->bsize=size;
    boardmatrix=new Coordinate*[size];
    for(int i=0;i<size;++i){
        boardmatrix[i]=new Coordinate[size];
    }
    //fill board with '.'
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j <size ; ++j) {
            boardmatrix[i][j]='.';
        }
    }
}
//copy ctor
Board::Board(const Board& b2){
    this->bsize=b2.size();
    this->boardmatrix =new Coordinate*[this->bsize];
    for(int i=0;i<bsize;++i){
        boardmatrix[i]=new Coordinate[bsize];
    }
    for (int i = 0; i <bsize ; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j]=b2.boardmatrix[i][j];
        }
    }
}
// dtor
Board::~Board(){
    for (int i = 0; i <bsize ; ++i) {
        delete[] boardmatrix[i];
    }
        delete [] boardmatrix;

}


Board& Board::operator=(char c){
    if(c !='.'&&c !='O'&&c !='X')
        throw IllegalCharException(c);
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j]=c;
        }
    }
    return *this;
}
Board& Board::operator =(const Board& b2){
    this->~Board();
    bsize=b2.size();
    this->boardmatrix =new Coordinate*[this->bsize];
    for(int i=0;i<bsize;++i){
        boardmatrix[i]=new Coordinate[bsize];
    }
    for (int i = 0; i <bsize ; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j].setSymbol(b2.boardmatrix[i][j].getsymbol()); //why not boardmatrix[i][j]=b2.boardmatrix[i][j];
        }
    }
    return *this;
}

Coordinate& Board::operator[](const Coordinate& c)const{
    if(c.getX()>=bsize ||c.getY()>=bsize)
        throw IllegalCoordinateException({c.getX(),c.getY()});
    return boardmatrix[c.getX()][c.getY()];
}
  ostream&operator <<(ostream& os ,const Board& theboard){
    for (int i = 0; i <theboard.bsize ; ++i) {
        for (int j = 0; j <theboard.bsize ; ++j) {
            os<<theboard.boardmatrix[i][j];
        }
        os<<endl;
    }
    return os;
}