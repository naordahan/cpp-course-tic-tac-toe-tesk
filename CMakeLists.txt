cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp Board.cpp Board.h IllegalCharException.hpp IllegalCharException.hpp IllegalCoordinateException.hpp Coordinate.cpp Coordinate.hpp DummyPlayers.cpp DummyPlayers.h Player.cpp Player.hpp Champion.cpp Champion.h TicTacToe.cpp TicTacToe.h)