#Declaration of variable
CXX = clang++-5.0
CXFLAG = -std=c+17
#main target

make: Board.o
	
	

Board.o: Board.cpp Board.h Coordinata.hpp Coordinata.cpp IllegalCharException.hpp IllegalCoordinateException.hpp 
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o



clean:
	rm *.o a.out 



#all: Board.o main.o
#	$(CXX) $(CPPFLAGS) Board.o main.o
#	./a.out
#to abtain o files
