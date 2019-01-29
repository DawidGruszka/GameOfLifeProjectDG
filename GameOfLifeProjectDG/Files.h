//
//  Files.h
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 27/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//

#ifndef Files_h
#define Files_h

#include <iostream>
#include "Board.h"


class Files{
public:
    fstream file;
    
    template <class T>
    void saveBoard(T a){
        
        file.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/save.bin", ios::out | ios::binary);
        file.write((char*)&a, sizeof(a));
        file.close();
    }
    
    
    Board readBoard(){
        Board a;
        
        file.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/save.bin", ios::in | ios::binary);
        file.read((char*)&a, sizeof(a));
        file.close();
        
        return a;
        
    }
    
    
    Board demoBoard(){
        Board a;
        
        file.open("/Users/dawid/Documents/xCode/GameOfLifeProjectDG/demo.bin", ios::in | ios::binary);
        file.read((char*)&a, sizeof(a));
        file.close();
        
        return a;
        
    }
        
};

#endif /* Files_h */
