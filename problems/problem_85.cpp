// https://neetcode.io/problems/pacific-atlantic-water-flow

#include <queue>
#include <unordered_set>
#include <vector>

class Solution
{
    int ROWS, COLS;
    const int offsets[5] = {-1, 0, 1, 0, -1};

    void dfs(int r, int c, std::unordered_set<int> &set, int prev_height,
             const std::vector<std::vector<int>> &heights)
    {
        int coord = r * COLS + c;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || set.count(coord) ||
            heights[r][c] < prev_height)
            return;

        set.insert(coord);
        dfs(r - 1, c, set, heights[r][c], heights);
        dfs(r + 1, c, set, heights[r][c], heights);
        dfs(r, c - 1, set, heights[r][c], heights);
        dfs(r, c + 1, set, heights[r][c], heights);
    }

    void bfs(std::queue<std::pair<int, int>> &queue, std::vector<std::vector<uint8_t>> &visited,
             std::vector<std::vector<int>> &heights)
    {
        while (!queue.empty())
        {
            auto [r, c] = queue.front();
            visited[r][c] = 1;
            queue.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = r + offsets[i];
                int y = c + offsets[i + 1];

                if (x >= 0 && x < ROWS && y >= 0 && y < COLS && visited[x][y] == 0 &&
                    heights[r][c] <= heights[x][y])
                    queue.push({x, y});
            }
        }
    }

public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        ROWS = heights.size(), COLS = heights[0].size();
        std::queue<std::pair<int, int>> pq, aq;

        for (int r = 0; r < ROWS; r++)
        {
            pq.push({r, 0});
            aq.push({r, COLS - 1});
        }

        for (int c = 0; c < COLS; c++)
        {
            pq.push({0, c});
            aq.push({ROWS - 1, c});
        }

        std::vector<std::vector<uint8_t>> pac(ROWS, std::vector<uint8_t>(COLS, 0));
        std::vector<std::vector<uint8_t>> atl(ROWS, std::vector<uint8_t>(COLS, 0));

        bfs(pq, pac, heights);
        bfs(aq, atl, heights);

        std::vector<std::vector<int>> res;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (pac[r][c] && atl[r][c])
                    res.push_back({r, c});
            }
        }

        return res;
    }

    std::vector<std::vector<int>> pacificAtlanticDfs(std::vector<std::vector<int>> &heights)
    {
        ROWS = heights.size(), COLS = heights[0].size();
        std::unordered_set<int> pac, atl;

        for (int i = 0; i < ROWS; i++)
        {
            dfs(i, 0, pac, heights[i][0], heights);
            dfs(i, COLS - 1, atl, heights[i][COLS - 1], heights);
        }

        for (int i = 0; i < COLS; i++)
        {
            dfs(0, i, pac, heights[0][i], heights);
            dfs(ROWS - 1, i, atl, heights[ROWS - 1][i], heights);
        }

        std::vector<std::vector<int>> res;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int coord = r * COLS + c;
                if (pac.count(coord) && atl.count(coord))
                    res.push_back({r, c});
            }
        }

        return res;
    }
};
