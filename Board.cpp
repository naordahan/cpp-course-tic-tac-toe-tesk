//
// Created by shosh on 5/1/18.
//

#include "Board.hpp"

// verify symbols in game
void verify(char c){
    if (c !='.'&& c!='X' &&c != 'O'){
        throw IllegalCharException{c};
    }
}

//ostream& Board::printmat(ostream &os)const{
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j <size ; ++j) {
//            os << boardmatrix[indx(i,j)];
//        }
//        os << endl;
//    }
//    return os;
//}

Boardloc& Boardloc::operator=(char c){
    verify(c);
    location=c;
    return *this;

}
Board& Board::operator=(char c){
    verify(c);
    for(int i=0;i<size*size;i++){
        boardmatrix[i]= '.';
    }
    return *this;
}