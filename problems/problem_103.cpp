// https://neetcode.io/problems/longest-palindromic-substring

#include <string>
#include <vector>

class Solution
{
    std::pair<int, int> expand_at_center(std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
            left--, right++;

        return {left + 1, right - 1};
    }

public:
    std::string longestPalindrome(std::string s)
    {
        std::pair<int, int> res(0, 0);

        for (int i = 0; i < s.size(); i++)
        {
            auto [lo, ro] = expand_at_center(s, i, i);
            if (ro - lo > res.second - res.first)
                res = {lo, ro};

            auto [le, re] = expand_at_center(s, i, i + 1);
            if (re - le > res.second - res.first)
                res = {le, re};
        }

        return s.substr(res.first, res.second - res.first + 1);
    }

    // dynamic programming apprach
    std::string longestPalindromeDp(std::string s)
    {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        std::pair<int, int> ans(0, 0);

        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; diff++)
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = diff + i;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};
