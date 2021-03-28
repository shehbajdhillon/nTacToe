#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std;

class Player {
  public:
    Player(string name, char symbol);
    string getName();
    char getSymbol();
  private:
    string name;
    char symbol;
};

#endif
