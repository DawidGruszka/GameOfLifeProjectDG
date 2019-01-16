//
//  Board.h
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 16/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//

#ifndef Board_h
#define Board_h

#define alive 1
#define dead 0

#define height 18
#define width 18
#define heightx 17
#define widthx 17

using namespace std;

class Board{
public:
    Cell board[height][width];
    
    Board(){};
    
    void printBoard(){
        int maxh, maxw;
        
        for(maxh=heightx-1; maxh>=1; maxh--){
            for(maxw=1; maxw<=widthx-1; maxw++){
                if(board [maxh][maxw].state==alive){
                    cout<<"#";
                }
                else if(board [maxh][maxw].state==dead){
                    cout<<"-";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    void cleanBoard(){
        int maxh, maxw;
        for(maxh=0; maxh<=heightx; maxh++){
            for(maxw=0; maxw<=widthx; maxw++){
                board [maxh][maxw].state = 0;
            }
        }
    }
    
    void loadUserData(){
        int amount;
        int x;
        int cordx, cordy;
        
        cout<<"How many life cells do you want to have?\n";
        cin>>amount;
        
        for(x=1; x<=amount; x++){
            cout<<"Type in x coordinate for life cell #"<< x << "(1-"<< heightx <<")\n";
            cin>>cordx;
            cout<<"Type in y coordinate for life cell #"<< x << "(1-"<< widthx <<")\n";
            cin>>cordy;
            
            
            board [cordy][cordx].state = alive;
        }
        
    }
    
    void calculateBoard(){
        int maxh, maxw;
        
        
        
        for(maxh=0; maxh<=heightx; maxh++){
            for(maxw=0; maxw<=widthx; maxw++){
                
                board[maxh][maxw].neighbourCount=0;
                board[maxh][maxw].neighbourCount+=board[maxh-1][maxw-1].state; //top left corner
                board[maxh][maxw].neighbourCount+=board[maxh-1][maxw].state; //middle top
                board[maxh][maxw].neighbourCount+=board[maxh-1][maxw+1].state; //top right corner
                board[maxh][maxw].neighbourCount+=board[maxh][maxw-1].state; //middle left
                board[maxh][maxw].neighbourCount+=board[maxh][maxw+1].state; //middle right
                board[maxh][maxw].neighbourCount+=board[maxh+1][maxw-1].state; //bottom left corner
                board[maxh][maxw].neighbourCount+=board[maxh+1][maxw].state; //middle bottom
                board[maxh][maxw].neighbourCount+=board[maxh+1][maxw+1].state; //bottom right corner
                
                
            }}
        
        for(maxh=0; maxh<=heightx; maxh++){
            for(maxw=0; maxw<=widthx; maxw++){
                if(board[maxh][maxw].state== alive && board[maxh][maxw].neighbourCount==2 ){
                    board[maxh][maxw].state= alive;
                }
                else if(board[maxh][maxw].state== alive && board[maxh][maxw].neighbourCount==3){
                    board[maxh][maxw].state= alive;
                }
                else if(board[maxh][maxw].state== dead && board[maxh][maxw].neighbourCount==3){
                    board[maxh][maxw].state= alive;
                }
                else{
                    board[maxh][maxw].state= dead;
                }
            }
        }
        for(maxh=0; maxh<=heightx; maxh++){
            for(maxw=0; maxw<=widthx; maxw++){
                if(maxh==0 || maxw==0 || maxh==heightx || maxw==widthx){
                    board[maxh][maxw].state=0;
                }}}
        
    }
    
    void saveBoard(){
        fstream fileS;
        fileS.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/save.bin", ios::out | ios::binary);
        fileS.write((char*)&board, sizeof(board));
        fileS.close();
        
    }
    void readBoard(){
        int sum= 0;
        fstream fileR;
        fileR.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/save.bin", ios::in | ios::binary);
        fileR.read((char*)&board, sizeof(board));
        fileR.close();
        
        for(int maxh=0; maxh<=heightx; maxh++){  //checks if board in a file is empty
            for(int maxw=0; maxw<=widthx; maxw++){
                sum += board[maxh][maxw].state;
            }}
        if(sum==0){
            throw "The board read from a save file is empty, start from the beginning.\n\n";
        }
    }
    void demoBoard(){
        int sum= 0;
        fstream fileR;
        fileR.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/demo.bin", ios::in | ios::binary);
        fileR.read((char*)&board, sizeof(board));
        fileR.close();
        
        for(int maxh=0; maxh<=heightx; maxh++){  //checks if board in a file is empty
            for(int maxw=0; maxw<=widthx; maxw++){
                sum += board[maxh][maxw].state;
            }}
        
    }
};

#endif /* Board_h */
