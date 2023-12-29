#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

class Token
{
private:
    bool beenPlayed;
    char symbol;

public:
    bool getBeenPlayed();
    char getSymbol();

    void setBeenPlayed(bool beenPlayed);
    void setSymbol(char symbol);

    Token();
    ~Token();
};



#endif