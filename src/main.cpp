#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>

#include "player.hpp"
#include "board.hpp"

using namespace std;

int translate(int num);

int main() {
  int size, numPlayers;
  size = 3;

  cout << "Enter number of players: ";
  cin >> numPlayers;
  vector<Player> playersList;
  while ((getchar() != '\n'));

  for (int i = 1; i <= numPlayers; i++) {
    char symbol;
    ostringstream name;
    name << "Player " << i;
    cout << "Player " << i << " symbol: ";
    symbol = getchar();
    Player player = Player(name.str(), symbol);
    playersList.push_back(player);
    while ((getchar() != '\n'));
  }

  system("clear");

  Board board = Board(size);

  int idx = 0;
  int symbolsPlaced = size * size;
  while (symbolsPlaced) {
    cout << "\n\n";
    int coord;
    Player currPlayer = playersList[idx];
    board.printGrid();
    cout << currPlayer.getName() << "'s " << "turn.\n";
    cin >> coord;
    coord = translate(coord);
    if (board.placeMark(coord, currPlayer.getSymbol())) {
      idx = (++idx) % (numPlayers);
      symbolsPlaced--;
      if (board.validateBoard()) {
        board.printGrid();
        cout << currPlayer.getName() << " is the winner\n";
        break;
      }
    }
    else {
      cout << "Error Placing mark, try again\n";
    }
  }

  if (!symbolsPlaced) {
    cout << "\nDRAW!\n";
    board.printGrid();
  }

  return 0;
}


int translate(int num) {
  if (num == 7 || num == 8 || num == 9) {
    return num - 7;
  }
  else if (num == 4 || num == 5 || num == 6) {
    return num - 1;
  }
  else if (num == 1 || num == 2 || num == 3) {
    return num + 5;
  }
  else {
    return -1;
  }
}
