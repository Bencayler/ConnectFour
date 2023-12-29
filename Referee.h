#ifndef REFEREE_H_INCLUDED
#define REFEREE_H_INCLUDED
#include "Token.h"
#include <iostream>

const static int NUM_COLUMNS = 7;
const static int NUM_ROWS = 6;

class Referee
    {
    private:
        static const int NUM_ROWS = 6;
        static const int NUM_COLUMNS = 7;
        
        Token** gameboard;
        int rowIndex;
        int colIndex;

    public:
        Referee();
        ~Referee();

        void play();
        bool checkForWinner(Token** gameboard, int colIndex, int rowIndex, char playerNumber);
        void playerMove(int playerNumber, char& selection);
        void playerMove(char playerNumber, char& selection);
        void getInput(char& selection);
        void generateBoard();
        void displayBoard(std::ostream &outs) const;
        void displayBoard() const;
    };
    
#endif
