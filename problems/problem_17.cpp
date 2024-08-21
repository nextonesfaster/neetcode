// https://neetcode.io/problems/permutation-string

#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // runtime: O(26 + n)
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int s1_chars[26] = {0};
        int s2_chars[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            s1_chars[s1[i] - 'a']++;
            s2_chars[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (s1_chars[i] == s2_chars[i])
                matches++;

        int i = 0;
        for (int j = s1.size(); j < s2.size(); j++)
        {
            if (matches == 26)
                return true;

            int index = s2[j] - 'a';
            s2_chars[index]++;
            if (s2_chars[index] == s1_chars[index])
                matches++;
            else if (s2_chars[index] == s1_chars[index] + 1)
                matches--;

            index = s2[i] - 'a';
            if (s2_chars[index] == s1_chars[index])
                matches--;
            else if (s2_chars[index] == s1_chars[index] + 1)
                matches++;
            s2_chars[index]--;
            i++;
        }

        return matches == 26;
    }

    // runtime: O(26n)
    bool checkInclusionAlt(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int s1_chars[26] = {0};
        for (char c : s1)
            s1_chars[c - 'a']++;

        int curr_chars[26] = {0};
        int i = 0, j = 0;

        while (j < s2.size())
        {
            if (j - i == s1.length())
                break;

            if (s1_chars[s2[j] - 'a'] > curr_chars[s2[j] - 'a'])
                curr_chars[s2[j++] - 'a']++;
            else if (s1_chars[s2[j] - 'a'])
                curr_chars[s2[i++] - 'a']--;
            else
            {
                std::fill(curr_chars, curr_chars + 26, 0);
                j++;
                i = j;
            }
        }

        return (j - i == s1.length());
    }
};
