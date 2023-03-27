#include "card.hpp"
using namespace ariel;

string type;
int value;

Card::Card(int value, string type)
{
    this->value = value;
    this->type = type;
};

int Card::getCardValue()
{
    return this->value;
};

int Card::getCardType()
{
    return this->type;
};

int Card::compareCards(Card card)
{
   return 0;
};


