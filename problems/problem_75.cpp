// https://neetcode.io/problems/combinations-of-a-phone-number

#include <vector>
#include <string>

class Solution
{
    std::vector<std::string> res;
    const std::vector<std::vector<char>> map = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    void backtrack(const std::string &digits, std::string &curr, int curr_idx)
    {
        if (curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = curr_idx; i < digits.size(); i++)
        {
            std::vector<char> digit_chars = map[digits[i] - '1' - 1];
            for (auto &ch : digit_chars)
            {
                curr.push_back(ch);
                backtrack(digits, curr, i + 1);
                curr.pop_back();
            }
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};

        std::string curr = "";
        backtrack(digits, curr, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    sol.letterCombinations("34");
}
