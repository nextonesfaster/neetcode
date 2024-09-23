// https://neetcode.io/problems/subsets-ii

#include <algorithm>
#include <vector>

class Solution {
  std::vector<std::vector<int>> res;

  void backtrack(const std::vector<int> &nums, std::vector<int> &curr, int curr_idx) {
    res.push_back(curr);
    for (int i = curr_idx; i < nums.size(); i++) {
      if (i > curr_idx && nums[i] == nums[i - 1])
        continue;
      curr.push_back(nums[i]);
      backtrack(nums, curr, i + 1);
      curr.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> curr;
    backtrack(nums, curr, 0);
    return res;
  }

  std::vector<std::vector<int>> subsetsWithDupIt(std::vector<int> &nums) {
    std::vector<std::vector<int>> res = {{}};
    std::sort(nums.begin(), nums.end());

    int prev = 0;
    for (int i = 0; i < nums.size(); i++) {
      std::vector<std::vector<int>> res_copy = res;
      // start at the prev end so we don't have duplicates
      int start = (i > 0 && nums[i - 1] == nums[i]) ? prev : 0;
      prev = res.size();
      for (int j = start; j < prev; j++) {
        res_copy[j].push_back(nums[i]);
        res.push_back(res_copy[j]);
      }
    }
    return res;
  }
};
