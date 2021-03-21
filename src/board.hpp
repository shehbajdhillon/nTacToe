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
    bool validateBoard();
    vector<vector<int>> getGrid();
    int getSize();
    Board(int size);
};

#endif
