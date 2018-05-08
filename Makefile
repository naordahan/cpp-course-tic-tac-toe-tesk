
CXX=clang++-5.0
CXFLAG=-std=c+17
all: main.cpp Board.cpp Board.hpp IllegalCharException.hpp IllegalCharException.hpp IllegalCoordinateException.hpp Coordinata.hpp
Board.o: main.cpp Board.cpp Board.h 
	$(CXX) $(CPPFLAGS) --compile main.cpp Board.cpp -o Board.o
clean:
rm *.o 
