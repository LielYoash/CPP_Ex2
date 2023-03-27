#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace ariel;

Game::Game(Player p1, Player p2)
{
    this->player1 = p1;
    this->player2 = p2;
};

void Game::play(){};

string Game::printGameStats(){return ""};

string Game::printGameWinner(){return ""};

string Game::printGameLog(){return ""};

string Game::printLastPlayer(){return ""};

string Game::printLastTurn(){return ""};

void Game::playAll(){};