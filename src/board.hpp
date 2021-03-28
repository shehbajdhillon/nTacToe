#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

using namespace std;

class Board {
  private:
    vector<vector<int>> grid;
    int size;
    bool validateRow(vector<int> row);
    bool validateRows();
    bool validateCols();
    bool validateDiag();
  public:
    int translate(int num);
    int placeMark(int coord, char mark);
    bool isOccupied(int coord);
    bool validateBoard();
    vector<vector<int>> getGrid();
    void printGrid();
    int getSize();
    Board(int size);
};

#endif
