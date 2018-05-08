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
    Coordinata c;
    IllegalCoordinateException(Coordinata c): c(c){}
    Coordinata theCoordinate() const{
        return c;
    }

};

#endif //TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP
