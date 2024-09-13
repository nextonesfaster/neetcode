// https://neetcode.io/problems/palindrome-partitioning

#include <vector>
#include <string>

class Solution
{
    std::vector<std::vector<std::string>> res;

    bool is_palindrome(const std::string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void backtrack(const std::string &s, std::vector<std::string> &curr, int start)
    {
        if (start >= s.length())
        {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < s.length(); i++)
        {
            if (!is_palindrome(s, start, i))
                continue;
            curr.push_back(s.substr(start, i - start + 1));
            backtrack(s, curr, i + 1);
            curr.pop_back();
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::string> curr;
        backtrack(s, curr, 0);
        return res;
    }
};
