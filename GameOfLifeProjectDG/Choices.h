//
//  Choices.h
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 16/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//

#ifndef Choices_h
#define Choices_h

class Choices{
public:
    char k, x;
    

    char mainChoice(){
    
        cin>>k;
        if(k!='n' && k!='N' && k!='r' && k!='R' && k!='d' && k!='D'){
            throw "Error. Type in r, n or d.\n";
        }
        return k;
    }
    
    char saveChoice(){
        
        cin>>x;
        if(x!='n' && x!='N' && x!='y' && x!='Y'){
            throw "Wrong choice!";
        }
        return x;
    }


};
#endif /* Choices_h */
