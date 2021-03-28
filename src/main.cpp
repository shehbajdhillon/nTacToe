#include <cstdlib>
#include <iostream>
#include <vector>

#include "player.hpp"
#include "board.hpp"

using namespace std;

int main() {
  int size = 3;
  Board board = Board(size);
  int coord;
  board.printGrid();
  while (true) {
    cin >> coord;
    system("clear");
    coord = board.translate(coord);
    board.placeMark(coord, 'Y');
    if (board.validateBoard()) {
      std::cout << "LESSGO\n";
      break;
    }
    board.printGrid();
  }
  return 0;
}

