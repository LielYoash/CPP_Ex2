#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
using namespace std;
using namespace ariel;

class Player
{
    public:
        Player(string name);
        void addCard(Card card);
        void removeCard(Card card);
        int numberOfCardsInStack();
        int numberOfCardsTaken();
};

#endif /* Player_hpp */