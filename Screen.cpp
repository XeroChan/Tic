//
// Created by UL0265663 on 05.05.2023.
//

#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen() = default;

void Screen::ViewBoard() {
    cout << "Screen view:\n";
    board->printBoard();
}

