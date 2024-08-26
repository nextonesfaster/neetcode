// https://neetcode.io/problems/minimum-window-with-characters

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        if (t.length() > s.length())
            return "";

        const size_t array_size = 'z' - 'A' + 1;
        size_t t_chars[array_size] = {0};
        for (char c : t)
            t_chars[c - 'A']++;

        size_t window_chars[array_size] = {0};
        size_t l = 0, conditions_true = 0;
        size_t required_true = std::count_if(t_chars, t_chars + array_size, [](size_t c)
                                             { return c; });
        size_t lmin = -1, rmin = std::numeric_limits<size_t>::max();

        for (size_t r = 0; r < s.length(); r++)
        {
            size_t index = s[r] - 'A';
            if (t_chars[index])
            {
                window_chars[index]++;
                if (window_chars[index] == t_chars[index])
                    conditions_true++;
            }

            while (conditions_true == required_true)
            {
                if (lmin == -1 || r - l < rmin - lmin)
                    lmin = l, rmin = r;

                index = s[l++] - 'A';
                if (t_chars[index])
                {
                    if (t_chars[index] == window_chars[index])
                        conditions_true--;
                    window_chars[index]--;
                }
            }
        }

        if (lmin != -1)
            return s.substr(lmin, rmin - lmin + 1);
        else
            return "";
    }
};

int main()
{
    Solution solution;
    std::cout << solution.minWindow("OUZODYXAZV", "XYZ") << std::endl;
    std::cout << solution.minWindow("xyz", "xyz") << std::endl;
    std::cout << solution.minWindow("ADOBECODEBANC", "ABC") << std::endl;
}
