// https://neetcode.io/problems/rotting-fruit

#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int orangesRotting(std::vector<std::vector<int>> &grid) {
    int mins = 0;
    int fresh = 0;
    std::queue<std::pair<int, int>> queue;

    int m = grid.size(), n = grid[0].size();
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 1)
          fresh++;
        else if (grid[r][c] == 2)
          queue.push({r, c});
      }
    }

    const int offsets[5] = {-1, 0, 1, 0, -1};
    while (fresh > 0 && !queue.empty()) {
      int qs = queue.size();
      for (int i = 0; i < qs; i++) {
        auto [r, c] = queue.front();
        queue.pop();

        for (int j = 0; j < 4; j++) {
          int x = r + offsets[j];
          int y = c + offsets[j + 1];

          if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
            continue;
          grid[x][y] = 2;
          queue.push({x, y});
          fresh--;
        }
      }

      mins++;
    }

    return fresh == 0 ? mins : -1;
  }
};
