//
// Created by shosh on 5/1/18.
//

#ifndef TIC_TAC_TOE_ILLEGALCHAREXCEPTION_HPP
#define TIC_TAC_TOE_ILLEGALCHAREXCEPTION_HPP
class IllegalCharException{
private:
    char c;
public:
    IllegalCharException(char c): c(c) {}
    char theChar() const{
        return c;
    }
};

#endif //TIC_TAC_TOE_ILLEGALCHAREXCEPTION_HPP
