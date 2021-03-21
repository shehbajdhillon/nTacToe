#include "board.hpp"
#include <vector>


Board::Board(int size) {
  this->size = size;
  for (int i = 0; i < size; i++) {
    this->grid.push_back(vector<int>(size, -1));
  }
}


vector<vector<int>> Board::getGrid() {
  return this->grid;
}


int Board::getSize() {
  return this->size;
}


bool Board::validateRow(vector<int> row) {
  for(int i = 0; i < this->size - 1; i++) {
    if (row[i] == -1 || row[i] != row[i + 1]) {
      return false;
    }
  }
  return true;
}


bool Board::validateRows() {
  for (vector<int> row: this->grid) {
    if (this->validateRow(row)) {
      return true;
    }
  }
  return false;
}


bool Board::validateCols() {
  for (int i = 0; i < this->size; i++) {
    vector<int> row;
    for (int j = 0; j < this->size; j++) {
      row.push_back(this->grid[j][i]);
    }
    if (this->validateRow(row)) {
      return true;
    }
  }
  return false;
}


bool Board::validateDiag() {
  vector<int> diag1, diag2;
  for (int i = 0; i < this->size; i++) {
    diag1.push_back(this->grid[i][i]);
    diag2.push_back(this->grid[(this->size - 1) - i][i]);
  }
  return (this->validateRow(diag1) || this->validateRow(diag2));
}


