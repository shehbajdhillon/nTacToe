#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>

#include "player.hpp"
#include "board.hpp"
#include "utils.hpp"

using namespace std;

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
    printGrid(board.getGrid(), size);
    cout << currPlayer.getName() << "'s " << "turn.\n";
    cin >> coord;
    coord = translate(coord);
    if (board.placeMark(coord, currPlayer.getSymbol())) {
      idx = (++idx) % (numPlayers);
      symbolsPlaced--;
      if (board.validateBoard()) {
        system("clear");
        printGrid(board.getGrid(), size);
        cout << currPlayer.getName() << " is the winner\n";
        break;
      }
      system("clear");
    }
    else {
      system("clear");
      cout << "Error Placing mark, try again\n";
    }
  }

  if (!symbolsPlaced) {
    cout << "\nDRAW!\n";
    printGrid(board.getGrid(), size);
  }

  return 0;
}
