//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP
#define TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP

#include "Coordinata.hpp"
#include <string>
class IllegalCoordinateException{
    //TODO: build class
private:
    // no idea yet
public:
    // no idea yet
    int x,y;
    IllegalCoordinateException(int xp,int yp): x(xp),y(xp){}
    std::string theCoordinate() const{
        return std::to_string(x)+ ","+std::to_string(y);
    }
    IllegalCoordinateException(Coordinata c){
        this->x=c.x;
        this->y=c.y;
    }
};

#endif //TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP
