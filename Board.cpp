//
// Created by shosh on 5/1/18.
//

#include "Board.h"
#include "stdio.h"
#include <vector>
#include <list>
#include <cmath>
//ctor:

Board::Board(const uint size){
    this->bsize=size;
    boardmatrix=new Coordinate*[size];
    for(int i=0;i<size;++i){
        boardmatrix[i]=new Coordinate[size];
    }
    //fill board with '.'
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j <size ; ++j) {
            boardmatrix[i][j]='.';
        }
    }
}
Board::Board(){
    this->bsize=3;
    boardmatrix=new Coordinate*[bsize];
    for(int i=0;i<bsize;++i){
        boardmatrix[i]=new Coordinate[bsize];
    }
    //fill board with '.'
    for (int i = 0; i <bsize ; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j]='.';
        }
    }
}
//copy ctor
Board::Board(const Board& b2){
    this->bsize=b2.size();
    this->boardmatrix =new Coordinate*[this->bsize];
    for(int i=0;i<bsize;++i){
        boardmatrix[i]=new Coordinate[bsize];
    }
    for (int i = 0; i <bsize ; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j]=b2.boardmatrix[i][j];
        }
    }
}
// dtor
Board::~Board(){
    for (int i = 0; i <bsize ; ++i) {
        delete[] boardmatrix[i];
    }
        delete [] boardmatrix;

}

Board& Board::operator=(char c){
    if(c !='.'&&c !='O'&&c !='X')
        throw IllegalCharException(c);
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j]=c;
        }
    }
    return *this;
}
Board& Board::operator =(const Board& b2){
    this->~Board();
    bsize=b2.size();
    this->boardmatrix =new Coordinate*[this->bsize];
    for(int i=0;i<bsize;++i){
        boardmatrix[i]=new Coordinate[bsize];
    }
    for (int i = 0; i <bsize ; ++i) {
        for (int j = 0; j <bsize ; ++j) {
            boardmatrix[i][j].setSymbol(b2.boardmatrix[i][j].getsymbol()); //why not boardmatrix[i][j]=b2.boardmatrix[i][j];
        }
    }
    return *this;
}

Coordinate& Board::operator[](const Coordinate& c)const{
    if(c.getX()>=bsize ||c.getY()>=bsize)
        throw IllegalCoordinateException({c.getX(),c.getY()});
    return boardmatrix[c.getX()][c.getY()];
}
ostream&operator <<(ostream& os ,const Board& theboard){
    for (int i = 0; i <theboard.bsize ; ++i) {
        for (int j = 0; j <theboard.bsize ; ++j) {
            os<<theboard.boardmatrix[i][j];
        }
        os<<'\n';
    }
    return os;
}
istream& operator >>(istream& cin , Board& theboard){
    string line;
    //cout<< "3";
    cin >> line;         
    //cout<< "4";
    Board tmp(line.length());
    //cout<< "5";
    theboard=tmp;
    //cout<< "before loop\n";

    for (int i = 0; i <theboard.size() ; ++i) {
        for (int j = 0; j <theboard.size() ; ++j) {
            //cout << "inside";
           // cout << line[j] <<"  ";
            theboard.boardmatrix[i][j]=line[j];    //TODO:we have IllegalCharException all the time in clion!! why?
            
        }
       // cout << '\n';
        cin >> line;
    }
    return cin;
    }

//so far so good
//TODO: make it work
//TODO:fix this one: not working 
void Dcircle(RGB* imge,int Xfrom,int Xto,int Yfrom,int Yto,int dimy){
    int R = ((Xto - Xfrom) / 2) -(int)((Xto-5 - Xfrom+5)%10);  //redius - need to fix
				int Ox = (Xto - Xfrom) / 2 ;      // xmid
				int Oy = (Yto - Yfrom) / 2 ;      //ymid
    //  a nicer circale with the help of yossi
                for (int y=0; y<2*R; y++){
                    for (int x=0; x<2*R; x++){
                        if ( floor(sqrt( (x-Ox)*(x-Ox) + (y-Oy)*(y-Oy) ) ) == R-10 ) {
                            imge[dimy * (y + Yfrom) + Xfrom + x]={0,0,255};
                            imge[dimy * (y + Yfrom) + Xfrom + x+1]={0,0,255};
                            imge[dimy * (y + Yfrom) + Xfrom + x+2]={0,0,255};
                            imge[dimy * (y + Yfrom) + Xfrom + x-1]={0,0,255};
                        }
                    }
                }              
}
void Dex(RGB* imge,int Xfrom,int Xto,int Yfrom,int Yto,int dimy){
    //func tha draw x
    for (int r = 10; r < Yto - Yfrom - 10 ; ++r) {
					//Drawing main diagonal of X
                    imge[dimy * (r + Yfrom) + Xfrom + r]={255,0,0};
                    //make shape bigger/bold
                    imge[dimy * (r + Yfrom) + Xfrom + r-1]={255,0,0};
                    imge[dimy * (r + Yfrom) + Xfrom + r+1]={255,0,0};					
					//Drawing secondery diagonal of X
                    imge[dimy * (r + Yfrom) + Xto - (r)]={255,0,0};
                    //make shape bigger/bold
                    imge[dimy * (r + Yfrom) + Xto - (r)-1]={255,0,0};
                    imge[dimy * (r + Yfrom) + Xto - (r)+1]={255,0,0};
	}  
}


