# cpp-course-tic-tac-toe-tesk
tic tac toe in c++ for cpp course

old make file from tesk 6:
#Declaration of variable
CXX = clang++-5.0
CXFLAG = -std=c+17
#main target
make: Board.o
Board.o: Board.cpp Board.h Coordinate.hpp Coordinate.cpp IllegalCharException.hpp IllegalCoordinateException.hpp 
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o
clean:
	rm *.o a.out 
#all: Board.o main.o
#	$(CXX) $(CPPFLAGS) Board.o main.o
#	./a.out
#to abtain o files

end of makefile
