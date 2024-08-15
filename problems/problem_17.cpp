// https://neetcode.io/problems/permutation-string

#include <string>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1_chars(26, 0);
        for (char c : s1)
            s1_chars[c - 'a']++;

        vector<int> curr_chars(26, 0);
        int i = 0, j = 0;

        while (j < s2.size())
        {
            if (j - i == s1.length())
                break;

            if (s1_chars[s2[j] - 'a'] > curr_chars[s2[j] - 'a'])
                curr_chars[s2[j++] - 'a']++;
            else if (s1_chars[s2[j] - 'a'] > 0)
                curr_chars[s2[i++] - 'a']--;
            else
            {
                std::fill(curr_chars.begin(), curr_chars.end(), 0);
                j++;
                i = j;
            }
        }

        return (j - i == s1.length());
    }
};
