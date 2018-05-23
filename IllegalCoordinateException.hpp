//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP
#define TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP

#include "Coordinate.hpp"
#include <string>
#include <exception>
class IllegalCoordinateException:public std::exception{

private:
    // no idea yet
public:
    // no idea yet
    Coordinate c;
    IllegalCoordinateException(Coordinate c): c(c){}
//    Coordinate theCoordinate() const{
//        return c;
//    }
    const std::string theCoordinate() const{
        return std::to_string(c.getX())+','+std::to_string(c.getY());
    }

};

#endif //TIC_TAC_TOE_ILLEGALCOORDINATEEXCEPTION_HPP
