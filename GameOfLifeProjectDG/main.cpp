//
//  main.cpp
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 15/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//
//Topics: Multiple inheritance, Templates, Exceptions, IOstreams    (4)
//Classes: Cell, Board, Files, Choices, Menu                        (5)

#include <iostream>
#include <fstream>
#include "Cell.h"
#include "Board.h"
#include "Menu.h"
#include "Choices.h"

using namespace std;

int main() {
    Menu menu;
    menu.menu();
    
    return 0;
}
