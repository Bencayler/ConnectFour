#include "Token.h"
#include "Referee.h"

bool Token::getBeenPlayed() {
    return this->beenPlayed;
}

char Token::getSymbol() {
    return this->symbol;
}

void Token::setBeenPlayed(bool input) {
    this->beenPlayed = input;
}

void Token::setSymbol(char input) {
    this->symbol = input;
}

Token::Token(/* args */)
    :beenPlayed(false),
    symbol('0')
{

}

Token::~Token()
{

}