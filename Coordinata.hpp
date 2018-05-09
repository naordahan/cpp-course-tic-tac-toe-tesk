//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_COORDINATA_HPP
#define TIC_TAC_TOE_COORDINATA_HPP

#include <istream>

struct Coordinata {
    int  x,y;
    Coordinata(int xindx,int yindex):x(xindx),y(yindex){};

//    ~Coordinata() {};

//    Coordinata(const Coordinata &c2){
//        setX(c2.x);
//        setY(c2.y);
//    };
    Coordinata operator=(const Coordinata &c2){
//        this-> ~Coordinata();
        setX(c2.x);
        setY(c2.y);
        return *this;
    };

    //getter ans setter -do i neew them?
    int getX() const {
        return x;
    };
    void setX(int x) {
        Coordinata::x = x;
    };
    int getY() const {
        return y;
    };
    void setY(int y) {
        Coordinata::y = y;
    };
    // "to string"
    inline friend std::ostream & operator << (std::ostream &os,const Coordinata a){
        return (os<< a.x <<","<< a.y);
    }


};


#endif //TIC_TAC_TOE_COORDINATA_HPP
