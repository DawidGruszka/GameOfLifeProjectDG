//
//  Menu.h
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 16/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//

#ifndef Menu_h
#define Menu_h
#include "Choices.h"
#include "Board.h"
#include <unistd.h>


class Menu: public Choices{
public:
    //Choices choice;
    char k;
    char i;
    char z;
    int d;
    int u;
    
    Board board;
    
    Menu(){};
    
    void menu(){
    
        i= 2;
        
        
        board.cleanBoard(); //clears the board
        do{
            d=0;
            cout<<"Do you want to read previous state, check demo(oscillator), or start from the beginning?\n*r for read*\n*n for new beginning*\n*d for demo*\n\n";
            
            try{
                k=mainChoice();
            }
            catch(const char* x){
                d=1;
                cerr<<x<<endl;
            }
            
            if(k=='n' || k=='N'){
                board.loadUserData(); //gets data about first alive cells from user
            }
            else if(k=='r' || k=='R'){
                try{
                    board.readBoard(); //reads board from a file called "save.bin"
                }
                catch(const char* s){
                    cerr<< s;
                    board.loadUserData();
                }
            }
            else if(k=='d' || k=='D'){
                board.demoBoard(); //reads demo board from a file called "demo.bin"
            }
        }while(d==1);
        
        while(i!='1'){
            
            board.printBoard(); //prints board
            
            
            cout<<"Type in '1' to break or anything else to continue.\n\n";
            cin>>i;
            
            if(i!='1'){
                board.calculateBoard(); //calculates next board with respect to Conway's game of life rules
            }
        }
        do{
            u=0;
        cout<<"Do you want to save?\n*y for yes*\n*n for no*\n";
        try{
            z=saveChoice();
        }
        catch(const char* o){
            u=1;
            cerr<<o<<endl;
        }
        if(z=='y' || z=='Y'){
            board.saveBoard();//saves the board to a file called "save.bin"
            cout<< "Saved!"<<endl;
        }
        else if(z=='n' || z=='N'){
            cout<< "Not saved!" <<endl;
            }
        }while(u==1);
    }
};
#endif /* Menu_h */
