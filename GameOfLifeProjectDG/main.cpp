//
//  main.cpp
//  GameOfLifeProjectDG
//
//  Created by Dawid Gruszka on 15/01/2019.
//  Copyright © 2019 Dawid Gruszka. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Cell.h"
#include "Board.h"
#include "Menu.h"
#include "Choices.h"

using namespace std;

int main() {
    Board board;
    Menu menu;
    menu.menu(board);
    
    return 0;
}
