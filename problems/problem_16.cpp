// https://neetcode.io/problems/longest-substring-without-duplicates

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int max_len = 0, i = 0, j = 0;

    while (j < s.size()) {
      while (set.count(s[j]))
        set.erase(s[i++]);

      set.insert(s[j++]);
      max_len = max(max_len, j - i);
    }

    return max_len;
  }
};
