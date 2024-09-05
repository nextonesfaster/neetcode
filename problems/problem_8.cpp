// https://neetcode.io/problems/valid-sudoku

#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<int>> row_map;
        unordered_map<int, unordered_set<int>> col_map;
        unordered_map<int, unordered_set<int>> block_map;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                char cell = board[i][j];
                if (cell == '.')
                    continue;

                int block_index = (i / 3) * 3 + j / 3;
                if (row_map[i].count(cell) || col_map[j].count(cell) || block_map[block_index].count(cell))
                    return false;

                row_map[i].insert(cell);
                col_map[j].insert(cell);
                block_map[block_index].insert(cell);
            }
        }

        return true;
    }
};
