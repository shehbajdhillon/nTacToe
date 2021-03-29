#include <iostream>
#include "utils.hpp"

using namespace std;

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

void printGrid(vector<vector<int>> grid, int size) {

  for (vector<int> row: grid) {
    cout << " ";
    for (int i: row) {
      cout << (char)i << " | ";
    }
    cout << "\n";
    for (int i = 0; i < size; i++) {
      cout << "----";
    }
    cout << "\n";
  }
}
