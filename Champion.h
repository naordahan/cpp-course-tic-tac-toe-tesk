//
// Created by shosh on 5/17/18.
//

#ifndef TIC_TAC_TOE_CHAMPION_HPP
#define TIC_TAC_TOE_CHAMPION_HPP
//#include "Player.hpp"
#include "Player.h"
#include "Coordinate.hpp"
class Champion: public Player {

public:
    const string name() const override { return "shlomi"; }
    const Coordinate play(const Board &board)override;
};


#endif //TIC_TAC_TOE_CHAMPION_HPP
