// https://neetcode.io/problems/subsets

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> res = {{}};

    for (auto &num : nums) {
      std::vector<std::vector<int>> res_copy = res;
      for (auto &s : res_copy) {
        s.push_back(num);
        res.push_back(s);
      }
    }

    return res;
  }
};
