#include "card.hpp"
using namespace ariel;

Card::Card(int value, string type)
{
    this->value = value;
    this->type = type;
};

int Card::compareto(Card card)
{
    return 0;
};