string Board::draw(int nPx){
    const int dimx=nPx;
    const int dimy=nPx;
    string fileName="myboard.ppm";
    ifstream file(fileName);
    bool myfileExist=false;
    if(file){
        //cout<< "i's exist!!!"<<'\n';
        myfileExist=true;
    }
    int i=1;
    while(myfileExist){  //if we have pic alredy
        fileName="MyBoard";
        fileName+=to_string(i);
        fileName+=".ppm";

        ifstream file(fileName);
        if(file){i++;}
        else{myfileExist=false;}
    }
    //create new file
    ofstream imgFile(fileName);
    imgFile<<"P6"<<'\n'<< dimx << " " << dimy << '\n' << 255 <<'\n';
    // start building the pic:   
    // create mat for pixel:   
    RGB imge[dimx*dimy];
    //background color
    for(int j=0; j<dimy;j++){  // row
       for(int i=0; i<dimx;i++){ // column               
        //    imge[(dimx*j)+i].red = (i % 256);
        //    imge[(dimx*j)+i].green = (j % 256);
        //    imge[(dimx*j)+i].blue = ( ((i*i)+(j*j)) % 256);
           imge[(dimx*j)+i]={240,240,24};           
         }
    } 
    int cellsize = dimx/bsize; //size for each coordinate
    //lets make speration lins
    //Drawing the cols
	for (int i = 0; i < bsize; ++i) {
		int Xfrom = i * (cellsize);
		for (int r = 3; r < dimy - 3 ; ++r) {
            imge[dimy * (r) + Xfrom]={0,0,0};			
		}
	}
	//Drawing the rows
	for (int j = 0; j < bsize; ++j) {
		int Yfrom = j * (cellsize) ;
		for (int r = 3; r < dimx - 3 ; ++r) {
            imge[(r) + Yfrom * dimy]={0,0,0};
		}
	}
	int loop = 0;
	//Drawing symbols
	for (int row = 0; row < bsize; ++row) {
		for (int column = 0; column < bsize; ++column) {
            //coordinate for moving between cells
			int Xfrom = column * (cellsize);
			int Xto = (column + 1) * (cellsize); //dont include the last bit
			int Yfrom = row * (cellsize) ;
			int Yto = (row + 1) * (cellsize); //dont include the last bit
			if (boardmatrix[row][column] == 'X') {
                //Drawing X
                Dex(imge,Xfrom,Xto,Yfrom,Yto,dimy);  			
			}
			else if(boardmatrix[row][column] == 'O'){
				//Drawing O
                
                //from https://github.com/GeekCSA/Exercise-8---Draw/blob/master/Board.cpp

				// int R = ((Xto - Xfrom) / 2) -(int)((Xto-5 - Xfrom+5)%10);  //redius - need to fix
				// int Ox = (Xto - Xfrom) / 2 ;      // xmid
				// int Oy = (Yto - Yfrom) / 2 ;      //ymid

				// for (int X = 10; X < Yto - Yfrom - 10 ; ++X) {
				// 	int Y = floor(sqrt(R*R - (X - Ox)*(X - Ox)) + Oy);
				// 	int attach = 20;
				// 	//Drawing bottom size of the circle
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+1]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+2]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+3]={0,0,255};
                //     imge[dimy * (Y + Yfrom - attach) + Xfrom + X+4]={0,0,255};
                //     //Drawing upper size of the circle ?
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+1]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+2]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+3]={0,0,255};
                //     imge[dimy * (Yto - Y + attach) + Xfrom + X+4]={0,0,255};
				// }
                //  a nicer circle with the help of yossi
                 Dcircle(imge,Xfrom,Xto,Yfrom,Yto,dimy);    
			}
		}
	}
    imgFile.write(reinterpret_cast<char*>(&imge),3*dimx*dimy);
    imgFile.close();
    return fileName;
}


///
/*
shosh@shosh-vr:~/CLionProjects/tic-tac-toe$ g++ *.cpp -std=c++17
shosh@shosh-vr:~/CLionProjects/tic-tac-toe$ ./a.out <test.txt
*/