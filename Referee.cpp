#include "Referee.h"
#include "Token.h"
#include <iostream>
#include <string>

void Referee::displayBoard() const {
    for (int x = 0; x < NUM_ROWS; x++) {
        for(int y = 0; y < NUM_COLUMNS; y++) {
            std::cout << " " << gameboard[x][y].getSymbol() << " ";
        }
    std::cout << "\n";
    }

    std::cout << " A  B  C  D  E  F  G\n";
}

void Referee::play() {
    char selection = ' ';
    
    while (true) {
        playerMove('1', selection);


        playerMove('2', selection);

    }
}

bool Referee::checkForWinner(Token **gameboard, int colIndex, int rowIndex, char playerNumber) {

    int count = 0; // Maybe 0?

    std::cerr << "CHECK RIGHT\n";

    // Check right
    for (int i = colIndex; i < NUM_COLUMNS; i++) {
        if(gameboard[rowIndex][i].getSymbol() == '1') {
            count++;
        } else break;
    }

    // Check left
    for (int i = colIndex - 1; i >= 0; i--) {
        if(gameboard[rowIndex][i].getSymbol() == playerNumber) {
        count++;
        } else break;
    }

    if (count >=4) {
        return true; 
    }


    // Check vertival
    count = 0;
    for (int i = rowIndex; i < NUM_ROWS; i++) {
        if(gameboard[i][colIndex].getSymbol() == playerNumber) {
            count++;
        } else break;
    }
    if (count >=4) {
        return true; 
    }
    
    count = 0;
    // Check diagonal to the right (downwards)
    for (int i = rowIndex, j = colIndex; i < NUM_ROWS && j < NUM_COLUMNS; ++i, ++j) {
        if (gameboard[i][j].getSymbol() == playerNumber) {
            count++;
        } else break;
    }

    // Check diagonal to the left (upwards)
    for (int i = rowIndex - 1, j = colIndex - 1; i >= 0 && j >= 0; --i, --j) {
        if (gameboard[i][j].getSymbol() == playerNumber) {
            count++;
        } else break;
    }
    
    if (count >=4) {
        return true; 
    }

    count = 0;
    // Check diagonal to the right (upwards)
    for (int i = rowIndex, j = colIndex; i >= 0 && j < NUM_COLUMNS; --i, ++j) {
        if (gameboard[i][j].getSymbol() == playerNumber) {
            count++;
        } else break;
    }

    // Check diagonal to the left (downwards)
    for (int i = rowIndex + 1, j = colIndex - 1; i < NUM_ROWS && j >= 0; ++i, --j) {
        if (gameboard[i][j].getSymbol() == playerNumber) {
            count++;
        } else break;
    }

    if (count >=4) {
        return true; 
    }
    
    return false; // DEFAULT
}
// changing playerNumber to a char type
void Referee::playerMove(char playerNumber, char& selection) {
    int rowIndex = 0;
    int colIndex = 0;

    std::cout << "Player " << playerNumber << " make a selection\n";
    displayBoard();

    getInput(selection);

    std::cerr << "Selection: " << selection << "\n"; 


    colIndex = selection - 'A';

    // For piece placement, work in reverse of what the piece would actually do. 
    // Start at the bottom, iterate up the board, place the piece in the first open space.
    for (int i = NUM_ROWS - 1; i >= 0; i--) {
        if (!gameboard[i][colIndex].getBeenPlayed()) { 
            gameboard[i][colIndex].setBeenPlayed(true); 
            gameboard[i][colIndex].setSymbol(playerNumber); 
            rowIndex = i;
            break;
        }
    }

    std::cerr << "Row Index: " << rowIndex << "\n";

    if (checkForWinner(gameboard, colIndex, rowIndex, playerNumber) == true) {
        std::cout << "Player " << playerNumber << " wins!\n";
        std::exit(0);
         
    }
}


void Referee::getInput(char& selection) {
    std::cout << "Choose your desired column\n";
    std::cin >> selection;
    
    
    while (selection < 'A' || selection > 'G') {
        std::cout << "Invalid input detected. Enter a valid column (A-G): ";
        std::cin >> selection;
    }
}


Referee::Referee(/* args */) {
    gameboard = new Token*[NUM_ROWS];    
    for (int i = 0; i < NUM_ROWS; ++i) {
        gameboard[i] = new Token[NUM_COLUMNS];
    }
}

Referee::~Referee() {
    for (int i = 0; i < NUM_ROWS; ++i) {
        delete[] gameboard[i];
     }
        
    delete[] gameboard;    
}
