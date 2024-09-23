// https://neetcode.io/problems/n-queens

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  std::vector<std::vector<std::string>> res;
  std::vector<int> constraints;
  int n;

  bool is_under_attack(int r, int c) {
    return constraints[c] || constraints[n + r + c] || constraints[4 * n - 2 + r - c];
  }

  void place_queen(int r, int c) {
    constraints[c] = constraints[n + r + c] = constraints[4 * n - 2 + r - c] = 1;
  }

  void remove_queen(int r, int c) {
    constraints[c] = constraints[n + r + c] = constraints[4 * n - 2 + r - c] = 0;
  }

  void backtrack(int r, std::vector<std::string> &board) {
    if (r == n) {
      res.push_back(board);
      return;
    }

    for (int c = 0; c < n; c++) {
      if (is_under_attack(r, c))
        continue;

      place_queen(r, c);
      board[r][c] = 'Q';

      backtrack(r + 1, board);

      remove_queen(r, c);
      board[r][c] = '.';
    }
  }

public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    this->n = n;
    constraints = std::vector<int>(5 * n - 2, 0);
    std::vector<std::string> board(n, std::string(n, '.'));

    backtrack(0, board);
    return res;
  }
};
