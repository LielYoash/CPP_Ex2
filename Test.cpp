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

    CHECK(p1.numberOfCardsInStack() == 26);
    CHECK(p2.numberOfCardsInStack() == 26);
    CHECK(p1.numberOfCardsTaken() == 0);
    CHECK(p2.numberOfCardsTaken() == 0);
}
TEST_CASE("Test 2 - cards")
{
    Card c1(1, "Spades");
    Card c2(10, "Hearts");
    Card c3(6, "Diamonds");
    Card c4(8, "Clubs");
    Card c5(5, "Spades");
    Card c6(7, "Hearts");
    CHECK(c1.getCardValue() == 1);
    CHECK(c1.getCardType() == "Spades");
    CHECK(c1.compareCards(c1) == 0);
    CHECK(c6.compareCards(c2) == -1);
    CHECK(c5.compareCards(c1) == 1);
    CHECK(c2.getCardValue() == 10);
    CHECK(c2.getCardType() == "Hearts");
}

TEST_CASE("Test 3 - players")
{
    Player p1("Alice");
    Player p2("Bob");
    Card c1(1, "Spades");
    Card c2(10, "Hearts");
    CHECK(p1.numberOfCardsInStack() == 26);
    CHECK(p1.numberOfCardsTaken() == 0);
    CHECK(p1.addCard(c1) == 0);
    CHECK(p2.addCard(c2) == 0);
    CHECK(p1.numberOfCardsInStack() == 27);
    CHECK(p1.numberOfCardsTaken() == 28);
    CHECK(p1.removeCard(c1) == 0);
    CHECK(p1.numberOfCardsInStack() == 26);
    CHECK(p1.numberOfCardsTaken() == 26);
    CHECK(p2.numberOfCardsInStack() == 26);
    CHECK(p2.numberOfCardsTaken() == 27);
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
    Game g1(p1, p2);
    CHECK(g1.printGameWinner() == "No winner yet");
    p1.addCard(c1);
    p1.addCard(c2);
    p1.addCard(c3);
    p1.addCard(c4);
    p2.addCard(c5);
    p2.addCard(c6);
    p2.addCard(c7);
    p2.addCard(c8);
    g1.play();
    string s = g1.printLastTurn();
    CHECK(s == "Alice played 2 Spades, Bob played 1 Clubs");
    CHECK(p1.numberOfCardsTaken() == 1);
    CHECK(p2.numberOfCardsInStack() == 25);

    g1.playAllTurns();
    if (p1.numberOfCardsInStack() == 0)
    {
        CHECK(g1.printGameWinner() == "Bob");
        string winner = g1.printGameWinner();
    }
    else if (p2.numberOfCardsInStack() == 0)
    {
        CHECK(g1.printGameWinner() == "Alice");
        string winner = g1.printGameWinner();
    }
    else
    {
        CHECK(g1.printGameWinner() == "No winner yet");
    }
    

    CHECK(p1.numberOfCardsTaken() >= 26);
    CHECK(p1.numberOfCardsInStack() ==52);
    CHECK(p2.numberOfCardsInStack() == 0);

}