// https://neetcode.io/problems/search-2d-matrix

#include <vector>

class Solution {
public:
  // this approach performs a single binary search, treating the matrix as a sorted 1-d array
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int ROWS = matrix.size(),
        COLS = matrix[0].size(); // matrix is guaranteed to have at least one row

    int l = 0, r = (COLS * ROWS) - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (matrix[m / COLS][m % COLS] < target)
        l = m + 1;
      else if (matrix[m / COLS][m % COLS] > target)
        r = m - 1;
      else
        return true;
    }

    return false;
  }

  // this approach performs two separate binary searches
  bool searchMatrixAlt(std::vector<std::vector<int>> &matrix, int target) {
    int ROWS = matrix.size(),
        COLS = matrix[0].size(); // matrix is guaranteed to have at least one row

    int top = 0, bottom = ROWS - 1;
    int row;
    while (top <= bottom) {
      row = top + (bottom - top) / 2;
      if (matrix[row][COLS - 1] < target)
        top = row + 1;
      else if (matrix[row][0] > target)
        bottom = row - 1;
      else
        break;
    }

    if (top > bottom) // this also ensures row is initialized if we go further
      return false;

    int l = 0, r = COLS - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (matrix[row][m] < target)
        l = m + 1;
      else if (matrix[row][m] > target)
        r = m - 1;
      else
        return true;
    }

    return false;
  }
};
