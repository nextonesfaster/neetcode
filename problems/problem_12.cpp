// https://neetcode.io/problems/three-integer-sum

#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;

      if (i > 0 && nums[i - 1] == nums[i])
        continue;

      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int tsum = nums[i] + nums[l] + nums[r];

        if (tsum < 0)
          l++;
        else if (tsum > 0)
          r--;
        else {
          res.push_back({nums[i], nums[l], nums[r]});
          l++;
          while (nums[l] == nums[l - 1] && l < r)
            l++;
        }
      }
    }

    return res;
  }
};
