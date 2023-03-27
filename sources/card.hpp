#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Card
    {
    private:
        string type;
        int value;

    public:
        Card(int value, string type);
        int compareCards(Card card);
        int getCardValue();
        string getCardType();
    };
}
#endif /* Card_hpp */