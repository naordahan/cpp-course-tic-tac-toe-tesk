
CXX=clang++-5.0
CXFLAG=-std=c+17
all: Board.o main.o
	$(CXX) $(CPPFLAGS) Board.o main.o
	./a.out

Board.o: main.cpp Board.cpp Board.h 
	$(CXX) $(CPPFLAGS) -c Board.cpp -o Board.o

main.o: main.cpp Board.h
	$(CXX) $(CPPFLAGS) -c main.cpp  -o main.o
clean:
rm *.o a.out
