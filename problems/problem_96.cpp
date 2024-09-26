// https://neetcode.io/problems/swim-in-rising-water

#include <queue>
#include <vector>

typedef std::array<int, 3> arr3;

class Solution
{
    const int DIRS[5] = {-1, 0, 1, 0, -1};

public:
    int swimInWater(std::vector<std::vector<int>> &grid)
    {
        const int N = grid.size();

        std::priority_queue<arr3, std::vector<arr3>, std::greater<>> pq;
        std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (!pq.empty())
        {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (r == N - 1 && c == N - 1)
                // reached the top-right corner
                return t;

            for (int i = 0; i < 4; i++)
            {
                int x = r + DIRS[i];
                int y = c + DIRS[i + 1];

                if (x >= 0 && y >= 0 && x < N && y < N && !visited[x][y])
                {
                    visited[x][y] = true;
                    pq.push({std::max(t, grid[x][y]), x, y});
                }
            }
        }

        return -1;
    }
};
