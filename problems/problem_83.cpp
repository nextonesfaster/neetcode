// https://neetcode.io/problems/islands-and-treasure

#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  void islandsAndTreasure(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::queue<std::pair<int, int>> queue;
    for (int r = 0; r < m; r++)
      for (int c = 0; c < n; c++)
        if (grid[r][c] == 0)
          queue.push({r, c});

    const int offsets[5] = {-1, 0, 1, 0, -1};

    while (!queue.empty()) {
      auto [r, c] = queue.front();
      queue.pop();

      for (int i = 0; i < 4; i++) {
        int x = r + offsets[i];
        int y = c + offsets[i + 1];

        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != std::numeric_limits<int>::max())
          continue;

        grid[x][y] = grid[r][c] + 1;
        queue.push({x, y});
      }
    }
  }
};
