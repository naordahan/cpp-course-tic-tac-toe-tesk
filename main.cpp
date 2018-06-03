#include "Board.h"
#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;



int main() {
    Board board;
    cin >> board;

    string filename = board.draw(600);
    cout << filename << endl;
    return 0;
}