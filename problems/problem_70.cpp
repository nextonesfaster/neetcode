// https://neetcode.io/problems/permutations

#include <vector>

class Solution {
  std::vector<std::vector<int>> res;

  void backtrack(const std::vector<int> &nums, std::vector<int> &curr, std::vector<bool> &used) {
    if (curr.size() == nums.size()) {
      res.push_back(curr); // creates a copy
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i])
        continue;

      curr.push_back(nums[i]);
      used[i] = true;
      backtrack(nums, curr, used);
      used[i] = false;
      curr.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<int> curr = {};
    curr.reserve(nums.size());
    std::vector<bool> used(nums.size(), false);
    backtrack(nums, curr, used);
    return res;
  }
};
