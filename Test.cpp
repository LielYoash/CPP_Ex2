#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}
TEST_CASE("Test 2 - cards")
{
    Card c1(1, "Spades");
    Card c2(10, "Hearts");
    Card c3(6, "Diamonds");
    Card c4(8, "Clubs");
    Card c5(5, "Spades");
    Card c6(7, "Hearts");
    CHECK(c1.compareto(c1) == 0);
    CHECK(c6.compareto(c2) == -1);
    CHECK(c5.compareto(c1) == 1);
    CHECK(c3.compareto(c4) == -1);
    CHECK(c4.compareto(c3) == 1);
    CHECK(c2.compareto(c6) == 1);
    CHECK(c6.compareto(c6) == 0);
}

TEST_CASE("Test 3 - players")
{
    Player p1("Alice");
    Player p2("Bob");
    Card c1(1, "Spades");
    Card c2(10, "Hearts");
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    p1.addCard(c1);
    p2.addCard(c2);
    CHECK(p1.stacksize() == 27);
    CHECK(p1.cardesTaken() == 28);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 27);
}

TEST_CASE("Test 4 - game")
{
    Player p1("Alice");
    Player p2("Bob");
    Card c1(2, "Spades");
    Card c2(6, "Hearts");
    Card c3(9, "Diamonds");
    Card c4(8, "Clubs");
    Card c5(1, "Spades");
    Card c6(5, "Hearts");
    Card c7(10, "Spades");
    Card c8(7, "Hearts");
    Game game(p1, p2);
    CHECK(game.printWiner() == "No winner yet");
    p1.addCard(c1);
    p1.addCard(c2);
    p1.addCard(c3);
    p1.addCard(c4);
    p2.addCard(c5);
    p2.addCard(c6);
    p2.addCard(c7);
    p2.addCard(c8);
    game.playTurn();
    string s = game.printLastTurn();
    CHECK(s == "Alice played 2 Spades, Bob played 1 Clubs");
    CHECK(p1.cardesTaken() == 1);
    CHECK(p2.stacksize() == 25);

    game.playAll();
    if (p1.stacksize() == 0)
    {
        CHECK(game.printWiner() == "Bob");
        string winner = game.printWiner();
    }
    else if (p2.stacksize() == 0)
    {
        CHECK(game.printWiner() == "Alice");
        string winner = game.printWiner();
    }
    else
    {
        CHECK(game.printWiner() == "No winner yet");
    }
    

    CHECK(p1.cardesTaken() >= 26);
    CHECK(p1.stacksize() ==52);
    CHECK(p2.stacksize() == 0);

}