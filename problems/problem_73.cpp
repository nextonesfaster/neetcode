// https://neetcode.io/problems/search-for-word

#include <vector>
#include <string>

class Solution
{
    int m, n;

    bool dfs(std::vector<std::vector<char>> &board, const std::string &word, int curr_idx, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[curr_idx])
            return false;
        if (curr_idx == word.size() - 1)
            return true;

        board[i][j] = '#';
        if (dfs(board, word, curr_idx + 1, i - 1, j) || dfs(board, word, curr_idx + 1, i + 1, j) || dfs(board, word, curr_idx + 1, i, j - 1) || dfs(board, word, curr_idx + 1, i, j + 1))
            return true;

        board[i][j] = word[curr_idx];
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        m = board.size();
        n = board[0].size();
        if (word.size() > m * n)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (dfs(board, word, 0, i, j))
                    return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    std::vector<std::vector<char>> board = {{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}};
    sol.exist(board, "aaaaaaaaaaaaa"); // should be false but for some reason, Neetcode expects it to be true
}
