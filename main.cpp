#include <iostream>
#include "TicTacToe.h"
using namespace std;
class TicTacToe;
int main(){
    TicTacToe* myGame = new TicTacToe();
    myGame->startGame();
    delete myGame;
    return 0;
}