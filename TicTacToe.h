#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <map>
#include <string>
using namespace std;
class TicTacToe{
    public:
        TicTacToe();
        ~TicTacToe(){};
        int isWin();
        void playerMove();
        void AIMove();
        void startGame();
        void AICalculate();
        int calculateHelper(int curr);
        string toString();
        void printBoard();
        void clearBoard();

    private:
        int board[9];
        int rep[2];
        map<string, int> nextStep;
        int seq;
};
#endif