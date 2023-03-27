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
    public:
        Card(int value, string type);
        int compareto(Card card);
    };
}
#endif /* Card_hpp */