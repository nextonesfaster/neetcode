// https://neetcode.io/problems/longest-repeating-substring-with-replacement

#include <string>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        if (s.empty())
            return 0;

        int max_len = 0;
        for (char c = 'A'; c <= 'Z'; c++)
        {
            int i = 0, j = 0, replaced = 0;
            while (j < s.size())
            {
                if (s[j] == c)
                    j++;
                else if (replaced < k)
                    j++, replaced++;
                else if (s[i] == c)
                    i++;
                else
                    i++, replaced--;
                max_len = max(max_len, j - i);
            }
        }

        return max_len;
    }
};
