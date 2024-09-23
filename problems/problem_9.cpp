// https://neetcode.io/problems/longest-consecutive-sequence

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> unique_nums(nums.begin(), nums.end());
    int max_seq_len = 0;

    for (auto num : unique_nums) {
      if (!unique_nums.count(num - 1)) {
        int curr = num, seq_len = 1;
        while (unique_nums.count(++curr))
          seq_len++;
        if (seq_len > max_seq_len)
          max_seq_len = seq_len;
      }
    }

    return max_seq_len;
  }
};
