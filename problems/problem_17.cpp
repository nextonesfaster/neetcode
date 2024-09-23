// https://neetcode.io/problems/longest-repeating-substring-with-replacement

#include <string>

using namespace std;

class Solution {
public:
  // this runs in O(n) and takes O(26) space
  int characterReplacement(string s, int k) {
    if (s.empty())
      return 0;

    int max_len = 0;
    int l = 0;
    vector<int> curr_counts(26, 0);
    int maxf = 0;

    for (int r = 0; r < s.size(); r++) {
      curr_counts[s[r] - 'A']++;
      maxf = max(maxf, curr_counts[s[r] - 'A']);

      if (r - l + 1 - maxf > k)
        curr_counts[s[l++]]--;
      max_len = max(max_len, r - l + 1);
    }

    return max_len;
  }

  // this runs in O(26n) and takes O(1) space
  int characterReplacementAlt(string s, int k) {
    if (s.empty())
      return 0;

    int max_len = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
      int i = 0, j = 0, replaced = 0;
      while (j < s.size()) {
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
