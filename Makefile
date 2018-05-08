#Declaration of variable
CXX = clang++-5.0
CXFLAG = -std=c+17
#main target

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o

main.o: main.cpp Board.hpp
	$(CXX) $(CPPFLAGS) -c main.cpp -o main.o
#to remove generated files

clean:
	rm *.o a.out 



#all: Board.o main.o
#	$(CXX) $(CPPFLAGS) Board.o main.o
#	./a.out
#to abtain o files
