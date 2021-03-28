#include "board.hpp"
#include <vector>
#include <iostream>

#define EMPTY_VALUE 32

using namespace std;

Board::Board(int size) {
  this->size = size;
  for (int i = 0; i < size; i++) {
    this->grid.push_back(vector<int>(size, EMPTY_VALUE));
  }
}


vector<vector<int>> Board::getGrid() {
  return this->grid;
}


int Board::getSize() {
  return this->size;
}


bool Board::validateBoard() {
  return
    (this->validateCols() || this->validateDiag() ||
     this->validateRows());
}


bool Board::validateRow(vector<int> row) {
  for(int i = 0; i < this->size - 1; i++) {
    if (row[i] == EMPTY_VALUE || row[i] != row[i + 1]) {
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


void Board::printGrid() {
  for (vector<int> row: this->grid) {
    cout << " ";
    for (int i: row) {
      cout << (char)i << " | ";
    }
    cout << "\n";
    for (int i = 0; i < this->size; i++) {
      cout << "----";
    }
    cout << "\n";
  }
}


bool Board::isOccupied(int coord) {
  int row = coord / this->size;
  int col = coord % this->size;

  return this->grid[row][col] != EMPTY_VALUE;
}


int Board::placeMark(int coord, char mark) {
  if (!this->isOccupied(coord)) {

    int row = coord / this->size;
    int col = coord % this->size;
    this->grid[row][col] = mark;
    return 1;
  }
  return 0;
}
