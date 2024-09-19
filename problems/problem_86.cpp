// https://neetcode.io/problems/surrounded-regions

#include <vector>
#include <queue>

class Solution
{
    int ROWS, COLS;
    const int offsets[5] = {-1, 0, 1, 0, -1};

    void bfs(std::queue<std::pair<int, int>> &queue, std::vector<std::vector<char>> &board)
    {
        while (!queue.empty())
        {
            auto [r, c] = queue.front();
            board[r][c] = 'T';
            queue.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = r + offsets[i];
                int y = c + offsets[i + 1];

                if (x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == 'O')
                    queue.push({x, y});
            }
        }
    }

public:
    void solve(std::vector<std::vector<char>> &board)
    {
        // identify all `O`s reachable from the edges
        std::queue<std::pair<int, int>> queue;
        ROWS = board.size(), COLS = board[0].size();

        for (int i = 0; i < ROWS; i++)
        {
            if (board[i][0] == 'O')
                queue.push({i, 0});
            if (board[i][COLS - 1] == 'O')
                queue.push({i, COLS - 1});
        }

        for (int i = 0; i < COLS; i++)
        {
            if (board[0][i] == 'O')
                queue.push({0, i});
            if (board[ROWS - 1][i] == 'O')
                queue.push({ROWS - 1, i});
        }

        bfs(queue, board);

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (board[r][c] == 'T')
                    board[r][c] = 'O';
                else if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }
    }
};
