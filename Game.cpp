//
// Created by Maciej on 05.04.2023.
//

#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;

Game::Game() {
    int dim = InitBoard();
    board = new Board(dim);
    InitPlayers();
}

Game::~Game() {
    for (auto player : List) {
        delete player;
    }
}

void Game::play() {
    bool isGameOver = false;
    ViewBoard();
    while (!isGameOver) {
        for (int i = 0; i < List.size() && !isGameOver; i++) {
            bool madeMove = false;
            while (!board->isFull() && !isGameOver) {
                if(i>=1) {
                    if (board->checkWin(List[i-1]->getSymbol())) {
                        cout << "Won " << List[i-1]->getSymbol() << "!" << endl;
                        isGameOver = true;
                    }
                }
                if (!isGameOver) {
                    List[i]->makeMove();
                    system("cls");
                    madeMove = true;
                    ViewBoard();
                }
                if (madeMove) {
                    break;
                }
            }
            if (board->isFull() && !isGameOver) {
                cout << "Tie!" << endl;
                isGameOver = true;
            }
        }
    }
}

void Game::InitPlayers() {
    int players, bots;
    cout << "Enter number of players who going to play:\n";
    cin >> players;
    for(int i=0; i<players; i++){
        char symbol;
        string name = "Player ";
        name+= to_string(i+1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Human(symbol, *board);
        List.push_back(player);
    }
    cout << "Enter number of bots to play against:\n";
    cin >> bots;
    for(int i=0; i<bots; i++){
        char symbol;
        string name = "Bot ";
        name+= to_string(i+1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Computer(symbol, *board);
        List.push_back(player);
    }
}

int Game::InitBoard() {
    int dim;
    cout << "Enter board dimension: ";
    cin >> dim;
    return dim;
}


