#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;

class Game
{
    public:
        Game(Player p1, Player p2);
        void playTurn();
        string printStats();
        string printWiner();
        string printLog();
        string printLastTurn();
        void playAll();
};

#endif /* Game_hpp */

